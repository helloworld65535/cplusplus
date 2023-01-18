#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int *a = new int;
    cout<<*a;
    delete a;

    int *b=new int[4];
    for (int i = 0; i < 4; i++)
    {
        cout<<b[i]<<',';
    }
    cout<<endl;
    delete[] b;

    return 0;
}
