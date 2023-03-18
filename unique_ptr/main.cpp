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
     /* 也可以像指针一样使用*和-> */
     (*b).Print();
     /* 移动构造 */
     auto c = std::move(b);

     c.reset(new Base); // 替换存储的指针,原指针指向内存被释放
     if (c)             /* 判断是否有管理对象 */
          c->Print();
     std::cout << "=========[release]=========" << std::endl;
     delete c.release(); // 释放被管理对象的所有权。调用方负责删除该对象。若无管理对象则返回null

     // auto d = c; //无法复制构造，std::unique_ptr不能被复制
     auto pb = new Base();
     std::cout << "==============================================" << std::endl;
     auto e = std::unique_ptr<Base>(pb);
     auto f = std::unique_ptr<Base>(pb);
     std::cout << "==:" << (e == f) << std::endl; /* 比较拥有的指针 */
     std::cout << ">:" << (e > f) << std::endl;
     e.release();
     e->Print();
     f->Print();
     std::cout << "END" << std::endl;

     // 当std::unique_ptr对象被销毁时，它会自动释放它所拥有的对象
     return 0;
}
// 详见 https://en.cppreference.com/w/cpp/memory/unique_ptr