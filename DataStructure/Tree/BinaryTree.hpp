#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <initializer_list>

template <typename ElemType>
struct BinaryTreeNode
{
    ElemType elem_;
    BinaryTreeNode *left_, *right_;
    BinaryTreeNode(ElemType elem, BinaryTreeNode *left = 0, BinaryTreeNode *right = 0)
        : elem_(elem), left_(left), right_(right) {}
};

template <typename ElemType>
class BinaryTree
{
public: /*公共*/
    enum class CreateBTree
    {
        Preorder,
    };
    BinaryTree();
    
    ~BinaryTree();

    /**
     * @brief 二叉树是否为空
     * @return 二叉树是否为空
     */
    virtual bool empty();

    /**
     * @brief 添加元素
     * @param elem 要添加的元素
     */
    virtual void add(ElemType elem);

    /**
     * @brief 先序遍历
     * @param func 操作
     */
    virtual void preorderTraversal(void (*func)(ElemType &elem));

    /**
     * @brief 中序遍历
     * @param func 操作
     */
    virtual void inorderTraversal(void (*func)(ElemType &elem));

    /**
     * @brief 后序遍历
     * @param func 操作
     */
    virtual void postorderTraversal(void (*func)(ElemType &elem));

protected: /*保护*/
    unsigned number_;
    BinaryTreeNode<ElemType> *root_;

private: /*私有*/
};

#include <vector>
#include <queue>
#include <stack>

template <typename ElemType>
BinaryTree<ElemType>::BinaryTree()
{
    root_ = nullptr;
    number_ = 0;
}


template <typename ElemType>
BinaryTree<ElemType>::~BinaryTree()
{
    /* 层序遍历的方法，将所有节点添加到容器vector中，然后统一delete */
    std::queue<BinaryTreeNode<ElemType> *> nodeQueue;
    std::vector<BinaryTreeNode<ElemType> *> nodeVector;
    if (!empty())
        nodeQueue.push(root_);
    while (!nodeQueue.empty())
    {
        BinaryTreeNode<ElemType> *temp = nodeQueue.front();
        nodeQueue.pop();
        nodeVector.push_back(temp);
        if (temp->left_ != nullptr)
            nodeQueue.push(temp->left_);
        if (temp->right_ != nullptr)
            nodeQueue.push(temp->right_);
    }
    for (auto i = nodeVector.begin(); i != nodeVector.end(); ++i)
    {
        delete (*i);
        (*i) = nullptr;
    }
}

template <typename ElemType>
bool BinaryTree<ElemType>::empty()
{
    return root_ == nullptr;
}

template <typename ElemType>
void BinaryTree<ElemType>::add(ElemType elem)
{
    BinaryTreeNode<ElemType> *node = new BinaryTreeNode<ElemType>(elem);
    if (empty())
    {
        root_ = node;
    }
    else
    {
        // addNode(node);
        BinaryTreeNode<ElemType> *t = root_;
        while (t)
        {
            if (elem > t->elem_)
            {
                if (t->right_ == nullptr)
                {
                    t->right_ = node;
                    break;
                }
                else
                {
                    t = t->right_;
                }
            }
            else
            {
                if (t->left_ == nullptr)
                {
                    t->left_ = node;
                    break;
                }
                else
                {
                    t = t->left_;
                }
            }
        }
    }
    ++number_;
}

template <typename ElemType>
void BinaryTree<ElemType>::preorderTraversal(void (*func)(ElemType &elem))
{
    /*
        root_ 入栈
        循环：
            出栈
            right 入栈
            left 入栈
     */
    if (empty())
        return;
    std::stack<BinaryTreeNode<ElemType> *> nodeStack;
    nodeStack.push(root_);
    while (!nodeStack.empty())
    {
        BinaryTreeNode<ElemType> *t = nodeStack.top();
        nodeStack.pop();
        if (t == nullptr)
            continue;
        func(t->elem_);
        nodeStack.push(t->right_);
        nodeStack.push(t->left_);
    }
}

template <typename ElemType>
void BinaryTree<ElemType>::inorderTraversal(void (*func)(ElemType &elem))
{
    /*
        current=root
        循环： current不为null 或 Stack不为空
            将有效的 current 和 current的所有左节点 入栈
            出栈
            current=right
     */
    if (empty())
        return;
    std::stack<BinaryTreeNode<ElemType> *> nodeStack;
    BinaryTreeNode<ElemType> *current = root_;
    while (current != nullptr || !nodeStack.empty())
    {
        while (current)
        {
            nodeStack.push(current);
            current = current->left_;
        }
        BinaryTreeNode<ElemType> *t = nodeStack.top();
        func(t->elem_);
        nodeStack.pop();
        current = t->right_;
    }
}

template <typename ElemType>
void BinaryTree<ElemType>::postorderTraversal(void (*func)(ElemType &elem))
{
    /*
        current=root
        prev=null
        循环： current不为null 或 Stack不为空
            将有效的 current 和 current的所有左节点 入栈

            if Stack栈顶 为空 或者为prev
                prev=出栈
            else
                current=栈顶 right
    */
    if (empty())
        return;
    std::stack<BinaryTreeNode<ElemType> *> nodeStack;
    BinaryTreeNode<ElemType> *current = root_, *prev = nullptr;
    while (current != nullptr || !nodeStack.empty())
    {
        while (current)
        {
            nodeStack.push(current);
            current = current->left_;
        }
        current = nodeStack.top();
        if (current->right_ == nullptr || current->right_ == prev)
        {
            nodeStack.pop();

            func(current->elem_);
            prev = current;
            current = nullptr;
        }
        else
        {
            current = current->right_;
        }
    }
}

#endif // BINARYTREE_HPP
