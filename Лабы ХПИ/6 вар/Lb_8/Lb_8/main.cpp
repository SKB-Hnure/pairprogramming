#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>

int main()
{
    int i;
    int max_sum=0;
    int sum=0;
    int arrey[100];
//заполняем массив случю числами
    srand(time (NULL));
    for(i=0; i<100; i++)
        {
            arrey[i]=rand()%201-100;
        }
//находим макс. полож. посл.
    for(i=0; i<100; i++)
        {
         if(arrey[i]>=0)
         {
            sum=sum+arrey[i];
            if (i==99)
              if(sum>max_sum)
              {
                max_sum=sum;
                sum=0;
              }
            }
         else
            if(sum>max_sum)
            {
                max_sum=sum;
                sum=0;
            }
            else
                sum=0;
        }
        for(i=0; i<100; i++)
       {
           printf(" %3d ", arrey[i]);
        if  ((i+1)%10==0) printf("\n");
          }

    printf("\n%s %d","max_sum =", max_sum);
    return 0;
}
