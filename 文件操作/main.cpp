#include <iostream>

#include <fstream> //����ͷ�ļ�
using namespace std;
void WriteFile()
{
    // ����������
    ofstream outfilestream;
    // ָ���򿪷�ʽ
    outfilestream.open("write.txt", ios::out);
    // д������
    outfilestream << "����������" << endl;
    outfilestream << "���䣺18" << endl;
    outfilestream << "�Ա���" << endl;
    // �ر���
    outfilestream.close();
}
void ReadFile()
{
    // ����������
    ifstream infilestream;
    // ָ���򿪷�ʽ
    infilestream.open("write.txt", ios::in);
    // �ж��Ƿ�򿪳ɹ�
    if (!infilestream.is_open())
    {
        cout << "open file fail" << endl;
        infilestream.close();
        return;
    }
    // ��ȡ����
    /* ����һ */

    /* char buf1[1024] = {0};
    while (infilestream >> buf1)
    {
        cout << buf1 << endl;
    } */

    /* ������ */

    /* char buf2[1024] = {0};
    while (infilestream.getline(buf2, sizeof(buf2)))
    {
        cout << buf2 << endl;
    } */

    /* ������ */

    string buf3;
    while (getline(infilestream, buf3))
    {
        cout << buf3 << endl;
    }

    /* ������ */

    /* char buf4;
    while ((c = infilestream.get()) != EOF)
    {
        cout << buf4;
    } */

    // �ر���
    infilestream.close();
}

class Person
{
public:
    char name[64];
    int age;
};
void BinaryWriteFile()
{
    ofstream outfilestream;
    // ָ���򿪷�ʽ
    outfilestream.open("binarywrite.txt", ios::out | ios::binary);
    // д������
    Person p1 = {"����", 18};
    Person p2 = {"����", 19};
    Person p3 = {"����", 20};
    outfilestream.write((const char *)&p1, sizeof(Person));
    outfilestream.write((const char *)&p2, sizeof(Person));
    outfilestream.write((const char *)&p3, sizeof(Person));

    // �ر���
    outfilestream.close();
}

void BinaryReadFile()
{
    fstream infilestream;
    // ָ���򿪷�ʽ
    infilestream.open("binarywrite.txt", ios::in | ios::binary);
    // �ж��Ƿ�򿪳ɹ�
    if (!infilestream.is_open())
    {
        cout << "open file fail" << endl;
        infilestream.close();
        return;
    }
    // ��ȡ����
    Person p[3];
    // infilestream.read((char *)&p[0], sizeof(Person));
    // infilestream.read((char *)&p[1], sizeof(Person));
    // infilestream.read((char *)&p[2], sizeof(Person));

    for (int i = 0; i < 3; i++)
    {
        infilestream.read((char *)&p[i], sizeof(Person));
        cout << "������" << p[i].name << endl
             << "���䣺" << p[i].age << endl;
    }

    // �ر���
    infilestream.close();
}
int main(void)
{
    cout<<"_______WriteFile_______"<<endl;
    WriteFile();
    cout<<"_______ReadFile_______"<<endl;
    ReadFile();
    cout<<"_______BinaryWriteFile_______"<<endl;
    BinaryWriteFile();
    cout<<"_______BinaryReadFile_______"<<endl;
    BinaryReadFile();
    cout << "Exit" << endl;
    return 0;
}