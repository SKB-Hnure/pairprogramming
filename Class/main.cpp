#include <iostream>

using namespace std;

class Student
{
    public:
        short age;
};

int main()
{
    Student alex, michael;
    alex.age = 8;
    michael.age = 9;

    cout << "Alex's age:" << alex.age<<"\n michael's age"<<michael.age;
    return 0;
}
