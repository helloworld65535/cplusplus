#include <iostream>
using namespace std;

class Phone
{
public:
    Phone()
    {
        cout << "Phone���캯��" << endl;
    }
    ~Phone()
    {
        cout << "Phone��������" << endl;
    }
};
class Person
{
public:
    Phone phone;
    Person()
    {
        cout << "Person���캯��" << endl;
    }
    ~Person()
    {
        cout << "Person��������" << endl;
    }
};
main(void)
{
    Person p;

    return 0;
}