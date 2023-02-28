#include <iostream>
#include "BinaryTree.hpp"

class BTree_char : public BinaryTree<char>
{
public: /*公共*/
    using TreeNode = BinaryTreeNode<char>;
    enum class CreateType
    {
        Preorder,/* 前序 */
    };
    BTree_char(CreateType);
    void createTreePreorder(TreeNode *&node)
    {
        char c;
        std::cin >> c;
        if ('#' == c)
        {
            node = nullptr;
        }
        else
        {
            node = new TreeNode(c);
            createTreePreorder(node->left_);
            createTreePreorder(node->right_);
        }
    }

    void createTreeInorder(TreeNode *&node)
    {
        char c;
        std::cin >> c;
        if ('#' == c)
        {
            node = nullptr;
        }
        else
        {
            createTreeInorder(node->left_);
            node = new TreeNode(c);
            createTreeInorder(node->right_);
        }
    }
};
/*
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

    t.preorderTraversal([](int &elem) -> void
                        { std::cout << elem << " "; });
    std::cout << std::endl;
    t.postorderTraversal([](int &elem) -> void
                         { std::cout << elem << " "; });

    return 0;
}
*/
int main(void)
{
    BTree_char *t = new BTree_char(BTree_char::CreateType::Preorder);
    t->preorderTraversal([](char &i) -> void
                        { std::cout << i << " "; });
    t->postorderTraversal([](char &i) -> void
                        { std::cout << i << " "; });
    return 0;
}

BTree_char::BTree_char(CreateType type)
{
    switch (type)
    {
    case CreateType::Preorder:
        createTreePreorder(root_);
        break;

    default:
        break;
    }
}
