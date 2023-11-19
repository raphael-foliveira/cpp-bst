#include "../include/tree_node.hpp"

TreeNode::TreeNode() : left(nullptr), right(nullptr), val(0) {}

TreeNode::TreeNode(int val) : left(nullptr), right(nullptr), val(val) {}

TreeNode::~TreeNode() {
    delete left;
    delete right;
}

TreeNode::TreeNode(const TreeNode& other) {
    val = other.val;
    if (other.right != nullptr) {
        right = new TreeNode(*other.right);
    } else {
        right = nullptr;
    }
    if (other.left != nullptr) {
        left = new TreeNode(*other.left);
    } else {
        left = nullptr;
    }
}

TreeNode& TreeNode::operator=(const TreeNode& other) {
    if (this != &other) {
        val = other.val;
        if (other.right != nullptr) {
            right = new TreeNode(*other.right);
        } else {
            right = nullptr;
        }
        if (other.left != nullptr) {
            left = new TreeNode(*other.left);
        } else {
            left = nullptr;
        }
    }
    return *this;
}

int TreeNode::getVal() {
    return val;
}

void TreeNode::setVal(int newVal) {
    val = newVal;
}

TreeNode* TreeNode::getLeft() {
    return left;
}

void TreeNode::setLeft(TreeNode* newLeft) {
    left = newLeft;
}

TreeNode* TreeNode::getRight() {
    return right;
}

void TreeNode::setRight(TreeNode* newRight) {
    right = newRight;
}

