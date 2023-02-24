#include <iostream>

void fun1()
{
     // 在当前区域引入命名空间 std
     using namespace std;
     // std::cout
     cout << "hello world\n";
}

void fun2()
{
     // 声明 使用String 作为 std::string 的别名
     using String = std::string;
     String s("hello world\n");
     std::cout << s << std::endl;
}

namespace A
{
     void print(std::string str)
     {
          printf("This is A::%s\n", str.c_str());
     }
     void f()
     {
          print("fun()");
     }
     void f(int)
     {
          print("fun(int)");
     }

} // namespace A
// 引入命名空间内的所有 f函数 包括重载，此时f() f(int)可以当作全局函数使用
using A::f;
void fun3()
{
     f();
     f(0);
}

class Base
{
public: /*公共*/
     void show()
     {
          puts("This is Base::show()");
     }
     virtual void f(int)
     {
          puts("This is Base::f(int)");
     }
     virtual void f(char)
     {
          puts("This is Base::f(char)");
     }
};

class Derived : private Base
{
public: /*公共*/
     // 将本来应该继承到 private 的 Base::show 的访问性修改为 public
     using Base::show;
     
     using Base::f;
     //派生类中的成员函数将重写基类中具有相同名称和参数类型的虚拟成员函数
     void f(int) override
     {
          puts("This is Derived::f(int)");
     }
};

void fun4()
{
     Derived d;
     d.show();
     d.f(0);
     d.f('c');
}

int main(void)
{
     fun4();
     return 0;
}