#pragma once
#include "AbstractList.hpp"

template <class DataType>
class ArrayList : public AbstractList<DataType>
{
private:
    DataType *array;
    int capacity;

    void SetCapacity()
    {
        if ((AbstractList<DataType>::size * 2) > capacity)
        {
            int temp_capacity = 2 * capacity;
            DataType *temp = new DataType[temp_capacity];
            for (int i = 0; i < AbstractList<DataType>::size; i++)
            {
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
            capacity = temp_capacity;
        }
        else if ((AbstractList<DataType>::size * 4) < capacity)
        {
            int temp_capacity = capacity / 2;
            DataType *temp = new DataType[temp_capacity];
            for (int i = 0; i < AbstractList<DataType>::size; i++)
            {
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
            capacity = temp_capacity;
        }
    }

public:
    ArrayList(int c = 10)
    {
        AbstractList<DataType>::size = 0;
        capacity = c * 2;
        array = new DataType[capacity];
    }

    void ClearList() override
    {
        if (array)
        {
            delete[] array;
        }
        AbstractList<DataType>::size = 0;
        capacity = 20;
        array = new DataType[capacity];
    }

    DataType *Get(int i) override
    {
        if (i < AbstractList<DataType>::size)
        {
            return &array[i];
        }
        return nullptr;
    }

    DataType *Locate(bool (*Compare)(const DataType &)) override
    {
        for (int i = 0; i < AbstractList<DataType>::size; i++)
        {
            if (Compare(array[i]))
            {
                return &array[i];
            }
        }
        return nullptr;
    }

    DataType *Prior(DataType *element) override
    {
        if (element != array)
        {
            for (int i = 0; i < AbstractList<DataType>::size; i++)
            {
                if ((&array[i + 1]) == element)
                    return &array[i];
            }
        }
        return nullptr;
    }

    DataType *Next(DataType *element) override
    {
        if (element != &array[AbstractList<DataType>::size - 1])
        {
            for (int i = 0; i < AbstractList<DataType>::size - 1; i++)
            {
                if ((&array[i]) == element)
                    return &array[i + 1];
            }
        }
        return nullptr;
    }

    void Insert(int index, DataType data) override
    {
        if (index < 1 || index > AbstractList<DataType>::size + 1)
            return;
        for (int i = AbstractList<DataType>::size; i > index; i--)
        {
            array[i] = array[i - 1];
        }
        array[index - 1] = data;
        ++AbstractList<DataType>::size;
        SetCapacity();
    }

    DataType Delete(int index) override
    {
        if (index < 1 || index > AbstractList<DataType>::size)
            return 0;
        DataType temp = array[index - 1];
        for (int i = index - 1; i < AbstractList<DataType>::size; ++i)
        {
            array[i] = array[i + 1];
        }
        --AbstractList<DataType>::size;
        SetCapacity();
        return temp;
    }

    void Traverse(void (*function)(const DataType &)) override
    {
        for (int i = 0; i < AbstractList<DataType>::size; i++)
        {
            function(array[i]);
        }
    }

    ~ArrayList() override
    {
        if (array)
        {
            delete[] array;
        }
    }
};