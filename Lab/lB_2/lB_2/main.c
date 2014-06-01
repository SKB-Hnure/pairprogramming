#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // область допустимых значений a,x,!=0 n!=1$2
    int n=3,m=1;

    double x,y; //параметры, которые вводятся
    double a=1,b=1;
    double t1, t2;   //результаты
    double ax;       //рабочая переменная

    printf("Введите x, y\n");
    scanf("%lf %lf",&x,&y);

    ax=a*x;
    t1=1/a*((-1/(((n-2)*pow(x,n-2))))+(b/((x,n-1)*pow(x,n-1))));
    t2=(2*x)/pow (a,2)*sin(ax)-(pow(x,2)/a-2/pow(a,3))*cos(ax);


    printf("t1 = %lg\n",t1);
    printf("t2 = %lg\n",t2);



    return 0;
}
