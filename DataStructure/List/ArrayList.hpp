#pragma once
#include "AbstractList.hpp"

template <class DataType>
class ArrayList : public AbstractList<DataType>
{
private:
    int capacity;

    void SetCapacity()
    {
        if ((AbstractList<DataType>::size * 2) > capacity)
        {
            int temp_capacity = 2 * capacity;
            DataType *temp = new DataType[temp_capacity];
            for (int i = 0; i < AbstractList<DataType>::size; i++)
            {
                temp[i] = AbstractList<DataType>::array[i];
            }
            delete[] AbstractList<DataType>::array;
            AbstractList<DataType>::array = temp;
            capacity = temp_capacity;
        }
        else if ((AbstractList<DataType>::size * 4) < capacity)
        {
            int temp_capacity = capacity / 2;
            DataType *temp = new DataType[temp_capacity];
            for (int i = 0; i < AbstractList<DataType>::size; i++)
            {
                temp[i] = AbstractList<DataType>::array[i];
            }
            delete[] AbstractList<DataType>::array;
            AbstractList<DataType>::array = temp;
            capacity = temp_capacity;
        }
    }

public:
    ArrayList(int c = 10)
    {
        AbstractList<DataType>::size = 0;
        capacity = c * 2;
        AbstractList<DataType>::array = new DataType[capacity];
    }

    void ClearList() override
    {
        if (AbstractList<DataType>::array)
        {
            delete[] AbstractList<DataType>::array;
        }
        AbstractList<DataType>::size = 0;
        capacity = 20;
        AbstractList<DataType>::array = new DataType[capacity];
    }

    bool IsEmpty() override
    {
        return (AbstractList<DataType>::size == 0);
    }

    int Length() override
    {
        return AbstractList<DataType>::size;
    }

    DataType *Get(int i) override
    {
        if (i < AbstractList<DataType>::size)
        {
            return &AbstractList<DataType>::array[i];
        }
        return nullptr;
    }

    DataType *Locate(bool (*Compare)(const DataType &)) override
    {
        for (int i = 0; i < AbstractList<DataType>::size; i++)
        {
            if (Compare(AbstractList<DataType>::array[i]))
            {
                return &AbstractList<DataType>::array[i];
            }
        }
        return nullptr;
    }

    DataType *Prior(DataType *element) override
    {
        if (element != AbstractList<DataType>::array)
        {
            for (int i = 0; i < AbstractList<DataType>::size; i++)
            {
                if ((&AbstractList<DataType>::array[i + 1]) == element)
                    return &AbstractList<DataType>::array[i];
            }
        }
        return nullptr;
    }

    DataType *Next(DataType *element) override
    {
        if (element != &AbstractList<DataType>::array[AbstractList<DataType>::size - 1])
        {
            for (int i = 0; i < AbstractList<DataType>::size - 1; i++)
            {
                if ((&AbstractList<DataType>::array[i]) == element)
                    return &AbstractList<DataType>::array[i + 1];
            }
        }
        return nullptr;
    }

    void Insert(int index, DataType data) override
    {
        if (index < 1 || index > AbstractList<DataType>::size + 1)
            return;
        for (int i = AbstractList<DataType>::size; i > i; ++i)
        {
            AbstractList<DataType>::array[i] = AbstractList<DataType>::array[i - 1];
        }
        AbstractList<DataType>::array[index - 1] = data;
        AbstractList<DataType>::size++;
        SetCapacity();
    }

    DataType Delete(int index) override
    {
        if (index < 1 || index > AbstractList<DataType>::size)
            return NULL;
        DataType temp = AbstractList<DataType>::array[index - 1];
        for (int i = index - 1; i < AbstractList<DataType>::size; ++i)
        {
            AbstractList<DataType>::array[i] = AbstractList<DataType>::array[i + 1];
        }
        AbstractList<DataType>::size--;
        SetCapacity();
        return temp;
    }

    void Traverse(void (*function)(const DataType &)) override
    {
        for (int i = 0; i < AbstractList<DataType>::size; i++)
        {
            function(AbstractList<DataType>::array[i]);
        }
    }

    ~ArrayList() override
    {
        if (AbstractList<DataType>::array)
        {
            delete[] AbstractList<DataType>::array;
        }
    }
};