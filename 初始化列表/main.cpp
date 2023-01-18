#include <iostream>
using namespace std;

class Box
{
    int a, b, c;

public:
    Box(int p1=1, int p2=2, int p3=3) : a(p1), b(p2), c(p3)
    {
        Print();
    }

    void Print()
    {
        cout << "Box(a=" << a << ",b=" << b << ",c=" << c << ")" << endl;
    }
};

main(void)
{
    Box a;
    return 0;
}