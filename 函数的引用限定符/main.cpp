#include <iostream>

class Base
{

public: /*公共*/
     int v_ = 0;
     Base(int v) : v_(v)
     {
          std::cout << "construction value is " << v_ << std::endl;
     }
     void print() &&
     {
          printf("&&\n");
     }
     void print() &
     {
          printf("&\n");
     }
     void print() const &
     {
          printf("const &\n");
     }

     /// @brief 左值加上左值
     Base operator+(const Base &other) const &
     {
          puts("left+left");
          return Base(v_ + other.v_);
     }
     /// @brief 右值加上左值
     Base operator+(const Base &other) &&
     {
          puts("right+left");
          v_ += other.v_;
          return *this;
     }
     /// @brief 只要加上右值就使用该右值，不使用引用限定符
     Base operator+(Base &&other)
     {
          puts("+right");
          other.v_ += v_;
          return other;
     }
};

template <class T>
void print_value(const T &)
{
     printf("is left");
}
template <class T>
void print_value(T &&)
{
     printf("is right");
}

int main(void)
{
     Base a(4);
     print_value(a+Base(2) + Base(3) + a);
     return 0;
}