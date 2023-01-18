#include <iostream>
using namespace std;

class Person
{
    int age;

public:
    void Print()
    {
        cout << "这是Person类" << endl;
    }
    void PrintAge()
    {
        if (this == nullptr)
        {
            return;
        }
        cout << "age=" << age << endl;
    }
};
main(void)
{
    Person *p = nullptr;
    p->Print();    // 空指针，可以调用成员函数
    p->PrintAge(); // 但是如果成员函数中用到了this指针，就不可以了
    return 0;
}