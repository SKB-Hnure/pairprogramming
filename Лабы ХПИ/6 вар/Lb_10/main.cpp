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
      wchar_t  name[30]; //название
      wchar_t  author[30];   //автор
      wchar_t group;    //группа
      int cnt;
      int year;      //год
      };

    lib arr[10];
    lib bufer;
    for(int i=0; i<3; i++)
    {
    wprintf(L"%d %s", i+1,". Введите: автор, название, год выпуска, группа\n");
    wscanf(L"%s %s %d %lc",   arr[i].author, arr[i].name, &arr[i].year, &arr[i].group);
    }
for (int i=0;i<3;i++)
//wprintf(L"%hu \n", (unsigned short) arr[i].author[0]);
    while(flag)
    {
        flag=false;
    for(int i=0; i<2; i++)
    {

        if((unsigned short)arr[i].author[0]>(unsigned short)arr[i+1].author[0])
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
    wprintf(L"----------------------------------------------------\n");
    wprintf(L"|Каталог библиотеки                                 |\n");
    wprintf(L"|---------------------------------------------------|\n");
    wprintf(L"|     Автор     |   Название    |   Год   |  Группа |\n");
    wprintf(L"|     книги     |               | выпуска |         |\n");
    wprintf(L"|---------------|---------------|---------|---------|\n");
    /* вывод строк фактических данных */
    for(int i=0; i<3; i++)
    {
    wprintf(L"| %-13s | %-13s |   %4d  |   %lc    |\n", arr[i].author, arr[i].name, arr[i].year, arr[i].group);
    }
   //  wscanf(L"%s %s %d %lc", arr[0].author, arr[0].name, &arr[0].year);

    return 0;
}
