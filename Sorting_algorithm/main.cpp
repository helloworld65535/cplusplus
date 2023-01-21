#include <iostream>

#include <algorithm>
#include <ctime>
// #include <cstdlib>
#include "InsertSort.h"
#define log 1

int main(void)
{

    // SortCheck(InsertSort::BinaryInsertSort, true);
    std::vector<int> array;
    srand(time(0));
    for (int i = 0; i < 20; i++)
    {
        array.push_back((rand() % 201) - 100); // 随机添加[-100,100]范围内的数
    }
    if (log)
    {
        std::cout << "排序前：";
        std::for_each(array.begin(), array.end(), [](int i) -> void
                      { printf("%3d ", i); });
        std::cout << std::endl;
    }

    std::vector<int> check_array(array);
    std::sort(check_array.std::vector<int>::begin(), check_array.std::vector<int>::end());

    /* 排序操作 */
    // InsertSort i_sort(InsertSort::Binary);
    // i_sort(array);
    InsertSort(InsertSort::Binary)(array);

    if (log)
    {
        std::cout << "排序后：";
        std::for_each(array.begin(), array.end(), [](int i) -> void
                      { printf("%3d ", i); });
        std::cout << std::endl;
    }

    if (log)
    {
        std::cout << "  答案：";
        std::for_each(check_array.begin(), check_array.end(), [](int i) -> void
                      { printf("%3d ", i); });
        std::cout << std::endl;
    }
    if (check_array == array)
    {
        std::cout << "  正确" << std::endl;
    }
    // return (array == check_array);
    return 0;
}