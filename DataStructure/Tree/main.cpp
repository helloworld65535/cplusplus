#include <iostream>
#include "BinaryTree.hpp"

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
