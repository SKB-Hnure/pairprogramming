#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
using namespace std;

int main()
{
    int i;
    int max_sum=0;
    int sum=0;
    int arrey[100];
//заполняем массив случю числами
    srand(time (NULL));
    for(i=0; i<100; i++)
            arrey[i]=rand()%201-100;
            int k;
cout<<"Исходный массив:\n";
  for (i=0;i<100;i++)
        {
           printf(" %3d ", arrey[i]);
         if  ((i+1)%10==0) printf("\n");
          }
int n=0; double aref;
    for(i=0; i<100; i++)
         if(arrey[i]>0)
         {
            sum=sum+arrey[i];
            n++;
            }
           aref=sum/n;
 for(i=0; i<100; i++)
         if(arrey[i]<0)
            arrey[i]=aref;
    printf("\nВыходной массив:\n");
       for(i=0; i<100; i++)
       {
           printf(" %3d ", arrey[i]);
        if  ((i+1)%10==0) printf("\n");
          }
    return 0;
}
