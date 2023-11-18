#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP
#include "tree_node.hpp"

class BinaryTree {
private:
    TreeNode* root;

    TreeNode* searchRecursively(TreeNode* current, int searchVal);

public:
    BinaryTree();

    BinaryTree(TreeNode* root);

    ~BinaryTree();

    BinaryTree(const BinaryTree& other);

    BinaryTree& operator=(const BinaryTree& other);

    TreeNode* getRoot();

    void setRoot(TreeNode* newRoot);

    void insert(int val);

    TreeNode* search(int val);

    void remove(int val);
};

#endif