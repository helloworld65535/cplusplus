#include <iostream>
using namespace std;

int add(int a, int b)
{
    int sum = a + b;
    cout << "两数和" << sum << endl;
    return sum;
}

int add(int a, int c, int b=0)
{
    int sum = a + b + c;
    cout << "int三数和:" << sum << endl;
    return sum;
}


double add(double a, double b, double c)
{
    double sum = a + b + c;
    cout << "double三数和:" << sum << endl;
    return sum;
}

int main(void)
{
    add(1,2);
    add(1,2,3);
    add(1.2,1.3,1.4);
    return 0;
}