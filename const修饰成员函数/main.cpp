#include <iostream>
using namespace std;

class Cube
{
    int a;
    mutable int b; // 加关键字mutable后，在常函数中依然可以修改
    int c;

public:
    Cube(int a, int b, int c) : a(a), b(b), c(c) {}
    void setCube(int p1, int p2, int p3)
    {
        a = p1;
        b = p2;
        c = p3;
    }
    void Print() const
    {
        // a++;//无法修改成员属性
        b++;
        cout << "a=" << a << "b=" << b << "c=" << c << endl;
    }
};
main(void)
{
    Cube c(1, 2, 3);
    c.Print();

    const Cube cc(2, 3, 4);
    // cc.setCube(3,4,5);//常对象只能调用常函数
    cc.Print();
    return 0;
}