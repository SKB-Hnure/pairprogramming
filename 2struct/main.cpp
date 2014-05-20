#include <iostream>

using namespace std;
struct fraction {
          double numerator;
          double denominator;
};

fraction fadd(fraction a, fraction b)
{
 fraction result;
 result.denominator=(a.numerator*b.denominator+b.numerator*a.denominator);
 result.numerator=(a.denominator*b.denominator);
 return result;
}
fraction fsub(fraction a, fraction b)
{
 fraction result;
 result.denominator=(a.numerator*b.denominator-b.numerator*a.denominator);
 result.numerator=(a.denominator*b.denominator);
 return result;
}
int main()
{
 fraction operand[2];
 double result;
 char operation;
 cout<<"Введите выражение: ";
 cin>>operand[0].numerator>>operand[0].denominator;
cin>>operation;
cin>>operand[1].numerator>>operand[1].denominator;
  switch (operation)
 {
 case '+':result=(operand[0].numerator*operand[1].denominator+operand[1].numerator*operand[0].denominator)/(operand[0].denominator*operand[1].denominator);
 break;
 case '-':result=(operand[0].numerator*operand[1].denominator-operand[0].denominator*operand[1].numerator)/(operand[0].denominator*operand[1].denominator);
 break;
 case '*':result=(operand[0].numerator/operand[0].denominator)*(operand[1].numerator/operand[1].denominator);
 break;
 case '/':result=(operand[0].numerator/operand[0].denominator)/(operand[1].numerator/operand[1].denominator);
 break;
 default:
 cout<<"mistake";
 break;
 }
 cout<<"\n";
 cout<<operand[0].numerator<<"/"<<operand[0].denominator<<operation<<operand[1].numerator<<"/"<<operand[1].denominator<<"="<<result;

    return 0;
}
