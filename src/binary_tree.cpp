#include "../include/binary_tree.hpp"
#include "../include/tree_node.hpp"

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::BinaryTree(TreeNode* root) : root(root) {}

BinaryTree::~BinaryTree() {
    delete root;
}

BinaryTree::BinaryTree(const BinaryTree& other) : root(other.root) {
    if (other.root != nullptr) {
        root = new TreeNode(*other.root);
    } else {
        root = nullptr;
    }
}

BinaryTree& BinaryTree::operator=(const BinaryTree& other) {
    if (this != &other) {
        root = other.root == nullptr ? nullptr : new TreeNode(*other.root);
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
    deleteNode(root, val);
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

TreeNode* BinaryTree::deleteNode(TreeNode* stRoot, int val) {
    if (stRoot == nullptr) {
        return nullptr;
    }
    if (stRoot->getVal() < val) {
        stRoot->setRight(deleteNode(stRoot->getRight(), val));
        return stRoot;
    }
    if (stRoot->getVal() > val) {
        stRoot->setLeft(deleteNode(stRoot->getLeft(), val));
        return stRoot;
    }
    bool leftIsNull = stRoot->getLeft() == nullptr;
    bool rightIsNull = stRoot->getRight() == nullptr;
    if (leftIsNull && rightIsNull) {
        delete stRoot;
        return nullptr;
    }
    if (leftIsNull) {
        TreeNode* temp = new TreeNode(*stRoot->getRight());
        delete stRoot;
        return temp;
    }
    if (rightIsNull) {
        TreeNode* temp = new TreeNode(*stRoot->getLeft());
        delete stRoot;
        return temp;
    }
    TreeNode* temp = findMin(stRoot->getRight());
    stRoot->setVal(temp->getVal());
    stRoot->setRight(deleteNode(stRoot->getRight(), temp->getVal()));
    return stRoot;
}

TreeNode* BinaryTree::findMin(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->getLeft() != nullptr) {
        current = current->getLeft();
    }
    return current;
}
