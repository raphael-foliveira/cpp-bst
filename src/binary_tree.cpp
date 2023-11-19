#include <iostream>
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
    TreeNode* current = root;
    while (current != nullptr) {
        if (val < current->getVal()) {
            if (current->getLeft() == nullptr) {
                current->setLeft(new TreeNode(val));
                return;
            }
            current = current->getLeft();
        } else {
            if (current->getRight() == nullptr) {
                current->setRight(new TreeNode(val));
                return;
            }
            current = current->getRight();
        }
    }
}

TreeNode* BinaryTree::find(int val) {
    return searchNode(root, val);
}

void BinaryTree::remove(int val) {
    if (root == nullptr) {
        return;
    }
    TreeNode* current = root;

    while (current != nullptr) {
        TreeNode* currentLeft = current->getLeft();
        TreeNode* currentRight = current->getRight();
        std::cout << "current: " << current->getVal() << std::endl;

        if (currentLeft != nullptr && currentLeft->getVal() == val) {
            // delete node to the left
        }

        if (currentRight != nullptr && currentRight->getVal() == val) {
            // delete node to the right
        }

        if (current->getVal() < val) {
            current = currentRight;
        } else {
            current = currentLeft;
        }
    }

}

TreeNode* BinaryTree::getRoot() {
    return root;
}

void BinaryTree::setRoot(TreeNode* newRoot) {
    root = newRoot;
}

TreeNode* BinaryTree::searchNode(TreeNode* current, int searchVal) {
    if (current == nullptr) {
        return nullptr;
    }
    if (current->getVal() == searchVal) {
        return current;
    }
    if (searchVal < current->getVal()) {
        return searchNode(current->getLeft(), searchVal);
    }
    return searchNode(current->getRight(), searchVal);
}

TreeNode* BinaryTree::findMin(TreeNode* node) {
    while (node != nullptr && node->getLeft() != nullptr) {
        node = node->getLeft();
    }
    return node;
}