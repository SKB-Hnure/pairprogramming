#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
    unsigned long n;            // параметр ряда
    double dbln;                // параметр ряда в форме с плавающей точкой
    double sum=0;               // сумма членов ряда
    double term;                // значение текущего члена
    const double eps=0.000001;  // предел точности

    for (n=0; ; n++)            //основной цикл
    {
     dbln=n;                    // преобразование n в форму с плавающей точкой
     //вычисление очередного члена
     term= pow(-1,dbln)*(1-pow(dbln,2)/(pow(2,n)+1));
     if (fabs(term)>=eps)       // проверка достижения предела точности
        sum+=term;              //если не достигнут - накопление суммы
     else break;                //если достигнут - выход из цикла
     if (n==9)                  //если 10 членов - вывод суммы
        printf("Сумма 10 членов ряда = %10.7lf\n",sum);
    }
    int m;
    if (n<=9)
    {
     for (m=n; m<9;m++)
     sum+= pow(-1,dbln)*(1-pow(dbln,2)/(pow(2,n)+1));
      printf("Сумма 10 членов ряда = %13.10lf\n",sum);
      }
   // конец основного цикла
   // вывод окончательной суммы
   printf("Полная сумма ряда = %10.7lf\n",sum);

    return 0;
}
