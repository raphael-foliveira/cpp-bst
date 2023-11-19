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

TreeNode* BinaryTree::deleteNode(TreeNode* root, int val) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->getVal() < val) {
        root->setRight(deleteNode(root->getRight(), val));
        return root;
    }
    if (root->getVal() > val) {
        root->setLeft(deleteNode(root->getLeft(), val));
        return root;
    }
    bool leftIsNull = root->getLeft() == nullptr;
    bool rightIsNull = root->getRight() == nullptr;
    if (leftIsNull && rightIsNull) {
        delete root;
        return nullptr;
    }
    if (leftIsNull) {
        TreeNode* temp = new TreeNode(*root->getRight());
        delete root;
        return temp;
    }
    if (rightIsNull) {
        TreeNode* temp = new TreeNode(*root->getLeft());
        delete root;
        return temp;
    }
    TreeNode* temp = findMin(root->getRight());
    root->setVal(temp->getVal());
    root->setRight(deleteNode(root->getRight(), temp->getVal()));
    return root;
}

TreeNode* BinaryTree::findMin(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->getLeft() != nullptr) {
        current = current->getLeft();
    }
    return current;
}
