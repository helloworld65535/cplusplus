#include <iostream>
using namespace std;

class Person
{
public:
    // ���캯��
    Person()
    {
        cout << "Person�Ĺ��캯������" << endl;
    }
    // ��������
    ~Person()
    {
        cout << "Person��������������" << endl;
    }
};

void func()
{
    cout << "ʵ����Person������ʼ" << endl;
    Person p;
    cout << "ʵ����Person��������" << endl;
}

int main()
{
    cout << "ʵ����Person��������֮ǰ" << endl;
    func();
    cout << "ʵ����Person��������֮��" << endl;
    return 0;
}