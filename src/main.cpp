#include <iostream>
#include "../include/binary_tree.hpp"
#include "../include/tree_node.hpp"

int main() {
    int values[] = { 10,1,11,2,45,37,5,98,4 };
    BinaryTree tree;


    for (int value : values) {
        tree.insert(value);
    }

    tree.remove(5);

    std::cout << tree.find(5)->getVal() << std::endl;

    for (int value : values) {
        std::cout << tree.find(value)->getVal() << std::endl;
    }

    return 0;
}