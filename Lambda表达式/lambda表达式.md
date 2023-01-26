# lambda表达式


[C++ 中的 Lambda 表达式 | Microsoft Learn](https://learn.microsoft.com/zh-cn/cpp/cpp/lambda-expressions-in-cpp?view=msvc-170)

在 C++ 11 和更高版本中，Lambda 表达式（通常称为 Lambda）是一种在被调用的位置或作为参数传递给函数的位置定义**匿名函数对象**（闭包）的简便方法。 Lambda 通常用于封装传递给算法或异步函数的少量代码行。 本文将提供 Lambda 的定义、将它与其他编程技术进行比较。 其中介绍了各自的优点，并提供了一些基本示例。

# ****Lambda 表达式的各个部分****

ISO C++ 标准展示了作为第三个参数传递给 `std::sort()`函数的简单 lambda：

```cpp
void abssort(float* x, unsigned n) {
    std::sort(x, x + n,
        // Lambda expression begins
        [](float a, float b) {
            return (std::abs(a) < std::abs(b));
        } // end of lambda expression
    );
}
```

1. capture 子句（在 C++ 规范中也称为 Lambda 引导。）
2. 参数列表（可选）。 （也称为 Lambda 声明符）
3. mutable 规范（可选）。
4. exception-specification（可选）。
   
    允许修改副本，而不能修改原始项。
    
5. trailing-return-type（可选）。
6. Lambda 体。

**此图显示了 lambda 的组成部分：**

![lambdaexpsyntax.png](lambdaexpsyntax.png)

## ****capture 子句****

Lambda 可在其主体中引入新的变量（用 C++14），它还可以访问（或“捕获”）周边范围内的变量。 Lambda 以 capture 子句开头。 它指定捕获哪些变量，以及捕获是通过值还是通过引用进行的。 有与号 (`&`) 前缀的变量通过引用进行访问，没有该前缀的变量通过值进行访问。

空 capture 子句 `[ ]`指示 lambda 表达式的主体不访问封闭范围中的变量。

可以使用默认捕获模式来指示如何捕获 Lambda 体中引用的任何外部变量：`[&]` 表示通过引用捕获引用的所有变量，而 `[=]` 表示通过值捕获它们。 可以使用默认捕获模式，然后为特定变量显式指定相反的模式。 例如，如果 lambda 体通过引用访问外部变量 `total` 并通过值访问外部变量 `factor`，则以下 capture 子句等效：

```cpp
[&total, factor]
[factor, &total]
[&, factor]
[=, &total]
```

使用默认捕获时，只有 Lambda 体中提及的变量才会被捕获。

如果 capture 子句包含默认捕获 `&`，则该 capture 子句的捕获中没有任何标识符可采用 `&identifier` 形式。 同样，如果 capture 子句包含默认捕获 `=`，则该 capture 子句没有任何捕获可采用 `=identifier` 形式。 标识符或 **`this`** 在 capture 子句中出现的次数不能超过一次。 以下代码片段给出了一些示例：

```cpp
struct S { void f(int i); };

void S::f(int i) {
    [&, i]{};      // OK
    [&, &i]{};     // ERROR: i preceded by & when & is the default
    [=, this]{};   // ERROR: this when = is the default
    [=, *this]{ }; // OK: captures this by value. See below.
    [i, i]{};      // ERROR: i repeated
}
```

捕获后跟省略号是一个包扩展，如以下[可变参数模板](https://learn.microsoft.com/zh-cn/cpp/cpp/ellipses-and-variadic-templates?view=msvc-170)示例中所示：

```cpp
template<class... Args>
void f(Args... args) {
    auto x = [args...] { return g(args...); };
    x();
}
```

要在类成员函数体中使用 Lambda 表达式，请将 **`this`** 指针传递给 capture 子句，以提供对封闭类的成员函数和数据成员的访问权限。

Visual Studio 2017 版本 15.3 及更高版本（在 `[/std:c++17](https://learn.microsoft.com/zh-cn/cpp/build/reference/std-specify-language-standard-version?view=msvc-170)` 模式及更高版本中可用）：可以通过在 capture 子句中指定 **`*this`** 通过值捕获 **`this`** 指针。 通过值捕获会将整个闭包复制到调用 Lambda 的每个调用站点。 （闭包是封装 Lambda 表达式的匿名函数对象）。当 Lambda 在并行或异步操作中执行时，通过值捕获非常有用。 它在某些硬件体系结构（如 NUMA）上特别有用。

有关展示如何将 Lambda 表达式与类成员函数一起使用的示例，请参阅 [Lambda 表达式示例](https://learn.microsoft.com/zh-cn/cpp/cpp/examples-of-lambda-expressions?view=msvc-170)中的“示例：在方法中使用 Lambda 表达式”。

在使用 capture 子句时，建议你记住以下几点（尤其是使用采取多线程的 Lambda 时）：

- 引用捕获可用于修改外部变量，而值捕获却不能实现此操作。 （**`mutable`** 允许修改副本，而不能修改原始项。）
- 引用捕获会反映外部变量的更新，而值捕获不会。
- 引用捕获引入生存期依赖项，而值捕获却没有生存期依赖项。 当 Lambda 以异步方式运行时，这一点尤其重要。 如果在异步 Lambda 中通过引用捕获局部变量，该局部变量将很容易在 Lambda 运行时消失。 代码可能会导致在运行时发生访问冲突。

## 参数列表

Lambda 既可以捕获变量，也可以接受输入参数。 参数列表（在标准语法中称为 Lambda 声明符）是可选的，它在大多数方面类似于函数的参数列表。

```cpp
auto y = [] (int first, int second)
{
    return first + second;
};
```

在 C++14 中，如果参数类型是泛型，则可以使用 **`auto`**关键字作为类型说明符。 此关键字将告知编译器将函数调用运算符创建为模板。 参数列表中的每个 **`auto`**实例等效于一个不同的类型参数。

```cpp
auto y = [] (auto first, auto second)
{
    return first + second;
};
```

Lambda 表达式可以将另一个 Lambda 表达式作为其自变量。 有关详细信息，请参阅 [Lambda 表达式示例](https://learn.microsoft.com/zh-cn/cpp/cpp/examples-of-lambda-expressions?view=msvc-170)一文中的“高阶 Lambda 表达式”。

由于参数列表是可选的，因此在不将自变量传递到 Lambda 表达式，并且其 Lambda 声明符不包含 exception-specification、trailing-return-type 或 **`mutable`** 的情况下，可以省略空括号。

## **mutable 规范**

通常，Lambda 的函数调用运算符是 const-by-value，但对 **`mutable`** 关键字的使用可将其取消。它不产生 mutable 数据成员。 利用 **`mutable`** 规范，Lambda 表达式的主体可以修改通过值捕获的变量。 本文后面的一些示例将展示如何使用 **`mutable`**。

## **异常规范**

你可以使用 **`noexcept`** 异常规范来指示 Lambda 表达式不会引发任何异常。 与普通函数一样，如果 Lambda 表达式声明 **`noexcept`** 异常规范且 Lambda 体引发异常，Microsoft C++ 编译器将生成警告 [C4297](https://learn.microsoft.com/zh-cn/cpp/error-messages/compiler-warnings/compiler-warning-level-1-c4297?view=msvc-170)，如下所示：

```cpp
// throw_lambda_expression.cpp
// compile with: /W4 /EHsc
int main() // C4297 expected
{
   []() noexcept { throw 5; }();
}

```

有关详细信息，请参阅[异常规范 (throw)](https://learn.microsoft.com/zh-cn/cpp/cpp/exception-specifications-throw-cpp?view=msvc-170)。

## **返回类型**

将自动推导 Lambda 表达式的返回类型。 无需使用 `[auto](https://learn.microsoft.com/zh-cn/cpp/cpp/auto-cpp?view=msvc-170)` 关键字，除非指定了 trailing-return-type。 trailing-return-type 类似于普通函数或成员函数的 return-type 部分。 但是，返回类型必须跟在参数列表的后面，你必须在返回类型前面包含 trailing-return-type 关键字 **`->`**。

如果 Lambda 体仅包含一个返回语句，则可以省略 Lambda 表达式的 return-type 部分。 或者，在表达式未返回值的情况下。 如果 lambda 体包含单个返回语句，编译器将从返回表达式的类型推导返回类型。 否则，编译器会将返回类型推导为 **`void`**。 下面的示例代码片段说明了这一原则：

```cpp
auto x1 = [](int i){ return i; }; // OK: return type is int
auto x2 = []{ return{ 1, 2 }; };  // ERROR: return type is void, deducing
                                  // return type from braced-init-list isn't valid
```

lambda 表达式可以生成另一个 lambda 表达式作为其返回值。 有关详细信息，请参阅 [Lambda 表达式示例](https://learn.microsoft.com/zh-cn/cpp/cpp/examples-of-lambda-expressions?view=msvc-170)中的“高阶 Lambda 表达式”。

## **Lambda 体**

Lambda 表达式的 Lambda 体是一个复合语句。 它可以包含普通函数或成员函数体中允许的任何内容。 普通函数和 lambda 表达式的主体均可访问以下变量类型：

- 从封闭范围捕获变量，如前所述。
- 参数。
- 本地声明变量。
- 类数据成员（在类内部声明并且捕获 **`this`** 时）。
- 具有静态存储持续时间的任何变量（例如，全局变量）。

# 语法

```cpp
[捕获参数列表](传入参数列表) mutable 异常规范 -> 返回类型{Lambda体}(立即调用参数列表)
```

## 捕获参数列表

将lambda表达式外的参数作为捕获参数传入lambda（函数）体内。多个参数数用`,` 隔开。

不访问封闭范围中的变量则`[ ]` 不填入内容。

以下 capture 子句等效：

```cpp
[&total, factor]
[factor, &total]
[&, factor]
[=, &total]
```

一般传入引用，如下所示：

```cpp
#include <iostream>
using namespace std;
int main()
{
    string capturearg1 = "hello ";
    string capturearg2 = "world";

    // 定义一个lambda函数
    auto lambda_function = [&capturearg1, capturearg2](int x, int y) -> int
    {
        cout << "capture args:" << capturearg1 << capturearg2 << endl;
        return x + y;
    };

    int result = lambda_function(2, 3);

    printf("The result is: %d\n", result);

    return 0;
}
```

捕获参数列表有**两种写法**

1. 无前缀的变量通过值捕获变量（只读访问外部变量）
   
    ```cpp
    int add1 = 1;
    int add2 = 2;
    // 定义一个lambda函数
    auto lambda_function = [add1, add2](int x, int y)  -> int 
    {
        return x + y + add1 + add2;
    };
    ```
    
2. `&`前缀的变量通过引用捕获变量
   
    ```cpp
    int add1 = 1;
    int add2 = 2;
    // 定义一个lambda函数
    auto lambda_function = [&add1, &add2](int x, int y)  -> int 
    {
        add1=0;
        add2=0;
        return x + y + add1 + add2;
    };
    ```
    
3. `[=]` **默认**通过值捕获所有变量（只读访问外部变量）
   
   
    ```cpp
    int add1 = 1;
    int add2 = 2;
    // 定义一个lambda函数
    auto lambda_function = [=](int x, int y)  -> int 
    {
        return x + y + add1 + add2;
    };
    ```
    
4. `[&]` **默认**通过引用捕获所有变量
   
    ```cpp
    int add1 = 1;
    int add2 = 2;
    // 定义一个lambda函数
    auto lambda_function = [&](int x, int y)  -> int 
    {
        add1=0;
        add2=0;
        return x + y + add1 + add2;
    };
    ```
    

## 参数列表（可选）

与函数参数列表相同，无参可以不写。

## mutable 规范（可选）

通常，Lambda 的函数调用运算符是 const-by-value，但对 **`mutable`**关键字的使用可将其取消。它不产生 mutable 数据成员。 利用 **`mutable`**规范，Lambda 表达式的主体可以修改通过值捕获的变量。 

```cpp
#include <iostream>
using namespace std;
int main()
{

    int add=1;
    // 定义一个lambda函数
    auto lambda_function = [=](int x) mutable
    {
        add=5;
        return x+add;
    };
    int result = lambda_function(3);

    printf("The result is: %d\n", result);

    return 0;
}
```

**取消值捕获变量的只读访问，使之可以更改。**

## **异常规范**

你可以使用 **`noexcept`** 异常规范来指示 Lambda 表达式不会引发任何异常。 与普通函数一样，如果 Lambda 表达式声明 **`noexcept`** 异常规范且 Lambda 体引发异常，Microsoft C++ 编译器将生成警告 [C4297](https://learn.microsoft.com/zh-cn/cpp/error-messages/compiler-warnings/compiler-warning-level-1-c4297?view=msvc-170)，如下所示：

```cpp
// throw_lambda_expression.cpp
// compile with: /W4 /EHsc
int main() // C4297 expected
{
   []() noexcept { throw 5; }();
}

```

有关详细信息，请参阅[异常规范 (throw)](https://learn.microsoft.com/zh-cn/cpp/cpp/exception-specifications-throw-cpp?view=msvc-170)。

## 返回类型（可选）

lambda函数的返回值，可以不填编译器自动推导。

## lambda体

lambda的函数体。

## 立即调用参数列表（可选）

如果该lambda函数要立即调用，则填写参数。

# 例子

## Lambda表达式的声明

由于 lambda 表达式已类型化，所以你可以将其指派给 **`auto`**变量或 `[function](https://learn.microsoft.com/zh-cn/cpp/standard-library/function-class?view=msvc-170)`对象，如下所示：

```cpp
#include <functional>
#include <iostream>

int main()
{

    using namespace std;

    // Assign the lambda expression that adds two numbers to an auto variable.
    auto f1 = [](int x, int y) { return x + y; };

    cout << f1(2, 3) << endl;

    // Assign the same lambda expression to a function object.
    function<int(int, int)> f2 = [](int x, int y) { return x + y; };

    cout << f2(3, 4) << endl;
}
```

## ****调立即用 Lambda 表达式****

你可以**立即调用** Lambda 表达式，如下面的代码片段所示。 

```cpp
#include <iostream>

int main()
{
   using namespace std;
   int n = [] (int x, int y) { return x + y; }(5, 4);
   cout << n << endl;
}
```

将 lambda 作为**自变量传递**给标准库算法，例如 `find_if` 。

```cpp
#include <list>
#include <algorithm>
#include <iostream>

int main()
{
    using namespace std;

    // Create a list of integers with a few initial elements.
    list<int> numbers;
    numbers.push_back(13);
    numbers.push_back(17);
    numbers.push_back(42);
    numbers.push_back(46);
    numbers.push_back(99);

    // Use the find_if function and a lambda expression to find the
    // first even number in the list.
    const list<int>::const_iterator result =
        find_if(numbers.begin(), numbers.end(),[](int n) { return (n % 2) == 0; });

    // Print the result.
    if (result != numbers.end()) {
        cout << "The first even number in the list is " << *result << "." << endl;
    } else {
        cout << "The list contains no even numbers." << endl;
    }
}
```

## ****嵌套 Lambda 表达式****

```cpp
#include <iostream>

int main()
{
    using namespace std;

    // The following lambda expression contains a nested lambda
    // expression.
    int timestwoplusthree = [](int x) { return [](int y) { return y * 2; }(x) + 3; }(5);

    // Print the result.
    cout << timestwoplusthree << endl;
}
```

# Lambda表达式的本质

[C++ Insights (cppinsights.io)](https://cppinsights.io/)

****Source:****

```cpp
#include <iostream>
using namespace std;
int main()
{
    int add1 = 1;
    int add2 = 2;
    // 定义一个lambda函数
    auto lambda_function = [=](int x)
    {
        return x+add1+add2;
    };
    int result = lambda_function(3);

    printf("The result is: %d\n", result);

    return 0;
}
```

**Insight:**

```cpp
#include <iostream>
using namespace std;
int main()
{
  int add1 = 1;
  int add2 = 2;
    
  class __lambda_8_28
  {
    public: 
    inline /*constexpr */ int operator()(int x) const
    {
      return (x + add1) + add2;
    }
    
    private: 
    int add1;
    int add2;
    
    public:
    __lambda_8_28(int & _add1, int & _add2)
    : add1{_add1}
    , add2{_add2}
    {}
    
  };
  
  __lambda_8_28 lambda_function = __lambda_8_28{add1, add2};
  int result = lambda_function.operator()(3);
  printf("The result is: %d\n", result);
  return 0;
}
```

---

lambda表达式可以**理解**为一个匿名的内联函数。

但是其**本质是类的仿函数（函数调用运算符重载函数）**

捕获列表是**类的私有成员**

参数列表是**函数调用运算符重载函数的参数列表**

返回类型是**函数调用运算符重载函数的返回类型**

lambda体是**函数调用运算符重载函数体**

mutable 规范和异常规范都是修饰的**函数调用运算符重载函数**