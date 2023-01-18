#include <iostream>
using namespace std;

class Base
{
private:
    int a, b, c;

public:
    void Print()
    {
        cout << "(" << a << "," << b << "," << c << ")" << endl;
    }

    Base(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c)
    {
        cout << "基类构造函数" << endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "派生类构造函数" << endl;
    }
};
int main(void)
{
    Derived d;
    d.Print();
    return 0;
}