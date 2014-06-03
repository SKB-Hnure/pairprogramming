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
    int data=1;
for ( i=0;i<9;i++)
 for (j=0;j<9;j++)
  arr[i][j]=0;

  caunt=1;
    for(m=0; m<9; m++)//увелич. № столбца
    {
        l=n;
        k=m;

        for(i=0; i<caunt; i++)
        {
             if (arr[l][k]==0)
             {
            arr[l][k]=data;
            l=l-1;
            k=k-1;
            data++;
             }
        }
        caunt++;
    }
    caunt=caunt-2;
    m=8;
    n=7;


    for(n=7; n>=0; n--)//уменьшение. № строки
    {
        l=n;
        k=m;

        for(i=0; i<caunt; i++)
        {
            if (arr[l][k]==0)
            {
            arr[l][k]=data;
            l--;
            k--;
            data++;
            }
           // printf("%d, %d \n", l, k);
        }
        caunt--;
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
