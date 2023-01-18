#include <iostream>
using namespace std;

class A
{
public:
    int a;
    char b;
    int c;
};
class B
{
public:
    int a;
    int b;
    char c;
};
class C
{
public:
    int a;
    static int b;
};
class D
{
public:
    int a;
    void fun()
    {
        cout << "D size of:" << sizeof(D) << endl;
    }
};
class Empty_1
{
};
class Empty_2
{
public:
    void fun()
    {
        cout << "Empty_2 size of:" << sizeof(Empty_2) << endl;
    }
};

main(void)
{
    cout << "A size of:" << sizeof(A) << endl;
    cout << "B size of:" << sizeof(B) << endl;
    cout << "C size of:" << sizeof(C) << endl;
    D().fun();
    cout << "Empty_1 size of:" << sizeof(Empty_1) << endl;
    Empty_2().fun();
    return 0;
}