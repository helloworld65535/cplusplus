#include <iostream>
using namespace std;

class Person
{
    int age;

public:
    void Print()
    {
        cout << "����Person��" << endl;
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
    p->Print();    // ��ָ�룬���Ե��ó�Ա����
    p->PrintAge(); // ���������Ա�������õ���thisָ�룬�Ͳ�������
    return 0;
}