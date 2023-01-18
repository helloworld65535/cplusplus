#include <iostream>
using namespace std;

class Base
{
public:
    int a;
    int b;
    void Print()
    {
        cout<<"a="<<a<<"b="<<b<<endl;
    }
};

class Drived : public Base
{
public:
    int a;
    int b;
    Drived(int p1,int p2,int p3,int p4)
    {
        a=p1;
        b=p2;
        Base::a=p3;
        Base::b=p4;
    }
    void Print()
    {
        cout<<"a="<<a<<"b="<<b<<endl;
    }

};
int main(void)
{
    Drived d(1,2,3,4);
    d.Print();
    d.Base::Print();
    return 0;
}