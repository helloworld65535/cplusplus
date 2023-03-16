#include <iostream>
#include "run_time.hpp"

long fibonacci(unsigned n)
{
     if (n < 2)
          return n;
     return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
     long f = 0;
     run_time("runing", [&]
              { f = fibonacci(42); });
     run_time_us("runing", [&]
                 { f = fibonacci(42); });
     std::cout << "f(42) = " << f << '\n';
     return 0;
}
