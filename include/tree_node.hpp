#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP

class TreeNode {
private:
    int val;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode();

    TreeNode(int val);

    ~TreeNode();

    TreeNode(const TreeNode& other);

    TreeNode& operator=(const TreeNode& other);

    int getVal();

    void setVal(int newVal);

    TreeNode* getLeft();

    void setLeft(TreeNode* newLeft);

    TreeNode* getRight();

    void setRight(TreeNode* newRight);
};


#endif