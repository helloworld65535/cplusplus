
#include <iostream>
#include <string>

class Tclass
{
public:
    static const int publicConstI = 1;
    static int publicI;

protected:
    static const int protectedConstI = 2;
    static int protectedI;

private:
    static const int privateConstI = 3;
    static int privateI;
};

int Tclass::publicI = 4;

class DTclass : public Tclass
{
};

int main(void)
{
    Tclass t;
    DTclass d;
    std::cout << sizeof(t) << std::endl;
    std::cout << sizeof(d) << std::endl;
    // public=======================================================================

    // 1 - 静态成员变量 声明在类内，初始化在类外    <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

    // 可以通过     类名::静态成员变量名 在类外访问
    // 也可以通过   类对象.静态成员变量名 在类外访问
    std::cout << Tclass::publicI << std::endl;
    std::cout << t.publicI << std::endl;

    // 可以类外修改
    Tclass::publicI = 44;
    std::cout << Tclass::publicI << std::endl;
    t.publicI = 444;
    std::cout << t.publicI << std::endl;

    /*
    可以发现
    类名::静态成员变量名 类对象.静态成员变量名
    访问的都是同一个地址
     */
    std::cout << &Tclass::publicI << std::endl;
    std::cout << &t.publicI << std::endl;
    std::cout << &DTclass::publicI << std::endl;
    std::cout << &d.publicI << std::endl;

    // 2 - const静态成员变量 声明在类内，初始化既可以在类内，也可以在类外   <<<<<<<<<<<<<
    std::cout << Tclass::publicConstI << std::endl;
    std::cout << t.publicConstI << std::endl;

    return 0;
}