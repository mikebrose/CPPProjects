#ifndef BINARY_TREE_H
#define BINARY_TREE_H

class BinaryTree
{
private:
    struct TreeNode
    {
        int val;
        TreeNode* left;
        TreeNode* right;
    };

    TreeNode* _root;
    
    void insert(TreeNode*& oldNode, TreeNode*& newNode);
    void displayInOrder(TreeNode* nodePtr) const;
    void displayPreOrder(TreeNode* nodePtr) const;
    void displayPostOrder(TreeNode* nodePtr) const;
    void deleteNode(int num, TreeNode*& nodePtr); 
    void makeDeletion(TreeNode*& nodePtr);  

public:

    BinaryTree() : _root{nullptr} { }
    ~BinaryTree()
    {
        // Need to implement
    }
    
    void insertNode(int num);
    void displayInOrder() const
    {
        displayInOrder(_root);
    };
    void displayPreOrder() const
    {
        displayPreOrder(_root);
    }
    void displayPostOrder() const
    {
        displayPostOrder(_root);
    }

    void remove(int val)
    {
        deleteNode(val, _root);
    }

    bool search(int val) const;
};

#endif