#pragma once

template <class DataType>
class AbstractList
{

protected:
    DataType *array;
    int size;

public:
    /* //CPP无虚构造函数
        /// @brief 构建一个空的线性表
        virtual AbstractList()
         */
    /// @brief 销毁线性表
    virtual ~AbstractList() {}

    /// @brief 将线性表重置为空表
    virtual void ClearList() = 0;

    /// @brief 线性表是否为空
    /// @return 真假
    virtual bool IsEmpty() = 0;

    /// @brief 返回线性表中的元素个数
    /// @return 线性表中的元素个数
    virtual int Length() = 0;

    /// @brief 返回线性表中第i个数据元素的值
    /// @param i [1,length]
    /// @return 第i个数据元素的指针
    virtual DataType *Get(int i) = 0;

    /// @brief 返回线性表中第一个满足Compare函数的元素
    /// @param Compare bool (*Compare)(const DataType &)
    /// @return 第一个满足Compare函数的元素的!指针!,若没有返回nullptr
    virtual DataType *Locate(bool (*Compare)(const DataType &)) = 0;

    /// @brief 返回当前元素的前驱元素
    /// @param element 当前元素的指针
    /// @return 返回前驱元素，若没有返回nullptr
    virtual DataType *Prior(DataType *element) = 0;

    /// @brief 返回当前元素的后继元素
    /// @param element 当前元素的指针
    /// @return 返回后继元素，若没有返回nullptr
    virtual DataType *Next(DataType *element) = 0;

    /// @brief 在线性表第i个位置插入新的数据元素
    /// @param index 插入位置[1,length+1]
    /// @param data 新的数据元素
    virtual void Insert(int index, DataType data) = 0;

    /// @brief 删除线性表中第i个数据元素
    /// @param index 删除位置[1,length]
    /// @return 被删除的元素
    virtual DataType Delete(int index) = 0;

    /// @brief 遍历线性表，对每个元素执行function操作
    /// @param function void (*function)(const DataType &)
    virtual void Traverse(void (*function)(const DataType &)) = 0;
};