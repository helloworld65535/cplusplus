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

void SwapSort::Quicksort(std::vector<int> &a)
{
    
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
