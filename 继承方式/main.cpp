#include <iostream>
using namespace std;

class Base
{
private:
    int a;
    void private_func()
    {
        cout << "����˽�к���";
    }

protected:
    int b;
    void protected_func()
    {
        cout << "���ౣ������,����->";
        private_func();
    }

public:
    int c;

    Base(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c)
    {
        cout << "���๹�캯��" << endl;
    }
};

class Derived : public Base
{
public:
    void derive_public_func()
    {
        cout << "�����๫������,����->";
        protected_func();
    }
};
int main(void)
{
    Derived d;
    d.derive_public_func();
    return 0;
}