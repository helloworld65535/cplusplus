#ifndef INSERTSORT_H
#define INSERTSORT_H

#include <vector>

class InsertSort
{
public:


    enum InsertSort_Mode
    {
        //二分
        Binary,
        Direct_Another,
        Direct
    };
    void DirectInsertSort(std::vector<int> &a);
    void DirectInsertSort_Another(std::vector<int> &a);
    void BinaryInsertSort(std::vector<int> &a);
    void operator()(std::vector<int> &a);

    InsertSort(enum InsertSort_Mode mode=Binary):Mode(mode){}
private:
    enum InsertSort_Mode Mode;

};

#endif // INSERTSORT_H
