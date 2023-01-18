#include <iostream>
using namespace std;

class Person
{
    string name;
    static int num;

public:
    Person(string name) : name(name)
    {
        num++;
        cout << num << "|" << name << endl;
    }
    static int HowMany()
    {
        return num;
    }
    ~Person()
    {
        num--;
    }
};

int Person::num = 0;

main(void)
{
    Person p[] = {string("����"), string("����"), string("����"), string("����")};
    for (int i = 0; i < 4; i++)
    {
        cout << p[i].HowMany()
             << endl;
    }

    return 0;
}