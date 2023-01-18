#include <iostream>
using namespace std;

// 此时公共的父类Animal称为虚基类

class Person
{
protected:
    int age;
    string name;
    string nativePlace;

public:
    Person(string name = "无名", int age = 0, string nativePlace = "不详") : name(name), age(age), nativePlace(nativePlace)
    {
    }
    // 函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了。
    virtual void self_introduction()
    {
        cout << "我叫" << name << "是" << nativePlace << "人,今年" << age << "岁。" << endl;
    }
};

class Teacher : public Person
{
protected:
    string subject;

public:
    Teacher(string name = "无名", int age = 0, string nativePlace = "不详", string subject = "") : Person(name, age, nativePlace), subject(subject)
    {
    }
    void self_introduction()
    {
        cout << "我叫" << name << "是" << nativePlace << "人,"
             << "是个" << subject << "老师,"
             << age << "岁。" << endl;
    }
};

// 我们希望传入什么对象，那么就调用什么对象的函数
// 如果函数地址在编译阶段就能确定，那么静态联编
// 如果函数地址在运行阶段才能确定，就是动态联编
void doSelf_introduction(Person &p)
{
    p.self_introduction();
}

int main(void)
{
    Person zs("张三", 33, "北京");
    Teacher ls("李四", 44, "北京", "法律");
    doSelf_introduction(zs);
    doSelf_introduction(ls);

    return 0;
}