#include <iostream>
using namespace std;

class Person
{
    int age;

public:
    Person(int age)
    {
        this->age = age;
    }
    Person& Addage(const Person &p)
    {
        this->age += p.age;
        return *this;
    }
    void Print()
    {
        cout << "age=" << age << endl;
    }
};
main(void)
{
    Person p1 = 12;
    Person p2 = 10;
    p1.Print();
    p1.Addage(p2).Addage(p2).Addage(p2);
    p1.Print();
    return 0;
}