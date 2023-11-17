#include "../include/binary_tree.hpp"
#include "../include/tree_node.hpp"

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::BinaryTree(TreeNode* root) : root(root) {}

BinaryTree::~BinaryTree() {
    delete root;
}

BinaryTree::BinaryTree(const BinaryTree& other) : root(other.root) {}

BinaryTree& BinaryTree::operator=(const BinaryTree& other) {
    if (this != &other) {
        root = other.root;
    }
    return *this;
}

TreeNode* BinaryTree::getRoot() {
    return root;
}

void BinaryTree::setRoot(TreeNode* newRoot) {
    root = newRoot;
}

