#include <iostream>
using namespace std;

class Person
{
    string name;
    int *age;

public:
    Person(string n)
    {
        name = n;
        age = nullptr;
    }
    Person(string n, int a)
    {
        name = n;
        age = new int(a);
    }

    Person(const Person &p)
    {
        name = p.name;
        age = new int(*p.age);
    }

    void Print()
    {
        cout << name << "的年龄为" << *age << endl;
    }

    ~Person()
    {
        cout << "析构函数" << endl;
        if (age)
        {
            cout << age << "被释放" << endl;
            delete age;
        }
    }
};

int main()
{
    Person xm("小明", 10);
    xm.Print();
    Person copy_xm(xm);
    copy_xm.Print();

    return 0;
}