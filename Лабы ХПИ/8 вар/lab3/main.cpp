#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x; //параметры, которые вводятся
    double a=1,b=1;
    double t1, t2;   //результаты
    double ax,bx;       //рабочая переменная

    printf("Введите x: ");
    scanf("%lf",&x);

    ax=a*x;
    bx=b*x;
    if ((a!=0)&&(x!=0))
    t1=1/pow(a,4)*(pow(x,3)/3-3*bx+3*pow(b,2)*log(x)+pow(b,3)/x);
    if ((1-sin(ax)!=0)&&(a!=0))
    t2=1/(1-sin(ax))+1/a*tan(ax/2);

    printf("t1 = %lg\n",t1);
    printf("t2 = %lg\n",t2);

    return 0;
}
