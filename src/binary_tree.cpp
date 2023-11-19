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
        if (other.root != nullptr) {
            root = new TreeNode(*other.root);
        } else {
            root = nullptr;
        }
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

TreeNode* BinaryTree::deleteNode(TreeNode* node, int val) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->getVal() < val) {
        node->setRight(deleteNode(node->getRight(), val));
        return node;
    }
    if (node->getVal() > val) {
        node->setLeft(deleteNode(node->getLeft(), val));
        return node;
    }
    if (node->getLeft() == nullptr) {
        if (node->getRight() == nullptr) {
            delete node;
            return nullptr;
        }
        TreeNode* temp = new TreeNode(*node->getRight());
        delete node;
        return temp;
    }
    if (node->getRight() == nullptr) {
        TreeNode* temp = new TreeNode(*node->getLeft());
        delete node;
        return temp;
    }
    TreeNode* temp = findMin(node->getRight());
    node->setVal(temp->getVal());
    node->setRight(deleteNode(node->getRight(), temp->getVal()));
    return node;
}



TreeNode* BinaryTree::findMin(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->getLeft() != nullptr) {
        current = current->getLeft();
    }
    return current;
}
