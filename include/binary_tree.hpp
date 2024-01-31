#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP
#include "tree_node.hpp"

class BinaryTree
{
private:
    TreeNode* root;

    TreeNode* searchNode(TreeNode* current, int searchVal);

    TreeNode* findMin(TreeNode* node);

    TreeNode* deleteNode(TreeNode* node, int val);

    void printInOrder(TreeNode* node);

    void printPreorder(TreeNode* node);

    void printPostorder(TreeNode* node);

public:
    BinaryTree();

    BinaryTree(TreeNode* root);

    ~BinaryTree();

    BinaryTree(const BinaryTree& other);

    void printInOrder();

    void printPreorder();

    void printPostorder();

    BinaryTree& operator=(const BinaryTree& other);

    TreeNode* getRoot();

    void setRoot(TreeNode* newRoot);

    void insert(int val);

    TreeNode* find(int val);

    void remove(int val);
};

#endif