#include <iostream>

using namespace std;
struct fraction {
          int numerator;
          int denominator;
};

bool found=false;
int del;
 fraction result;





fraction so (fraction result)
 {
     fraction temp;
     if(result.numerator>result.denominator)//находим меньший из членов
    {
        del=result.denominator;
    }
     else
     {
         del=result.numerator;
     }
 while (!found)
 {
     temp.numerator=result.numerator%del;
     temp.denominator=result.denominator%del;
      if((temp.numerator==0) && (temp.denominator==0))
      {
          result.numerator=result.numerator/del;
          result.denominator=result.denominator/del;
          found=true;
      }
      else
      {
        if(del>1)
        {
            del--;
        }
        else
        {

            found=true;
        }
    }
      }
      return result;
 }
fraction fsub(fraction a, fraction b)
 {
    fraction result, temp;
    result.numerator=(a.numerator*b.denominator)-(a.denominator*b.numerator);
    result.denominator=a.denominator*b.denominator;
    return so(result);
 }
 fraction fadd(fraction a, fraction b)
 {
fraction result, temp;
result.numerator=a.numerator*b.denominator+b.numerator*a.denominator;
result.denominator=a.denominator*b.denominator;
   return  so(result);
 }
fraction fmul(fraction a, fraction b)
 {
    fraction result, temp;
    result.numerator=a.numerator*b.numerator;
    result.denominator=a.denominator*b.denominator;
    return so(result);
 }
fraction fdev(fraction a, fraction b)
 {
    fraction result, temp;
    result.numerator=a.numerator*b.denominator;
    result.denominator=a.denominator*b.numerator;
    return so(result);
 }





int main()
{
 fraction operand[2];
 char operation;
 cout<<"Введите выражение: ";
cin>>operand[0].numerator>>operand[0].denominator;
cin>>operation;
cin>>operand[1].numerator>>operand[1].denominator;
  switch (operation)
 {
 case '+':
   result=fadd(operand[0], operand[1]);
   break;
  case '-':
   result=fsub(operand[0],operand[1]);
 break;
 case '*':
   result=fmul(operand[0],operand[1]);
 break;
 case '/':
   result=fdev(operand[0],operand[1]);
 break;
 default:
   cout<<"mistake";
 }
 cout<<"=";
 cout<<result.numerator<<'/'<<result.denominator;
    return 0;
}
