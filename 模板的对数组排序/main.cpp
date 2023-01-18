#include <iostream>
using namespace std;

template <class T>
void mySwap(T&a,T&b)
{
    T temp=a;
    a=b;
    b=temp;
}

template <class T>
void mySort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            mySwap(arr[min], arr[i]);
        }
    }
}

template <class T>
void myPrint(T arr[],int len)
{

    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main(void)
{
    char chararr[]="lkjhgfdsa";
    mySort(chararr,sizeof(chararr)/sizeof(char));
    myPrint(chararr,sizeof(chararr)/sizeof(char));


    int intarr[]={25,26,67,37,5,42,64,27,534,234,574,326,723,6,43,4};
    mySort(intarr,sizeof(intarr)/sizeof(int));
    myPrint(intarr,sizeof(intarr)/sizeof(int));
    return 0;
}