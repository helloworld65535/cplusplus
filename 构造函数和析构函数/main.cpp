#include <iostream>
using namespace std;

class Person
{
public:
    // 构造函数
    Person()
    {
        cout << "Person的构造函数调用" << endl;
    }
    // 析构函数
    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }
};

void func()
{
    cout << "实例化Person函数开始" << endl;
    Person p;
    cout << "实例化Person函数结束" << endl;
}

int main()
{
    cout << "实例化Person函数调用之前" << endl;
    func();
    cout << "实例化Person函数返回之后" << endl;
    return 0;
}