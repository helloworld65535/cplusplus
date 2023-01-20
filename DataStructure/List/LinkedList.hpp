#pragma once

#include "AbstractList.hpp"

template <class DataType>
class LinkNode
{
private:
    DataType data;
    LinkNode<DataType> *next;
    LinkNode<DataType> *prev;

public:
    LinkNode(DataType data, LinkNode<DataType> *next = nullptr, LinkNode<DataType> *prev = nullptr) : data(data),
                                                                                                      next(next),
                                                                                                      prev(prev)
    {
    }
    ~LinkNode()
    {
        next = nullptr;
        prev = nullptr;
    }

    DataType getData() const
    {
        return data;
    }
    DataType *getDataPtr()
    {
        return &data;
    }

    void setData(DataType data)
    {
        LinkNode::data = data;
    }

    LinkNode<DataType> *getNext()
    {
        return next;
    }

    void setNext(LinkNode<DataType> *next)
    {
        LinkNode::next = next;
    }

    LinkNode<DataType> *getPrev() const
    {
        return prev;
    }

    void setPrev(LinkNode<DataType> *prev)
    {
        LinkNode::prev = prev;
    }
};

template <class DataType>
class LinkedList : public AbstractList<DataType>
{

private:
    LinkNode<DataType> *head;

    /**
     * @brief 删除当前节点和之后的所有节点
     * @param current 当前节点的指针引用
     */
    void DeleteAllNext(LinkNode<DataType> *current)
    {
        if (current == nullptr)
            return;

        if (current->getNext() != nullptr)
            DeleteAllNext(current->getNext());
        delete current;
    }

public:
    LinkedList()
    {
        head = nullptr;
        AbstractList<DataType>::size = 0;
    }

    ~LinkedList()
    {
        ClearList();
    }

    virtual void ClearList() override
    {
        DeleteAllNext(head);
        AbstractList<DataType>::size = 0;
    }
    virtual bool IsEmpty() override
    {
        return (AbstractList<DataType>::size == 0);
    }

    virtual int Length() override
    {
        return AbstractList<DataType>::size;
    }
    virtual DataType *Get(int i) override
    {
        if (i > AbstractList<DataType>::size)
            return nullptr;
        LinkNode<DataType> *node = head;
        while (--i)
        {
            node = node->getNext();
        }
        return head->getDataPtr();
    }

    virtual DataType *Locate(bool (*Compare)(const DataType &)) override
    {
        LinkNode<DataType> *node = head;
        while (node != nullptr)
        {
            if (Compare(node->getData()))
            {
                return node->getDataPtr();
            }
            node = node->getNext();
        }
        return nullptr;
    }

    virtual DataType *Prior(DataType *element) override
    {
        LinkNode<DataType> *node = head;
        while (node != nullptr)
        {
            if (node->getDataPtr() == element)
            {
                return node->getPrev()->getDataPtr();
            }
            node = node->getNext();
        }
        return nullptr;
    }

    virtual DataType *Next(DataType *element) override
    {
        LinkNode<DataType> *node = head;
        while (node != nullptr)
        {
            if (node->getDataPtr() == element)
            {
                return node->getNext()->getDataPtr();
            }
            node = node->getNext();
        }
        return nullptr;
    }

    /// @brief 在线性表第i个位置插入新的数据元素
    /// @param index 插入位置[1,length+1]
    /// @param data 新的数据元素
    virtual void Insert(int index, DataType data) override
    {
        if (index > AbstractList<DataType>::size + 1)
        {
            return;
        }
        if (head == nullptr)
        {
            head = new LinkNode<DataType>(data);
            ++AbstractList<DataType>::size;
        }
        else
        {
            LinkNode<DataType> *node = head;
            --index;
            while (--index)
            {
                node = node->getNext();
            }

            /* node <- newnode -> index_node */
            LinkNode<DataType> *newnode = new LinkNode<DataType>(data, node->getNext(), node);
            if (node->getNext())
            {
                node->getNext()->setPrev(newnode);
            }
            /* node -> newnode */
            node->setNext(newnode);
            ++AbstractList<DataType>::size;
        }
    }

    /**
     * @brief 删除线性表中第i个数据元素
     * @param index 删除位置[1,length]
     * @return 被删除的元素
     */
    virtual DataType Delete(int index) override
    {
        // 判断范围
        if (index < 1 || index > AbstractList<DataType>::size)
        {
            return 0;
        }
        else
        {
            // 找到node->deleteNode->deleteNextNode
            LinkNode<DataType> *node = head;
            --index;
            while (--index)
            {
                node = node->getNext();
            }

            LinkNode<DataType> *deletenode = node->getNext();
            /* node->deleteNextNode */
            if (node->getNext()->getNext())
            {
                /* node<-deleteNextNode */
                node->getNext()->getNext()->setPrev(node);
            }
            /* 设置 node->deleteNextNode */
            node->setNext(node->getNext()->getNext());

            // 删除操作
            DataType temp = deletenode->getData();
            delete deletenode;
            --AbstractList<DataType>::size;
            return temp;
        }
    }

    virtual void Traverse(void (*function)(const DataType &)) override
    {
        LinkNode<DataType> *node = head;
        while (node != nullptr)
        {
            function(node->getData());
            node = node->getNext();
        }
    }
};
