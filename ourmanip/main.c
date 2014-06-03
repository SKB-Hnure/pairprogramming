/*
 */

#include <avr/io.h>

int main(void)
{
DDRC=0b11110000; //1 - вых
PORTC=0b11110000;

DDRA=0b11111111; //1 - вых
PORTA=0b00000000;

DDRD=0xFF;
PORTD=0b00000000;

while (1)
{
PORTD=0b00010000;
if (PORTC0==1)
PORTA=(1<<PORTA6);
if (PORTC1==1)
PORTA=(0<<PORTA6);
if (PORTC2==1)
PORTA=(0<<PORTA3);
if (PORTC3==1)
PORTA=(1<<PORTA3);
/*if (PC0==1)
 PORTD=0b11111111; //7
 if (PC1==1)
 PORTD=0b11111111; //
 if (PC2==1)
 PORTD=0b11111111; //PD7
*/
    // Insert code
}
    return 0;
}
