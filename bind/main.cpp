#include <iostream>
#include <functional>

void print(int a, int b, int c)
{
    std::cout << a << " " << b << " " << c << std::endl;
}

int main()
{
    int b = 0;
    // 生成print的转发调用包装器，print的参数a绑定1，print的参数b绑定b的const引用，print的参数c绑定第一个占位符
    auto f1 = std::bind(print, 1, std::cref(b), std::placeholders::_1);
    b = 2;
    f1(3); // 1 2 3
    return 0;
}