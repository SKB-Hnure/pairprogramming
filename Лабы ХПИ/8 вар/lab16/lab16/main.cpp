#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
float F(float x)
{
return (2-x)-exp(x);
}
int main()
{
   float x1=0, x2=1, xc=0.5;
   float f1, f2, fc;
   float e=0.0001;
   printf("|   X1   |    X2   |    Xc   |   F1   |   F2   |   Fc   |\n");
   printf("---------------------------------------------------------\n");
   while (fabs(x2-x1)>e)
   {
   xc=(double)(x1+x2)/2;
  f1=F(x1); f2=F(x2); fc=F(xc);
  printf("|%7.5f | %7.5f | %7.5f | %6.3f | %6.3f | %6.3f |\n",x1, x2, xc, f1, f2, fc);
  if (((f1>0)&&(fc<0))||((f1<0)&&(fc>0)))
  x2=xc;
  if (((f2>0)&&(fc<0))||((f2<0)&&(fc>0)))
  x1=xc;
   }
   cout<<"xc="<<xc;
    return 0;
}
