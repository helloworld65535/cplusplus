#include "SwapSort.h"

void SwapSort::BubbleSort(std::vector<int> &a)
{
    // 将最大的元素交换到未排序部分尾部
    for (std::vector<int>::size_type i = 0; i < a.size() - 1; i++)
    {
        for (std::vector<int>::size_type j = 0; j < a.size() - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                std::swap(a[j], a[j + 1]);
            }
        }
    }
}

void SwapSort::QuickSort(std::vector<int> &a)
{
    QuickSortHelper(a, 0, a.size() - 1);
}

void SwapSort::operator()(std::vector<int> &a)
{
    switch (Mode)
    {
    case Bubble:
        BubbleSort(a);
        break;
    default:
        break;
    }
}

void SwapSort::QuickSortHelper(std::vector<int> &a, int begin, int end)
{
    if(begin > end)
        return;
    int tmp = a[begin];
    int i = begin;
    int j = end;
    while(i != j){
        while(a[j] >= tmp && j > i)
            j--;
        while(a[i] <= tmp && j > i)
            i++;
        if(j > i){
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    a[begin] = a[i];
    a[i] = tmp;
    QuickSortHelper(a, begin, i-1);
    QuickSortHelper(a, i+1, end);
}
