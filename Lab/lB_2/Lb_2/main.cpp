#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <langinfo.h>
int main(void) {
 setlocale(LC_ALL,"");
 wchar_t autor1[18], autor2[18], autor3[18];
 wchar_t title1[18], title2[18], title3[18];
 int year1, year2, year3;
 wchar_t group1=0, group2=0, group3=0;
 /* Введение фактических данных*/
 wprintf(L"1. Введите: автор, название, год выпуска, группа > ");
 wscanf(L"%s %s %d %lc",autor1, title1, &year1, &group1);
 wprintf(L"2. Введите: автор, название, год выпуска, группа > ");
 wscanf(L"%s %s %d %lc",autor2, title2, &year2, &group2);
 wprintf(L"3. Введите: автор, название, год выпуска, группа > ");
 wscanf(L"%s %s %d %lc",autor3, title3, &year3, &group3);
 /* Вывод таблицы */
 /* вывод заголовков */
 wprintf(L"----------------------------------------------------\n");
 wprintf(L"|Каталог библиотеки                                 |\n");
 wprintf(L"|---------------------------------------------------|\n");
 wprintf(L"|     Автор     |   Название    |   Год   |  Группа |\n");
 wprintf(L"|     книги     |               | выпуска |         |\n");
 wprintf(L"|---------------|---------------|---------|---------|\n");
 /* вывод строк фактических данных */
 wprintf(L"| %-13s | %-13s |   %4d  |    %lc    |\n", autor1, title1, year1, group1);
 wprintf(L"| %-13s | %-13s |   %4d  |    %lc    |\n", autor2, title2, year2, group2);
 wprintf(L"| %-13s | %-13s |   %4d  |    %lc    |\n", autor3, title3, year3, group3);
 /* вывод примечаний */
 wprintf(L"|---------------------------------------------------|\n");
 wprintf(L"| Примечание: Х - художественная литература;        |\n");
 wprintf(L"| У - учебная литература; С - справочная литература |\n");
 wprintf(L"-----------------------------------------------------\n");
 return 0;
}
