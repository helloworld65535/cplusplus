#include <iostream>
using namespace std;

class Person
{
public:
    string name;
    Person()
    {
        name = "����";
        cout << name << "Person�Ĺ��캯������" << endl;
    }

    Person(string n)
    {
        name = n;
        cout << name << "Person�Ĺ��캯������" << endl;
    }

    Person(const Person &p)
    {
        name = "����|" + p.name;
        cout << name << "Person�Ŀ������캯������" << endl;
    }
    ~Person()
    {
        cout << name << "Person��������������" << endl;
    }
};

void SayName(Person p) // ֵ���ݵķ�ʽ������������ֵ
{
    cout << "�ҵ����ֽ�" << p.name << endl;
}

Person anonymous() // ��ֵ��ʽ���ؾֲ�����
{
    Person p("����");
    cout << "�ֲ�����:" << (int *)&p << endl;
    return p;
}

int main()
{
    cout << "            ==ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���==" << endl;
    Person p1("����");
    Person cp1(p1); // ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
    cout << "            ==ֵ���ݵķ�ʽ������������ֵ==" << endl;
    SayName(p1);
    cout << "            ==��ֵ��ʽ���ؾֲ�����==" << endl;
    Person np = anonymous();
    cout << (int *)&np << endl;
    cout << "            ==����==" << endl;
    return 0;
}