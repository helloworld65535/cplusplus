#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int *a = new int;
    cout << *a;
    delete a;

    // 如果分配请求的内存不足，operator new 会引发 std::bad_alloc 异常。
    // 或者，如果使用了 placement 形式 new(std::nothrow)，或者链接在非引发的 operator new 支持中，它将返回 nullptr。
    // 详见https://learn.microsoft.com/zh-cn/cpp/cpp/new-and-delete-operators?view=msvc-170
    int *b = new int[4];
    for (int i = 0; i < 4; i++)
    {
        cout << b[i] << ',';
    }
    cout << endl;
    delete[] b;

    return 0;
}
