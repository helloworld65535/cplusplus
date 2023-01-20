#include <iostream>
#include "ArrayList.hpp"
#include "LinkedList.hpp"

using namespace std;

void Print(const int &e)
{
    cout << e << " ";
}

int main()
{
    LinkedList<int> arrayList;
    for (int i = 0; i < 10; i++)
    {
        arrayList.Insert(arrayList.Length() + 1, i);
    }
    arrayList.Traverse(Print);
    cout << endl;
    for (int i = 0; i < 4; ++i)
    {
        arrayList.Delete(arrayList.Length());
    }
    arrayList.Traverse(Print);
    cout << endl;
    return 0;
}