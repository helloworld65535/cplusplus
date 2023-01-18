#include <iostream>

using namespace std;

/* 正确的使用 */
int add(int a,int b,int c);
int add(int a=0,int b=0,int c=0)
{
    return a+b+c;
}

/* int add(int a=0,int b=0,int c=0)
{
    return a+b+c;
} */

/* 错误的使用 */
/* int add(int a,int b,int c)
{
    return a+b+c;
} */



int main(void)
{
    cout<<add(1)<<endl;
    cout<<add(1,2)<<endl;
    cout<<add(1,2,3)<<endl;
    return 0;
}