#include <iostream>
using namespace std;

class Base
{
public:
    int a;
    char b;
    char c;
};

class Drived : public Base
{
public:
    char d;
};

class Other
{
public:
    int a;
    char b;
    char c;
    char d;
};
int main(void)
{
    cout << "Base size is " << sizeof(Base) << endl;
    cout << "Drived size is " << sizeof(Drived) << endl;
    cout << "Other size is " << sizeof(Other) << endl;
    return 0;
}