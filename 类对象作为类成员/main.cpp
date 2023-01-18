#include <iostream>
using namespace std;

class Phone
{
public:
    Phone()
    {
        cout << "Phone构造函数" << endl;
    }
    ~Phone()
    {
        cout << "Phone析构函数" << endl;
    }
};
class Person
{
public:
    Phone phone;
    Person()
    {
        cout << "Person构造函数" << endl;
    }
    ~Person()
    {
        cout << "Person析构函数" << endl;
    }
};
main(void)
{
    Person p;

    return 0;
}