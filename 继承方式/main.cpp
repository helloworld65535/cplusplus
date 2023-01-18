#include <iostream>
using namespace std;

class Base
{
private:
    int a;
    void private_func()
    {
        cout << "基类私有函数";
    }

protected:
    int b;
    void protected_func()
    {
        cout << "基类保护函数,调用->";
        private_func();
    }

public:
    int c;

    Base(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c)
    {
        cout << "基类构造函数" << endl;
    }
};

class Derived : public Base
{
public:
    void derive_public_func()
    {
        cout << "派生类公共函数,调用->";
        protected_func();
    }
};
int main(void)
{
    Derived d;
    d.derive_public_func();
    return 0;
}