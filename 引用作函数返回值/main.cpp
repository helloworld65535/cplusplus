#include <iostream>

using namespace std;

//不要返回局部变量的引用
/* 错误使用 */
/* int& test1()
{
    int a=10;
    return a;
} */

int& test2()
{
    static int a=10;    //静态全局变量
    return a;
}

int main(void)
{
    int &ref=test2();
    cout<<ref<<endl;
    test2()=100;
    cout<<ref<<endl;
    return 0;
}