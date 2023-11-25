#include <iostream>
#include "../include/binary_tree.hpp"
#include "../include/tree_node.hpp"


void printTree(BinaryTree* tree) {

}

int main() {
    int values[] = { 10,1,11,2,45,37,5,98,4 };
    BinaryTree tree;

    for (int value : values) {
        tree.insert(value);
    }
    tree.printInOrder();
    tree.printPreorder();
    tree.printPostorder();

    tree.remove(10);

    tree.printInOrder();
    tree.printPreorder();
    tree.printPostorder();

    return 0;
}


