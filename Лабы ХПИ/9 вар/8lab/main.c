#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int sum=0;
    int bufer=0;
    int bufer_2=0;
    int caunt=0;
    int arrey[200];
    int posl=0;
//заполняем массив случайными числами
    srand(time (NULL));
    for(i=0; i<200; i++)
        {
            arrey[i]=rand()%101;
        }
    //находим последовательность с макс_10 числами
    int k;
    for(k=0; k<90; k++)
    {
        int i;
        for(i=0; i<10; i++)
        {
            bufer=bufer+arrey[k+i];//находим суму посл. 10 эл,
        }
        if(bufer>sum)
        {
            caunt=k+9;
            sum=bufer;
            bufer=0;
        }
        else
            bufer=0;
    }

    printf("sum = %d \n",sum);
    int f;
   for(f=10; f>0; f--)
    {
      caunt--;
    printf("%d \n",arrey[caunt]);
    }
    return 0;
}
