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


int main(void)
{
    cout<<"_______WriteFile_______"<<endl;
    WriteFile();
    cout<<"_______ReadFile_______"<<endl;
    ReadFile();
    cout << "Exit" << endl;
    return 0;
}