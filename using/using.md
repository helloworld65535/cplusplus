# 关键字 `using`

**`using` 声明**将名称引入声明性区域，在该区域中显示 using 声明。

## 语法

```cpp
using [typename] nested-name-specifier unqualified-id ;
using declarator-list ;
using identifier = type ;
using namespace namespace-name ;
```

- `nested-name-specifier` 嵌套名称说明符
  命名空间、类或枚举名称和范围解析运算符 (::) 的序列，由范围解析运算符终止。 单个范围解析运算符可用于从全局命名空间引入名称。 关键字 `typename` 是可选的，在从基类引入到类模板时，可用于解析依赖名称。
- `unqualified-id` 非限定 ID 表达式
  非限定 ID 表达式，可以是标识符、重载运算符名称、用户定义的文本运算符或转换函数名称、类析构函数名称或模板名称和参数列表。
- `declarator-list [typename] nested-name-specifierunqualified-id` 声明符的逗号分隔列表，后跟省略号（可选）。
- `identifier`
  别名的名称。
- `type`
  您为其创建别名的类型标识符。
- `namespace-name`
  命名空间的名称

## 示例

### 1、引入命名空间

``` cpp
     // 在当前区域引入命名空间 std
     using namespace std;
     // std::cout
     cout << "hello world\n";
```

### 2、指定别名

```cpp
     // 声明 使用String 作为 std::string 的别名
     using String = std::string;
     String s("hello world\n");
     std::cout << s << std::endl;
```
### 3、引用声明

1. 引入命名空间内的**成员（变量和函数）**
```cpp
namespace A
{
     void print(std::string str)
     {
          printf("This is A::%s\n", str.c_str());
     }
     void f()
     {
          print("fun()");
     }
     void f(int)
     {
          print("fun(int)");
     }

} // namespace A
//引入命名空间内的所有 f函数 包括重载，此时f() f(int)可以当作全局函数使用
using A::f;
//注意不能再进行void f() 和void f(int)的定义与声明了
void fun3()
{
     f();
     f(0);
}
```
2. 派生类修改基类**成员（变量和函数）**可访问性
```cpp
class Base
{
public: /*公共*/
     void show()
     {
          puts("This is Base::show()");
     }
     virtual void f(int)
     {
          puts("This is Base::f(int)");
     }
     virtual void f(char)
     {
          puts("This is Base::f(char)");
     }
};

class Derived : private Base
{
public: /*公共*/
     // 将本来应该继承到 private 的 Base::show 的访问性修改为 public
     using Base::show;

     using Base::f;
     //派生类中的成员函数将重写基类中具有相同名称和参数类型的虚拟成员函数
     void f(int) override
     {
          puts("This is Derived::f(int)");
     }
};

void fun4()
{
     Derived d;
     d.show();
     d.f(0);
     d.f('c');
}
```
**注意**：`Base` 类的 `private` 成员 对于 `Derived` 类是不可访问的，所以不能修改。

## 参考
- [using 声明 | Microsoft Learn](https://learn.microsoft.com/zh-cn/cpp/cpp/using-declaration?view=msvc-170)
- [别名和 typedef (C++) | Microsoft Learn](https://learn.microsoft.com/zh-cn/cpp/cpp/aliases-and-typedefs-cpp?view=msvc-170)
- [命名空间 (C++) | Microsoft Learn](https://learn.microsoft.com/zh-cn/cpp/cpp/namespaces-cpp?view=msvc-170#using_directives)