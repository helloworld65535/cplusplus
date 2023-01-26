#include <iostream>

namespace All
{
    // [捕获参数列表](传入参数列表) mutable 异常规范 -> 返回类型{Lambda体}(立即调用参数列表)
    void Example1()
    {
        int addend1 = 1;
        int addend2 = 2;
        int sum = [add1 = addend1](int add2) mutable noexcept -> int
        {
            ++add1;
            return add1 + add2;
        }(addend2);
        std::cout << "addend1 = " << addend1 << std::endl;
        std::cout << "addend2 = " << addend2 << std::endl;
        std::cout << sum << std::endl;
    }

    // lambda的本质是类的仿函数
    void Example2()
    {
        int addend1 = 1;
        int addend2 = 2;
        // class lambda [](int add2) mutable->int noexcept
        auto function = [add1 = addend1](int add2) mutable noexcept -> int
        {
            ++add1;
            return add1 + add2;
        };
        int sum = function(addend2);
        std::cout << "addend1 = " << addend1 << std::endl;
        std::cout << "addend2 = " << addend2 << std::endl;
        std::cout << sum << std::endl;
    }
}

namespace Capture
{
    // [捕获参数列表](传入参数列表) mutable 异常规范 -> 返回类型{Lambda体}(立即调用参数列表)
    // 捕获参数列表可为空
    void Example1()
    {
        int addend1 = 1;
        int addend2 = 2;
        int sum = [](int add1, int add2) -> int
        {
            return add1 + add2;
        }(addend1, addend2);

        std::cout << "addend1 = " << addend1 << std::endl;
        std::cout << "addend2 = " << addend2 << std::endl;
        std::cout << sum << std::endl;
    }

    // 通过引用捕获变量
    void Example2()
    {
        int addend1 = 1;
        int addend2 = 2;
        int sum = [&addend1, &newname = addend2]() -> int
        {
            ++addend1;
            ++newname;
            return addend1 + newname;
        }();

        std::cout << "addend1 = " << addend1 << std::endl;
        std::cout << "addend2 = " << addend2 << std::endl;
        std::cout << sum << std::endl;
    }

    // 通过值捕获变量
    void Example3()
    {
        int addend1 = 1;
        int addend2 = 2;
        int sum = [addend1, newname = addend2]() -> int
        {
            return addend1 + newname;
        }();

        std::cout << "addend1 = " << addend1 << std::endl;
        std::cout << "addend2 = " << addend2 << std::endl;
        std::cout << sum << std::endl;
    }

    //[=] 默认通过值捕获所有变量
    void Example4()
    {
        int addend1 = 1;
        int addend2 = 2;
        int sum = [=, &addend1]() -> int
        {
            ++addend1;
            return addend1 + addend2;
        }();

        std::cout << "addend1 = " << addend1 << std::endl;
        std::cout << "addend2 = " << addend2 << std::endl;
        std::cout << sum << std::endl;
    }

    //[&] 默认通过引用捕获所有变量
    void Example5()
    {
        int addend1 = 1;
        int addend2 = 2;
        int sum = [&, addend2]() -> int
        {
            ++addend1;
            return addend1 + addend2;
        }();

        std::cout << "addend1 = " << addend1 << std::endl;
        std::cout << "addend2 = " << addend2 << std::endl;
        std::cout << sum << std::endl;
    }
}

namespace Mutable
{
    //mutable用于将 通过值捕获的变量 变为可修改。
    //因为 lambda类的 函数调用运算符重载函数 是const 的
    void Example1()
    {
        int addend1 = 1;
        int addend2 = 2;
        int sum = [=]() mutable noexcept -> int
        {
            ++addend1;
            ++addend2;
            return addend1+addend2;
        }();

        std::cout << "addend1 = " << addend1 << std::endl;
        std::cout << "addend2 = " << addend2 << std::endl;
        std::cout << sum << std::endl;
    }
}

int main(void)
{

    Mutable::Example1();

    return 0;
}