#include <iostream>
using namespace std;

/// @brief 只要类中有纯虚函数,则该类就为抽象类
class AbstractClass
{
public:
    /// @brief 纯虚函数: virtual 返回类型 函数名() =0;
    virtual void func() = 0;
};

/// @brief 子类必须重写抽象类中的纯虚函数，否则也属于抽象类
class Son : public AbstractClass
{
public:
    void func()
    {
        cout << "纯虚函数实现" << endl;
    }
};

int main(void)
{
    /* 错误:不允许使用抽象类类型 "AbstractClass" 的对象 */
    // AbstractClass abstractClass;
    Son s;
    s.func();

    return 0;
}