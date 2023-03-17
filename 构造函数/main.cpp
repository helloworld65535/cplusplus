#include <iostream>

class Object
{
public:
     Object()
     {
          value_ = nullptr;
          std::cout << "Object()";
          ShowObject();
     }

     Object(int value)
     {
          value_ = new int(value);
          std::cout << "Object(int)";
          ShowObject();
     }

     Object(const Object &other)
     {
          value_ = new int(*other.value_);
          std::cout << "Object(const Object &)";
          ShowObject();
     }

     Object(Object &&other)
     {
          value_ = other.value_;
          other.value_ = nullptr;
          std::cout << "Object(Object &&)";
          ShowObject();
     }

     void ShowObject()
     {
          std::cout << "{" << std::endl;
          std::cout << "this -> " << this << std::endl;
          std::cout << "value ptr -> " << value_ << std::endl;
          if (value_ != nullptr)
          {
               std::cout << "value is " << *value_ << std::endl;
          }

          std::cout << "}" << std::endl;
     }

     ~Object()
     {
          std::cout << "!!!!!!!!!~Object()!!!!!!!!" << std::endl;
          ShowObject();
          delete value_;
          value_ = nullptr;
     }

private:
     int *value_;
};

int main(int argc, char const *argv[])
{
     Object o1(1);  /* 构造 */
     Object o2(o1); /* 复制构造 */

     /*
     这种优化称为RVO(Return Value Optimization)。
     如果你想确保移动构造函数被调用，你可以使用-fno-elide-constructors编译选项来禁用RVO。
     这样，编译器就会强制使用移动构造函数来创建新的对象
     g++ -std=c++11 -fno-elide-constructors main.cpp -o main
      */
     Object o3(Object(2)); /* 移动构造 */
     return 0;
}