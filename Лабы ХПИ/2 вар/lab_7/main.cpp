#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
const int T=4;
int n=0;
float y;
int h;
printf("---------------------\n");
printf("|    X    |    Y    |\n");
printf("---------------------\n");
for (float x=0;x<=19.75;x+=0.25)
{
if (x>=T*(n+1)) n++;
if ((x>=T*n)&&(x<=T*n+2))
y=sqrt(1-pow((x-(T*n+1)),2));
if ((x>T*n+2)&&(x<T*n+4))
y=-sqrt(1-pow((x-(T*n+3)),2));
printf("| %7.2f |  %6.4f | ", x, y);
  h=(y+1)*10;
if (y-1-h*10>0.5) h++;
 for (; h>0; h--) printf(" ");
  printf("*\n");
}
    return 0;
}
