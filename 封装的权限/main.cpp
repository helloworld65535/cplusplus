#include <iostream>
#include <cmath>
using namespace std;

class Person
{
public: // ����Ȩ��
    string name;

protected: // ����Ȩ��
    string car;

private: // ˽��Ȩ��
    string password;

public:
    void init() // ��ʼ��
    {
        name = "����";
        car = "������";
        password = "123456";
    }
    void Print()
    {
        cout << name << "��" << car << "���п�������:" << password << endl;
    }
};
class Son : public Person
{
public:
    void inherit()
    {
        cout << "�ܷ���:" << name;
        cout << ",�ܷ���:" << car;
        // cout << ",�ܷ���" <<password;//����
        cout << endl;
    }
};

int main(void)
{
    Person p;
    p.init();
    p.name = "����";
    // p.car = "�ܳ�";//����
    // p.password = "66666";//����
    p.Print();

    Son s;
    s.init();
    s.inherit();
    s.Print();

    return 0;
}