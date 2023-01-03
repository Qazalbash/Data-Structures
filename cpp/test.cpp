#include <cstdlib>
#include <iostream>

#include "AVL_tree.hpp"

int main() {
    srand(time(0));

    AVLTree<int> bst;

    // for (int i = 0; i < 10; ++i) bst.insert(rand() % 10);

    bst.insert(12);
    bst.insert(11);
    bst.insert(13);

    // bst.inorder();

    std::cout << bst << std::endl;

    return 0;
}