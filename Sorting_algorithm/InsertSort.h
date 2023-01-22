#ifndef INSERTSORT_H
#define INSERTSORT_H

#include <vector>

class InsertSort
{
public:



    enum InsertSort_Mode
    {
        //希尔排序
        Shell,
        //二分（折半）插入排序
        Binary,
        //直接插入排序（交换）
        Direct_Another,
        //直接插入排序（插入）
        Direct
    };
   static void DirectInsertSort(std::vector<int> &a);
   static void DirectInsertSort_Another(std::vector<int> &a);
   static void BinaryInsertSort(std::vector<int> &a);
   static void ShellInsertSort(std::vector<int> &a);

    void operator()(std::vector<int> &a);

    InsertSort(enum InsertSort_Mode mode=Binary):Mode(mode){}
private:
    enum InsertSort_Mode Mode;

};

#endif // INSERTSORT_H
