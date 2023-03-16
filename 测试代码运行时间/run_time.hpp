#include <iostream>
#include <chrono>

/**
 * @brief 测试函数的运行时间
 * @tparam Func 函数，可传入lambda表达式
 * @param log 打印标头
 * @param func 传入要测试的函数
 */
template <class Func>
void run_time(std::string log, Func func)
{
     auto start = std::chrono::steady_clock::now();
     func();
     auto end = std::chrono::steady_clock::now();
     auto elapsed_seconds = std::chrono::duration<double>(end - start);

     std::cout << std::endl
               << log << ":" << elapsed_seconds.count() << "s\n";
}
template <class Func>
void run_time_us(std::string log, Func func)
{
     auto start = std::chrono::steady_clock::now();
     func();
     auto end = std::chrono::steady_clock::now();
     auto elapsed_microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

     std::cout << std::endl
               << log << ":" << elapsed_microseconds.count() << "us\n";
}