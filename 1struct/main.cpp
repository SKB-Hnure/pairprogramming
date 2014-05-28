#include <iostream>

using namespace std;

int main()
{
    struct phone
    {
    int town;
    int number_station;
    int number_phone;
    };
    phone my_number={212,767,8900};
    phone number;
    cout<<"Enter code town, numer station and number subscriber";
    cin>>number.town>>number.number_station>>number.number_phone;
    cout<<my_number.town<<'\t'<<my_number.number_station<<'\t'<<my_number.number_phone<<endl;
    cout<<number.town<<'\t'<<number.number_station<<'\t'<<number.number_phone;
    return 0;
}


int area(int a, int b)
{
return a*b;
}
int main()
{
int little_side=2;
int big_side=5;
cout<<area(little_side, big_side);
return 0;
}
