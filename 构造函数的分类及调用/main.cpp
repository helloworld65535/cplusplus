#include <iostream>
using namespace std;

class Answer
{
public:
    string text;
    Answer()
    {
        text = "��";
        cout << "Answer���޲ι��캯������" << endl;
    }
    Answer(string text)
    {
        this->text = text;
        cout << "Answer���вι��캯������" << endl;
    }
    Answer(const Answer &a)
    {
        text = a.text;
        cout << "Answer�Ŀ������캯������" << endl;
    }

    // ��������
    ~Answer()
    {
        cout << "Answer��������������" << endl;
    }
};

int main(void)
{
    /* ���ŷ� */
    Answer wangwu;                   // �޲�
    Answer lisi("��������д�Ĵ�"); // �в�
    Answer zhangsan(lisi);           // ����

    /* ��ʽ��*/
    // Answer wangwu1 = Answer();  //��Answer wangwu;
    // Answer lisi1 = Answer("��������1д�Ĵ�");
    // Answer zhangsan1=Answer(lisi1);

    /* ��ʽ�� */
    // Answer wangwu2;
    // Answer lisi2 = string("��������2д�Ĵ�");
    // Answer zhangsan2 = lisi2;

    cout << "����:" << wangwu.text << endl;
    cout << "����:" << lisi.text << endl;
    cout << "����:" << zhangsan.text << endl;
    return 0;
}