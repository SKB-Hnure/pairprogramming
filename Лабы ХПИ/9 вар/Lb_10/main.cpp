#include <iostream>
#include <stdio.h>
#include <locale.h>

using namespace std;

int main()

{
    setlocale(LC_ALL,"");

    int caunt;
    bool flag= true;

    struct pocket {
      char  name[30];
      char  firm[30];
      int parts;
      int cost;
      };

    pocket arr[10];
    pocket bufer;
    for(int i=0; i<3; i++)
    {
    printf("%d %s", i+1,". Введите: название, производитель, кол-во составных частей, цена($)\n");
    scanf("%s %s %d %d",   arr[i].name, arr[i].firm, &arr[i].parts, &arr[i].cost);
    }
    while(flag)
    {
        flag=false;
    for(int i=0; i<2; i++)
    {

        if((int)arr[i].name[0]>(int)arr[i+1].name[0])
            {
            bufer=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=bufer;
            flag=true;
               }
    }
    }


    /* вывод заголовков */
    printf("----------------------------------------------------\n");
    printf("|Офисные пакеты                                     |\n");
    printf("|---------------------------------------------------|\n");
    printf("|  Наименование | Производитель |  Сост.  | Цена($) |\n");
    printf("|               |               | частей  |         |\n");
    printf("|---------------|---------------|---------|---------|\n");
    /* вывод строк фактических данных */
    for(int i=0; i<3; i++)
    {
    printf("| %-13s | %-13s |   %4d  |   %4d  |\n", arr[i].name, arr[i].firm, arr[i].parts, arr[i].cost);
    }

    return 0;
}
