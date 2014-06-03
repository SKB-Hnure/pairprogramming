#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int arr[9][9];
    int i=0, j=0;
    int n=8;
    int buf=0;


    //    заполняем массив случю числами
    srand(time (NULL));
    for ( i=0;i<9;i++)
        for (j=0;j<9;j++)
            arr[i][j]=rand()%201-100;


    //вывод массива
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        printf(" %3d ",arr[i][j]);
        printf("\n");
    }


   for (int i=0;i<9;i++)
   {
    while (i>j)
    {
    buf=arr[i][j];
    arr[i][j]=arr[j][i];
    arr[j][i]=buf;
    j++;
    }
   j=0;
   }

printf("\n");
    //вывод массив
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        printf(" %3d ",arr[i][j]);
        printf("\n");
    }

    return 0;
}
