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

    tree.remove(10);

    for (int value : values) {
        TreeNode* currentNode = tree.find(value);
        if (currentNode == nullptr) {
            continue;
        }
        TreeNode* left = currentNode->getLeft();
        TreeNode* right = currentNode->getRight();
        std::cout << "(v: [" << currentNode->getVal();
        if (left != nullptr) {
            std::cout << "], l: [" << left->getVal();
        }
        if (right != nullptr) {
            std::cout << "], r: [" << right->getVal();
        }
        std::cout << "])\n";
    }

    return 0;
}


