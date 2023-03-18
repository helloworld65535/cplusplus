#include <iostream>
#include <memory>

class Base
{
public: /*公共*/
     Base()
     {
          std::cout << "constructor" << std::endl;
     }
     void Print()
     {
          std::cout << "this " << this << std::endl;
     }
     ~Base()
     {
          std::cout << "delete";
          Print();
     }
};

auto foo()
{
     /*
     可以使用std::unique_ptr<T> p(new T)
     或std::unique_ptr<T> p = std::make_unique<T>()
     来构造std::unique_ptr对象。
      */
     auto a = std::unique_ptr<Base>(new Base());
     /*
     获取指针：p.get()。
      */
     a.get()->Print();
     return a;
}
int main(void)
{
     auto b = foo();
     /*
     也可以像指针一样使用*和->
      */
     (*b).Print();
     /* 移动构造 */
     auto c = std::move(b);
     c.reset(new Base); // 替换存储的指针,原指针指向内存被释放

     c.release(); // 释放指针
     c->Print();

     // auto d = c; //无法复制构造，std::unique_ptr不能被复制

     std::cout << "END" << std::endl;

     // 当std::unique_ptr对象被销毁时，它会自动释放它所拥有的对象
     return 0;
}