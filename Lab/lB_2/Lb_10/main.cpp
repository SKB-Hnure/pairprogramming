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

    struct lib {
      char name[10]; //название
      char author[10];   //автор
      char group[5];    //группа
      int cnt;
      int year;      //год
      };

    lib arr[10];


    for(int i=0; i<3; i++)
    {
    wprintf(L"%d %s", i+1,". Введите: автор, название, год выпуска, группа\n");
    wscanf(L"%s %s %d %lc", arr[i].name, arr[i].author, &arr[i].year, &arr[i].group);
   // wscanf(L"%s %s %d %lc",autor2, title2, &year2, &group2);
    }

    while(flag)
    {
    for(int i=0; i<10; i++)
    {
        if(arr[i].author[i]>arr[i+1].author[i])
            {
            arr[i+1].author[i]=arr[i].author[i];
            caunt++;
             wprintf(L"Сортировка\n");
            }
         else
             if (caunt!=0)
                {
                flag=true;
                caunt=0;
                }
             else
                flag=false;


    }
    }




    /* вывод заголовков */
    wprintf(L"----------------------------------------------------\n");
    wprintf(L"|Каталог библиотеки                                 |\n");
    wprintf(L"|---------------------------------------------------|\n");
    wprintf(L"|     Автор     |   Название    |   Год   |  Группа |\n");
    wprintf(L"|     книги     |               | выпуска |         |\n");
    wprintf(L"|---------------|---------------|---------|---------|\n");
    /* вывод строк фактических данных */
    for(int i=0; i<3; i++)
    {
    wprintf(L"| %-13s | %-13s |   %4d  |    %lc    |\n", arr[i].name, arr[i].author, arr[i].year, arr[i].group);
    }

    return 0;
}
