#include <iostream>
#include "ArrayList.hpp"

using namespace std;

void Print(const int &e)
{
    cout << e << " ";
}

int main()
{


    ArrayList<int> arrayList;
    for (int i = 0; i < 10; i++)
    {
        arrayList.Insert(arrayList.Length() + 1, i);
    }
    arrayList.Traverse(Print);
    std::cout << std::endl;
    return 0;
}