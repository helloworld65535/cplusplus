
#include "InsertSort.h"

void InsertSort::DirectInsertSort(std::vector<int> &a)
{
    // 把无序部分的元素插入到有序部分
    //  - 有序部分默认有1个
    for (std::vector<int>::size_type i = 1; i < a.size(); i++)
    {
        // - 临时存储要插入的元素
        int element = a[i];

        // 在有序部分中找到该元素插入的位置
        // - 数组下标小于i的为有序部分
        // - 从有序部分第一个元素开始遍历
        // - 默认插入位置位插入元素的位置
        std::vector<int>::size_type insert_pos = i;
        for (std::vector<int>::size_type j = 0; j < i; j++)
        {

            // 比较方法
            // - 小的在前 ：升序
            if (element < a[j])
            {
                insert_pos = j;
                break;
            }

            // - 大的在前 ：降序
            /* if (element > a[j])
            {
                insert_pos = j;
                break;
            } */
        }
        // 进行插入操作

        // - 将插入位置的之后的所有有序元素都后移一位
        for (std::vector<int>::size_type j = i; j > insert_pos; j--)
        {
            a[j] = a[j - 1];
        }
        // - 将临时存储要插入的元素，赋值给插入位置
        a[insert_pos] = element;
    }
}

void InsertSort::DirectInsertSort_Another(std::vector<int> &a)
{
    // 把无序部分的元素插入到有序部分
    for (std::vector<int>::size_type i = 1; i < a.size(); i++)
    {
        // 有序部分从后往前，与待插入元素比较。
        for (std::vector<int>::size_type j = i; j > 0; j--)
        {
            // 如果待插入元素较小，交换他们。
            if (a[j] < a[j - 1])
            {
                std::swap(a[j], a[j - 1]);
            }
            // 否则说明待插入元素比有序部分剩下的元素都大，待插入元素插入完成。
            else
            {
                break;
            }
        }
    }
}

void InsertSort::BinaryInsertSort(std::vector<int> &a)
{
    // 把无序部分的元素插入到有序部分
    //  - 有序部分默认有1个
    for (std::vector<int>::size_type i = 1; i < a.size(); i++)
    {
        //要插入的元素比有序部分最大还要大，则跳过
        if (a[i] >= a[i - 1])
        {
            continue;
        }

        // - 临时存储要插入的元素
        int element = a[i];

        // 在有序部分中找到该元素插入的位置
        std::vector<int>::size_type insert_pos = i, left = 0, right = i - 1;
        while (left < right)
        {
            std::vector<int>::size_type mid = left + (right - left) / 2;
            if (element <= a[mid])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        insert_pos = left;
        // 进行插入操作

        // - 将插入位置的和之后的所有有序元素都后移一位
        for (std::vector<int>::size_type j = i; j > insert_pos; j--)
        {
            a[j] = a[j - 1];
        }

        // - 将临时存储要插入的元素，赋值给插入位置
        a[insert_pos] = element;
    }
}

void InsertSort::operator()(std::vector<int> &a)
{
    switch (Mode)
    {
    case Binary:
        BinaryInsertSort(a);
        break;
    case Direct_Another:
        DirectInsertSort(a);
        break;
    case Direct:
        DirectInsertSort(a);
        break;
    default:
        break;
    }
}
