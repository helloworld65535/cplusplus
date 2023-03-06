#include <iostream>
#include <memory>

class Base
{
     std::string name_;

public: /*公共*/
     Base(std::string name = "") : name_(name)
     {
          std::cout << "structure:";
          Print();
     }
     ~Base()
     {
          std::cout << "destructor:";
          Print();
     }
     void Print()
     {
          printf("Bass(%s)\n", name_.c_str());
     }
};

std::shared_ptr<Base> getBase(std::string name)
{
     auto p = std::make_shared<Base>(name);
     return p;
}

void dosomething(std::shared_ptr<Base> p)
{
     p.get()->Print();
}

// 拥有特定资源的最后一个 shared_ptr 对象被销毁后，资源将释放。
// 详见 https://learn.microsoft.com/zh-cn/cpp/standard-library/shared-ptr-class?view=msvc-170#members
int main()
{
     dosomething(getBase("hello"));
     std::cout << "END" << std::endl;
     return 0;
}