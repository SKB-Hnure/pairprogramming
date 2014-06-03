#define F_CPU 4000000UL

#include <avr/io.h>
#include <avr/iom16.h>
#include <util/delay.h>

volatile unsigned char actionTable[8][2]={
			{0x11,0x06},//задвинуть левую
			{0x12,0x02},//поворот Лв влево
			{0x14,0x01},//захват Лв разжат
			{0x18,0x00},//колонна влево

			{0x21,0x16},//выдвинуть левую
			{0x22,0x12},//поворот Лв вправо
			{0x24,0x11},//захват Лв зажат
			{0x28,0x10},//колонна вправо

		/*	{0x41,0x07},//задвинуть правую
			{0x42,0x05},//поворот Пр влево
			{0x44,0x04},//захват Пр разжат
			{0x48,0x03},//колонна вниз

			{0x81,0x17},//выдвинуть правую
			{0x82,0x15},//поворот Пр вправо
			{0x84,0x14},//захват Пр зажат
			{0x88,0x13} //колонна вверх */
								};


volatile unsigned char funcTable[3][2]={
 			{0x02,0x0A},// Выполнить execute
			{0x04,0x0B},// Запись listen
			{0x08,0x0C} // Ручной режим manual
							};

volatile unsigned char dynamicTable[200]={};
volatile unsigned char keyCount;
volatile unsigned char mas;
volatile unsigned char bufPB;
unsigned char keyState;

volatile unsigned char keyCode;

volatile unsigned char keyAction;

unsigned char funcKey,keyDown, keyNew;

unsigned char AnyKey(void);

unsigned char SameKey(void);

void ScanKey(void);

void ClearKey(void);

unsigned char FindAction();

void ExecKeyAction(void);


void USART_Init(void)
{
  UBRRH = 0;
  UBRRL = 25; //UBRR = (Fck/(16*BAUD)) – 1 скорость обмена 9600 бод
  //разр. прерыв при приеме, разр приема, разр передачи.
  UCSRB = (1<<RXEN)|(1<<TXEN);
  //обращаемся к регистру UCSRS, размер слова – 8 бит
  UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
}

void USART_Transmit( unsigned char data )
{
//Wait for empty transmit buffer
while ( !( UCSRA & (1<<UDRE)) );
//Put data into buffer, sends the data
UDR = data;
}



void ScanKeyboard(void)
{
    switch(keyState)
    {
        case 0: if(AnyKey()){ScanKey(); keyState=1;}break;
        case 1: if(SameKey()){_delay_ms(200); FindAction();keyState=2;}else keyState=0;break;
        case 2: if(SameKey());else keyState=3;break;
        case 3: if(SameKey()){keyState=2;}else{ExecKeyAction();ClearKey();keyState=0;}break;
        default:break;
    }
}

unsigned char AnyKey(void)
{
    PORTC = (0x1f<<2);
    return (PINA & 0x0F);
}

void ScanKey(void)
{
    unsigned char activeRow;
    for(activeRow = 0;activeRow<5;activeRow++)
    {
         PORTC=(1<<(2+activeRow));
         keyCode =(PINA & 0x0F);
        if(keyCode)
        {
            if(activeRow<4)
                keyCode |= (0x01<<(4+activeRow));
            else funcKey=1;
            break;
        }
    }
}

unsigned char SameKey(void)
{
    if(funcKey)
        PORTC = (1<<PC6);
    else
        PORTC = (((keyCode & 0xF0)>>2) & 0x7C);
        return (PINA & (keyCode & 0x0F));
}

void ClearKey(void)
{
    keyDown=0;
    funcKey=0;
	keyAction = 0;
}

unsigned char FindAction()
{
    unsigned char i;
    if(funcKey==1)
    {
        for(i=0;i<4;i++)
        {
            if(funcTable[i][0]==keyCode)
            {
                keyAction=funcTable[i][1];
                keyDown=1;
                keyNew=1;
                return 1;
            }
        }
        return 0;
    }
    for(i=0;i<8;i++)    //16
    {
        if(actionTable[i][0]==keyCode)
        {
            keyAction=actionTable[i][1];
            keyDown=1;
            keyNew=1;
            return 1;
        }
    }
    return 0;
}

void ExecKeyAction(void)
{
	keyCount++;
    bufPB=keyAction;
	USART_Transmit(bufPB);
}

void init(void) // init:   Reset and recalibrate
{
	PORTA=0x00;
	PORTB=0x00;
	PORTC=(0x1f<<2);
	PORTD=0x00;
	keyState=keyCode=keyAction=keyCount=bufPB=0;
	funcKey=keyDown=keyNew=0;
	mas=0;
}

void doWork(void)
{
    if(bufPB & 0xF0)
        PORTB |= 1<<(bufPB & 0x0F);
    else
        PORTB &= 0xFF-(1<<(bufPB & 0x0F));
}

int main(void)
{

DDRA=0x00; //светодиоды для парных
PORTA=0x00;

DDRB=0xFF; //не исп
PORTB=0x00;

DDRC=0xFF;    //клав
PORTC=(0x1f<<2);

DDRD=0b11111100; //PD7-PD2 as output, светодиоды для непарных и юарт
PORTD=0b00000000;

keyState=keyCode=keyAction=keyCount=bufPB=0;
funcKey=keyDown=keyNew=0;

USART_Init();

manual:											// РУЧНОЙ РЕЖ_____________________
init();
PORTD=0b00100000;
while (1)
{
	ScanKeyboard();
	switch(keyAction)
    {
		case 0x0A: goto execute; break;		// к ВЫП
        case 0x0B: _delay_ms(500); goto listen; break;		// к ЗАП
        case 0x0C: PORTD=0b00100000; break;
        default:break;
    }
	doWork();
}

listen: 										// РЕЖ ЗАПИСИ___________________
init();
PORTD=0b01000000;
while (1)
{
	ScanKeyboard();
	dynamicTable[keyCount]=bufPB;
	switch(keyAction)
    {
		case 0x0A: dynamicTable[keyCount+1]=0xAA; goto execute; break;		// сохр и ВЫП
        case 0x0B: dynamicTable[keyCount+1]=0xAA; _delay_ms(500); goto manual; break;			// сохр и РУЧНОЙ
        case 0x0C: dynamicTable[keyCount]=bufPB=dynamicTable[keyCount-1]; break;				// ОТМЕНА последнего действия
        default: break;
    }
	doWork();

}

execute:										// РЕЖ ВЫП___________________
init();
PORTD=0b10000000;
while (1)
{
	ScanKeyboard();
	if (keyAction==0x0C) goto manual;							// удерж ОТМЕНА для выхода
	if (dynamicTable[mas]==0xAA) mas=1;
	bufPB=dynamicTable[mas];
	USART_Transmit(bufPB);
	USART_Transmit(mas);
	doWork();
	_delay_ms(500);
	mas++;
}
}

/*void USART_Init(void)
{
  UBRRH = 0;
  UBRRL = 25; //UBRR = (Fck/(16*BAUD)) – 1 скорость обмена 9600 бод
  //разр. прерыв при приеме, разр приема, разр передачи.
  UCSRB = (1<<RXEN)|(1<<TXEN);
  //обращаемся к регистру UCSRS, размер слова – 8 бит
  UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
}

void USART_Transmit( unsigned char data )
{
//Wait for empty transmit buffer
while ( !( UCSRA & (1<<UDRE)) );
//Put data into buffer, sends the data
UDR = data;
}

unsigned char USART_Receive( void )
{
//Wait for data to be received
while ( !(UCSRA & (1<<RXC)) );
//Get and return received data from buffer
return UDR;
}

void ScanKeyboard(void) // Finite-state automat
{
	switch(keyState)
    {
        case 0: if(AnyKey()){ScanKey(); keyState=1;} break;//else keyState=0;break;  //else keyState=0;
        case 1: if(SameKey()){FindAction();keyState=2;}else keyState=0;break;
        case 2: if(SameKey());else keyState=3;break; 						//____________________________задержка keyshake тут
        case 3: if(SameKey()){keyState=2;}else{ExecKeyAction();ClearKey();keyState=0;}break;
        default:break;
    }

}


unsigned char AnyKey(void) //если любая кнопка нажата - true
{
    PORTC = (0x1f<<2);  // порт С = 0111 1100
    return (PINA & 0x0F); // вернем значения порта А младшей етрады
}


void ScanKey(void)
{
    unsigned char activeRow;
    for(activeRow = 0;activeRow<5;activeRow++)
    {
    	PORTC=(1<<(2+activeRow)); //сканим по очереди ряды
   		keyCode =(PINA & 0x0F); // запишем младший разряд (0000 1111)
   		if(keyCode)
    	{
        	if(activeRow<4) keyCode |= (0x01<<(4+activeRow)); // допишем код клавиши..
            else funcKey=1;// значит нажата функциональная клавиша
            break;
        }
    }
}

unsigned char SameKey(void)
{
	if(funcKey)
		PORTC = (1<<PC6);
	else
		PORTC = (((keyCode & 0xF0)>>2) & 0x7C);
        return (PINA & (keyCode & 0x0F));
}

unsigned char FindAction()
{
    unsigned char i;
    if(funcKey==1)
    {
        for(i=0;i<4;i++)
        {
			if(funcTable[i][0]==keyCode)
            {
                keyAction=funcTable[i][1];
				keyDown=1;
                keyNew=1;
                return 1;
            }
        }
        return 0;
    }
	for(i=0;i<16;i++)
    {
       	if(actionTable[i][0]==keyCode)
       	{
       	    keyAction=actionTable[i][1];
			keyDown=1;
          	keyNew=1;
     	    return 1;
      	}
    }
_delay_ms(200); //======================================================================== delay
return 0;
}

void ExecKeyAction(void)
{
	keyCount++;
	USART_Transmit(keyCount);///////=======
	USART_Transmit('_');
	USART_Transmit(keyAction);
 PORTD = keyAction;
}

void ClearKey(void)
{
    keyDown=0;
    funcKey=0;
	keyNew=0;
	keyAction = 0; 	//=====================================c============ keyAction = 0; ====================================================================================================================================
}

unsigned char Sensor() //вернет true если концевик каждой пары замкнут
{

if (bit_is_set(PINA,7) && bit_is_set(PINA,6) &&	bit_is_set(PINA,5) && bit_is_set(PINA,4)){
	_delay_us(1500);																						//========задержка на срабатывание датчика 1-2 сек=====
	if (bit_is_set(PINA,7) && bit_is_set(PINA,6) &&	bit_is_set(PINA,5) && bit_is_set(PINA,4)){
		return 1;
	}
	else {
		return 0;
	}
}
    else
	{
		return 0;
	}
}

void doWork(void)
{
	if (Sensor()){
		if(keyAction & 0xF0)  // если в старшей тетраде есть 1
    	PORTB |= 1<<(keyAction & 0x0F); // смещение лог. 1 соответственно коду
		else
		PORTB &= 0xFF-(1<<(keyAction & 0x0F)); // смещение соответственно коду и установка лог. 0
	}
	else {
		doWork();
	}
}

void stepBack(void)
{
	keyAction=dynamicTable[keyCount-1];
	USART_Transmit(keyAction);
	if(keyAction & 0xF0)
   	keyAction ^= (1<<4);
	else
	keyAction |= (1<<4);
	USART_Transmit(keyAction);
	keyCount--;
}

void init(void) // init:   Reset and recalibrate
{
	PORTA=0x00;
	PORTB=0x00;
	PORTC=(0x1f<<2);
	PORTD=0x00;
	keyState=keyCode=0;
	keyAction=0;
	funcKey=0;
	keyDown=keyNew=0;
	keyCount=mas=ctemp=0;
	doWork();
	_delay_ms(100);
}

int main(void)
{

DDRA=0x00; //порт А как ВХод
PORTA=0x00;

DDRB=0xFF; // порт В как ВЫХод
PORTB=0x00;

DDRC=0xFF; // порт С как ВЫХод
PORTC=(0x1f<<2);

DDRD=0b11111100; //PD7-PD2 as output
PORTD=0b00000000;

//USART_Init();

keyState=keyCode=keyAction=0;
funcKey=keyDown=keyNew=keyCount=mas=0;

manual:											// РУЧНОЙ РЕЖ_____________________
init();
PORTD=0b00100000;
while (1)
{
	ScanKeyboard();
switch(keyAction)
    {
		case 0x0A: goto execute; break;		// к ВЫП
    case 0x0B: _delay_ms(1000); goto listen; break;		// к ЗАП
    case 0x0C: goto manual; break;
    default:break;
    }
	_delay_ms(100);
	if (keyDown) USART_Transmit(keyAction);
	if (keyNew) doWork();
}

listen: 										// РЕЖ ЗАПИСИ___________________
init();
PORTD=0b01000000;
while (1)
{
	ScanKeyboard();
	switch(keyAction)
    {
		case 0x0A: dynamicTable[keyCount]=0xAA; goto execute; break;		// сохр и ВЫП
        case 0x0B: dynamicTable[keyCount]=0xAA; _delay_ms(1000); goto manual; break;			// сохр и РУЧНОЙ
        case 0x0C: stepBack(); break;									// ОТМЕНА последнего действия
        default: dynamicTable[keyCount]=keyAction; break;
    }

	USART_Transmit(keyCount);
	USART_Transmit(keyAction);
	_delay_ms(100);
	doWork();
}

execute:										// РЕЖ ВЫП___________________
init();
PORTD=0b10000000;
while (1)
{
	ScanKeyboard();
	_delay_ms(500); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	if ((keyDown) && (keyAction==0x0C)) goto manual;							// удерж ОТМЕНА для выхода
	if (dynamicTable[mas]==0xAA) mas=0;
	keyAction=dynamicTable[mas];
	USART_Transmit(keyAction);
	USART_Transmit(mas);
	doWork();
	mas++;
}


usart:
init();

USART_Transmit('o');
USART_Transmit('k');

while (1)
{
sym=USART_Receive();
switch(sym)
    {
		case 0x0A: break;
        case 0x0B: init(); break;
        case 0x0C: goto manual; break;
        default: keyAction=sym; break;
    }
doWork();
_delay_ms(200);
USART_Transmit('W');
}
}

*/



