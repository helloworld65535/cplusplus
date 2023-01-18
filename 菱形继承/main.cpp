#include <iostream>
using namespace std;

// 此时公共的父类Animal称为虚基类
class Animal
{
public:
    int age;
};
// 继承前加virtual关键字后，变为虚继承
class Sheep : public virtual Animal{};

class Camel : public virtual Animal{};

class Alpaca : public Sheep, public Camel{};

int main(void)
{
    Alpaca a;
    a.age = 10;
    cout << a.Animal::age << endl;
    cout << a.Sheep::age << endl;
    cout << a.Camel::age << endl;
    return 0;
}