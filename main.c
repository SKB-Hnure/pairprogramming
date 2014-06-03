#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[9][9];
    int caunt=1;
    int i=0, j=0;
    int k, l, g;
    int n=8;
    int m=0;
    int buf=0;


    //    заполняем массив случю числами
    srand(time (NULL));
    for ( i=0;i<9;i++)
        for (j=0;j<9;j++)
            arr[i][j]=rand()%201-100;


    //вывод массива
    for(n=0; n<9; n++)
    {
        for(m=0; m<9; m++)
        printf("%3d",arr[n][m]);
        printf("\n");
    }


//printf("m= %d \n",m);

    k=0;
    l=0;
    j=8;
    caunt=1;
   // printf("m=  %d k= %d l= %d j= %d",m, k, l,j);

    for(m=0; m<4; m++)//увелич. № столбца
    {
        printf("!!!!!!!!!!!!!!!!!!!!1\n");

        for(i=0; i<caunt; i++)
        {
           //  printf("m= %d",m);
                buf=arr[m][k];
                arr[m][k]=arr[m][j];
                arr[m][j]=buf;
                k++;
                j--;
        }
            k=0;
            j=8;
           if(caunt<4)
           caunt++;
           else
           caunt=0;
        }



    //вывод массива
    caunt=0;
    for(n=0; n<9; n++)
    {
        for(m=0; m<9; m++)
        printf("%3d",arr[n][m]);
        printf("\n");
    }

    return 0;
}
