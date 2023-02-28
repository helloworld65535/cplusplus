#include <iostream>
#include <chrono>

long fibonacci(unsigned n)
{
     if (n < 2)
          return n;
     return fibonacci(n - 1) + fibonacci(n - 2);
}

/**
 * @brief 测试函数的运行时间
 * @tparam Func 函数，可传入lambda表达式
 * @param log 打印标头
 * @param func 传入要测试的函数
 */
template <class Func>
void runtime(std::string log, Func func)
{
     auto start = std::chrono::steady_clock::now();
     func();
     auto end = std::chrono::steady_clock::now();
     std::chrono::duration<double> elapsed_seconds = std::chrono::duration<double>(end - start);

     std::cout << std::endl
               << log << ":" << elapsed_seconds.count() << "s\n";
}

int main()
{
     long f = 0;
     runtime("runing", [&]
             { f = fibonacci(42); });
     std::cout << "f(42) = " << f << '\n';
}
