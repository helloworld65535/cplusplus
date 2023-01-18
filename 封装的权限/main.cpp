#include <iostream>
#include <cmath>
using namespace std;

class Person
{
public: // 公共权限
    string name;

protected: // 保护权限
    string car;

private: // 私有权限
    string password;

public:
    void init() // 初始化
    {
        name = "张三";
        car = "拖拉机";
        password = "123456";
    }
    void Print()
    {
        cout << name << "有" << car << "银行卡密码是:" << password << endl;
    }
};
class Son : public Person
{
public:
    void inherit()
    {
        cout << "能访问:" << name;
        cout << ",能访问:" << car;
        // cout << ",能访问" <<password;//错误
        cout << endl;
    }
};

int main(void)
{
    Person p;
    p.init();
    p.name = "李四";
    // p.car = "跑车";//错误
    // p.password = "66666";//错误
    p.Print();

    Son s;
    s.init();
    s.inherit();
    s.Print();

    return 0;
}