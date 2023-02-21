#include <iostream>
#include <vector>
#include <queue>
template <class ElemType>
class BinaryTreeNode
{
public:
    ElemType elem_;
    BinaryTreeNode *left_, *right_;
    BinaryTreeNode(ElemType elem, BinaryTreeNode *left = 0, BinaryTreeNode *right = 0)
        : elem_(elem), left_(left), right_(right) {}
};

template <class ElemType>
class BinaryTree
{
public: /*公共*/
    BinaryTree();
    ~BinaryTree();

    bool empty();
    void add(ElemType elem);
    BinaryTreeNode<ElemType> *find(ElemType elem);
    BinaryTreeNode<ElemType> *root_;

protected: /*保护*/
    unsigned number_;

private: /*私有*/
};

int main(void)
{
    // BinaryTreeNode<int> *node = new BinaryTreeNode(2);
    BinaryTree<int> t;
    t.add(5);
    t.add(1);
    t.add(9);
    t.add(-1);
    t.add(2);
    t.add(7);
    t.add(10);

    return 0;
}

template <class ElemType>
BinaryTree<ElemType>::BinaryTree()
{
    root_ = nullptr;
    number_ = 0;
}

template <class ElemType>
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

template <class ElemType>
bool BinaryTree<ElemType>::empty()
{
    return root_ == nullptr;
}

template <class ElemType>
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

template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::find(ElemType elem)
{
    if (root_->elem_ == elem)
        return root_;
    return nullptr;
}
