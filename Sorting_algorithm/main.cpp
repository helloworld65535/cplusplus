#include <iostream>

#include <algorithm>
#include <ctime>
// #include <cstdlib>
#include "InsertSort.h"
#include "SwapSort.h"

bool CheckSort(void (*SortFunc)(std::vector<int> &), bool Log)
{

    std::vector<int> array;
    srand((unsigned int)time(0));
    for (int i = 0; i < 20; i++)
    {
        array.push_back((rand() % 201) - 100); // ������[-100,100]��Χ�ڵ���
    }
    if (Log)
    {
        std::cout << "����ǰ��";
        std::for_each(array.begin(), array.end(), [](int i) -> void
                      { printf("%3d ", i); });
        std::cout << std::endl;
    }

    std::vector<int> check_array(array);
    std::sort(check_array.std::vector<int>::begin(), check_array.std::vector<int>::end());

    /* ������� */
    // InsertSort i_sort(InsertSort::Binary);
    // i_sort(array);
    SortFunc(array);

    if (Log)
    {
        std::cout << "�����";
        std::for_each(array.begin(), array.end(), [](int i) -> void
                      { printf("%3d ", i); });
        std::cout << std::endl;

        std::cout << "  �𰸣�";
        std::for_each(check_array.begin(), check_array.end(), [](int i) -> void
                      { printf("%3d ", i); });
        std::cout << std::endl;
        if (check_array == array)
        {
            std::cout << "  ��ȷ" << std::endl;
        }
    }

    return (array == check_array);
}

int main(void)
{
    bool TestResult = (CheckSort(SwapSort::QuickSort, true));
    std::cout << "���Խ����" << (TestResult ? "��ȷ" : "����") << std::endl;

    return 0;
}