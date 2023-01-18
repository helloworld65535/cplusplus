#include <iostream>
using namespace std;

class Person
{
public:
    string name;
    Person()
    {
        name = "无名";
        cout << name << "Person的构造函数调用" << endl;
    }

    Person(string n)
    {
        name = n;
        cout << name << "Person的构造函数调用" << endl;
    }

    Person(const Person &p)
    {
        name = "拷贝|" + p.name;
        cout << name << "Person的拷贝构造函数调用" << endl;
    }
    ~Person()
    {
        cout << name << "Person的析构函数调用" << endl;
    }
};

void SayName(Person p) // 值传递的方式给函数参数传值
{
    cout << "我的名字叫" << p.name << endl;
}

Person anonymous() // 以值方式返回局部对象
{
    Person p("匿名");
    cout << "局部对象:" << (int *)&p << endl;
    return p;
}

int main()
{
    cout << "            ==使用一个已经创建完毕的对象来初始化一个新对象==" << endl;
    Person p1("张三");
    Person cp1(p1); // 使用一个已经创建完毕的对象来初始化一个新对象
    cout << "            ==值传递的方式给函数参数传值==" << endl;
    SayName(p1);
    cout << "            ==以值方式返回局部对象==" << endl;
    Person np = anonymous();
    cout << (int *)&np << endl;
    cout << "            ==结束==" << endl;
    return 0;
}