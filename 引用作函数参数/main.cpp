#include <iostream>

using namespace std;

void swap_c(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_cpp(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main(void)
{
    int a = 10, b = 20;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;

    cout << "swap_c" << endl;
    swap_c(&a, &b);

    cout << "a=" << a << endl;
    cout << "b=" << b << endl;

    cout << "swap_cpp" << endl;
    swap_cpp(a, b);

    cout << "a=" << a << endl;
    cout << "b=" << b << endl;

    return 0;
}