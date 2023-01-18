#include <iostream>
using namespace std;

// ��ʱ�����ĸ���Animal��Ϊ�����

class Person
{
protected:
    int age;
    string name;
    string nativePlace;

public:
    Person(string name = "����", int age = 0, string nativePlace = "����") : name(name), age(age), nativePlace(nativePlace)
    {
    }
    // ����ǰ�����virtual�ؼ��֣�����麯������ô�������ڱ����ʱ��Ͳ���ȷ�����������ˡ�
    virtual void self_introduction()
    {
        cout << "�ҽ�" << name << "��" << nativePlace << "��,����" << age << "�ꡣ" << endl;
    }
};

class Teacher : public Person
{
protected:
    string subject;

public:
    Teacher(string name = "����", int age = 0, string nativePlace = "����", string subject = "") : Person(name, age, nativePlace), subject(subject)
    {
    }
    void self_introduction()
    {
        cout << "�ҽ�" << name << "��" << nativePlace << "��,"
             << "�Ǹ�" << subject << "��ʦ,"
             << age << "�ꡣ" << endl;
    }
};

// ����ϣ������ʲô������ô�͵���ʲô����ĺ���
// ���������ַ�ڱ���׶ξ���ȷ������ô��̬����
// ���������ַ�����н׶β���ȷ�������Ƕ�̬����
void doSelf_introduction(Person &p)
{
    p.self_introduction();
}

int main(void)
{
    Person zs("����", 33, "����");
    Teacher ls("����", 44, "����", "����");
    doSelf_introduction(zs);
    doSelf_introduction(ls);

    return 0;
}