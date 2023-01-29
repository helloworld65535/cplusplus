#ifndef SWAPSORT_H
#define SWAPSORT_H

#include <vector>

class SwapSort
{
public:
    enum SwapSort_Mode
    {
        // 冒泡排序
        Bubble,
        // 快速排序
        Quick,
    };

    static void BubbleSort(std::vector<int> &a);
    static void Quicksort(std::vector<int> &a);

    void operator()(std::vector<int> &a);
    SwapSort(enum SwapSort_Mode mode = Bubble) : Mode(mode) {}

private:
    enum SwapSort_Mode Mode;
};

#endif // SWAPSORT_H
