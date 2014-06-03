#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
using namespace std;

int main()
{
    int i;
    int arrey[200];
//заполняем массив случю числами
    srand(time (NULL));
    for(i=0; i<200; i++)
            arrey[i]=rand()%101-50;
cout<<"Исходный массив:\n";
  for (i=0;i<100;i++)
        {
           printf(" %3d ", arrey[i]);
         if  ((i+1)%10==0) printf("\n");
          }

int n=0;
    for(i=0; i<199; i++)
         if(arrey[i]==arrey[i+1])
         {
            n++;
            }
printf("Количество пар с одинаковыми соседними значениями: %d",n);
    return 0;
}
