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

class Resource
{
public: /*公共*/
    Resource() : data(new Construct_Destruct_Test()) {}
    ~Resource()
    {
        delete data;
    }
	//复制赋值运算符 （右值）
    void operator=(Resource &&other) noexcept
    {
        std::cout << "operator=\n";
        //交换当前data和源data
        std::swap(data, other.data);
        //释放源data
        delete other.data;
        //指针置空
        other.data = nullptr;
    }
    void Display() { data->Display(); }

private: /*私有*/
    Construct_Destruct_Test *data;
};

int main()
{
    FunctionLog l(__func__);
    Resource a;
    a.Display();
    {
        FunctionLog area("area");
        Resource b;
        b.Display();
        a = std::move(b);
    }
    return 0;
}