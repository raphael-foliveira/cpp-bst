#include "../include/binary_tree.hpp"
#include "../include/tree_node.hpp"

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::BinaryTree(TreeNode* root) : root(root) {}

BinaryTree::~BinaryTree() {
    delete root;
}

BinaryTree::BinaryTree(const BinaryTree& other) : root(other.root) {
    root = new TreeNode(*other.root);
}

BinaryTree& BinaryTree::operator=(const BinaryTree& other) {
    if (this != &other) {
        root = new TreeNode(*other.root);
    }
    return *this;
}

void BinaryTree::insert(int val) {
    if (root == nullptr) {
        root = new TreeNode(val);
        return;
    }
    TreeNode* curr = root;
    while (curr != nullptr) {
        if (val < curr->getVal()) {
            if (curr->getLeft() == nullptr) {
                curr->setLeft(new TreeNode(val));
                return;
            }
            curr = curr->getLeft();
        } else {
            if (curr->getRight() == nullptr) {
                curr->setRight(new TreeNode(val));
                return;
            }
            curr = curr->getRight();
        }
    }
}

TreeNode* BinaryTree::search(int val) {
    return searchRecursively(root, val);
}

void BinaryTree::remove(int val) {}

TreeNode* BinaryTree::getRoot() {
    return root;
}

void BinaryTree::setRoot(TreeNode* newRoot) {
    root = newRoot;
}

TreeNode* BinaryTree::searchRecursively(TreeNode* current, int searchVal) {
    if (current == nullptr) {
        return nullptr;
    }
    if (current->getVal() == searchVal) {
        return current;
    }
    if (searchVal < current->getVal()) {
        return searchRecursively(current->getLeft(), searchVal);
    }
    return searchRecursively(current->getRight(), searchVal);
}