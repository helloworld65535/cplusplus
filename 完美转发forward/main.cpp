#include <iostream>
#include <memory>
#include <utility>

class FunctionLog
{
public:
    FunctionLog(const char *functionName) : functionName(functionName)
    {
        printf("\n🔽[%s]: Start.\n", functionName);
    }
    ~FunctionLog()
    {
        printf("\n🔼[%s]: End.\n", functionName);
    }

private:
    const char *functionName;
};

class Construct_Destruct_Test
{
public:
    Construct_Destruct_Test()
    {
        std::cout << "\n🆕[Constructing]:" << this << "\n";
    }
    ~Construct_Destruct_Test()
    {
        std::cout << "\n🆓[Destructing]:" << this << "\n";
    }
    void Display() const
    {
        std::cout << "\n🆗[Display]:" << this << "\n";
    }
};

template <class T>
void whatValue(T &&t)
{
    if (std::is_rvalue_reference<T &&>::value)
    {
        std::cout << "This is rvalue reference.\n";
    }
    else if (std::is_lvalue_reference<T &&>::value)
    {
        std::cout << "This is lvalue reference.\n";
    }
    else
    {
        std::cout << "This is not reference.\n";
    }
}

template <class T>
void use_forward(T &&t)
{
    whatValue(std::forward<T>(t));
}

int main()
{
    use_forward(1);

    int a = 2;
    use_forward(a);

    int &la = a;
    use_forward(la);

    int &&ra = 2;
    use_forward(ra);

    return 0;
}