#include <iostream>
using namespace std;

/// @brief ֻҪ�����д��麯��,������Ϊ������
class AbstractClass
{
public:
    /// @brief ���麯��: virtual �������� ������() =0;
    virtual void func() = 0;
};

/// @brief ���������д�������еĴ��麯��������Ҳ���ڳ�����
class Son : public AbstractClass
{
public:
    void func()
    {
        cout << "���麯��ʵ��" << endl;
    }
};

int main(void)
{
    /* ����:������ʹ�ó��������� "AbstractClass" �Ķ��� */
    // AbstractClass abstractClass;
    Son s;
    s.func();

    return 0;
}