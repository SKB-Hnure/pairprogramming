#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <langinfo.h>

using namespace std;

int main()

{
    setlocale(LC_ALL,"");

    int caunt;
    bool flag= true;

    struct searching {
      int year;
      wchar_t  name[30]; //название
      int d;
      int f;      //год
      };

    searching arr[10];
    searching bufer;
    for(int i=0; i<3; i++)
    {
 wprintf(L"1. Введите: год, научный руководитель, диаметр антенны(м), рабочая частота(МГц) > ");
 wscanf(L"%d %s %d %d",&arr[i].year, arr[i].name, &arr[i].d, &arr[i].f);
    }
for (int i=0;i<3;i++)
//wprintf(L"%hu \n", (unsigned short) arr[i].author[0]);
    while(flag)
    {
        flag=false;
    for(int i=0; i<2; i++)
    {

        if(arr[i].year>arr[i+1].year)
            {
            bufer=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=bufer;
           // wprintf(L"Сортировка\n");
            flag=true;
        //  wprintf(L"%d %ld| %d %ld\n", i , (unsigned short)arr[i].author[0], i+1, (unsigned short)arr[i+1].author[0]);
            }
    }
    }


    /* вывод заголовков */
 wprintf(L"--------------------------------------------\n");
 wprintf(L"|Проекты поиска внеземных сигналов         |\n");
 wprintf(L"|------------------------------------------|\n");
 wprintf(L"|  Год  |   Научный    | Диаметр | Рабочая |\n");
 wprintf(L"|       | руководитель | антены  | частота |\n");
 wprintf(L"|-------|--------------|---------|---------|\n");
    /* вывод строк фактических данных */
    for(int i=0; i<3; i++)
    {
    wprintf(L"| %5d | %-12s | %7d | %7d |\n", arr[i].year, arr[i].name, arr[i].d, arr[i].f);
    }
   //  wscanf(L"%s %s %d %lc", arr[0].author, arr[0].name, &arr[0].year);

    return 0;
}
