#include <iostream>
#include <cstdarg>

namespace A
{
    int add_nums(int count, ...)
    {
        int result = 0;
        std::va_list args;     // 用来对参数列表的访问
        va_start(args, count); // 启用对可变函数实参的访问
        for (int i = 0; i < count; ++i)
        {
            result += va_arg(args, int); // 访问下一个可变函数实参
        }
        va_end(args); // 结束对可变函数实参的遍历
        return result;
    }
}

#include <initializer_list>

namespace B
{
    int add_nums(std::initializer_list<int> args)
    {
        int result = 0;
        for (auto &&i : args)
        {
            result += i;
        }
        return result;
    }
}

template <class T>
void show(T arg)
{
    std::cout << arg << std::endl;
}

template <class T, class... Args>
void show(T arg, Args... args)
{
    std::cout << arg << ",";
    show(args...);
}

int main(void)
{
    show(1, 2.2, 'c', "hello");
    return 0;
}

