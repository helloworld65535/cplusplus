#include <iostream>

// 自定义异常
class Divisor_exception : public std::exception
{
public: /*公共*/
    virtual const char *what() const throw()
    {
        return "Divisor_exception";
    }
};

int divInt(int a, int b)
{
    if (b == 0)
        throw Divisor_exception(); // 抛出异常
    return a / b;
}

namespace 捕获异常
{
    int main(void)
    {
        int result = 10;
        try
        { // 发生异常后跳转到catch
            result = divInt(1, 0);
            std::cout << "result=" << result << std::endl;
        }
        catch (const std::exception &e) // 捕获 std::exception 异常
        {                               // 处理异常
            std::cerr << e.what() << '\n';
        } // 处理后程序继续运行

        std::cout << "END "
                  << "result=" << result << std::endl;
        return 0;
    }
}

namespace 多种异常
{
    int main(void)
    {
        int result = 10;
        try
        { // 发生异常后跳转到catch
            int n = 0;
            if (n == 0)
                throw n;
            result = divInt(1, n);
            std::cout << "result=" << result << std::endl;
        }
        catch (int e)
        {
            std::cout << "e=" << e << std::endl;
        }
        catch (const std::exception &e) // 捕获 std::exception 异常
        {                               // 处理异常
            std::cout << e.what() << '\n';
        }
        // 处理catch后程序从这里继续运行
        std::cout << "END "
                  << "result=" << result << std::endl;
        return 0;
    }
}
