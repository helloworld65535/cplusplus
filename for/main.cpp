#include <cstdio>
#include <list>

namespace For
{
    int main(void)
    {
        for (int i = 0; i < 10; ++i)
        {
            printf("%d\n", i);
        }
        /*
        init_expression://初始化表达式
            int i = 0;
            goto cond_expression;
        statement:      //语句块
        {
            printf("%d\n", i);
        }
        loop_expression://循环表达式
            ++i;
        cond_expression://条件表达式
            if (i < 10)
            {
                goto statement;
            }
        */
        return 0;
    }
}
namespace For_range
{
    int main(void)
    {
        // int arr[] = {1, 2, 3, 4, 5, 6, 7};
        std::list<int> arr = {1, 2, 3, 4, 5, 6, 7};

        for (auto &i : arr) // 引用可修改 int &i=
        {
            i++;
            printf("%d ", i);
        }
        putchar('\n');
        for (auto i : arr) // 赋值不可修改 int i= 。原arr[]不会被改变,改变的是局部变量i
        {
            printf("%d ", i);
        }
        return 0;
    }
}
int main(void)
{
    // For::main();
    For_range::main();

    return 0;
}