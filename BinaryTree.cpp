#include "BinaryTree.h"
#include <iostream>

void BinaryTree::insert(TreeNode*& oldNode, TreeNode*& newNode)
{
    if (oldNode == nullptr) //at leaf of tree
    {
        oldNode = newNode;
    }
    else if (newNode->val < oldNode->val)
    {
        insert(oldNode->left, newNode);
    }
    else
    {
        insert(oldNode->right, newNode);
    }
}

void BinaryTree::insertNode(int num)
{
    TreeNode* node = new TreeNode{num, nullptr, nullptr};
    insert(_root, node);
}

void BinaryTree::displayInOrder(TreeNode* nodePtr) const
{
    if(nodePtr)
    {
        displayInOrder(nodePtr->left);
        std::cout << nodePtr->val << ", " << std::endl;
        displayInOrder(nodePtr->right);
    }
}

void BinaryTree::displayPreOrder(TreeNode* nodePtr) const
{
    if(nodePtr)
    {
        std::cout << nodePtr->val << ", " << std::endl;
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

void BinaryTree::displayPostOrder(TreeNode* nodePtr) const
{
    if(nodePtr)
    {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        std::cout << nodePtr->val << ", " << std::endl;
    }
}

bool BinaryTree::search(int val) const 
{   
    TreeNode* nodePtr = _root;

    while (nodePtr)
    {
        if(val == nodePtr->val)
        {
           return true; 
        } 
        else if (val < nodePtr->val)
        {
            nodePtr = nodePtr->left;
        }
        else
        {
            nodePtr = nodePtr->right; 
        }
    }
    return false;
}

void BinaryTree::makeDeletion(TreeNode*& nodePtr)
{
    TreeNode* tempNodePtr = nullptr;

    if (nodePtr == nullptr)
    {
        std::cout << "Unable to delete empty node" << std::endl;
    }
    else if (nodePtr->right == nullptr)
    {
        //reattach left
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;
        
        delete tempNodePtr;
    }
    else if (nodePtr->left == nullptr)
    {
        //reattach right
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        
        delete tempNodePtr;
    }
    else return;
}

void BinaryTree::deleteNode(int val, TreeNode*& nodePtr)
{
    if(val < nodePtr->val)
    {
        deleteNode(val, nodePtr->left);
    }
    else if(val > nodePtr->val)
    {
        deleteNode(val, nodePtr->right);
    }
    else
    {
        makeDeletion(nodePtr);
    }

}






// void BinaryTree::deleteNode(int val)
// {
//     TreeNode* nodePtr = _root;
//     TreeNode* prevNode = nullptr;

//     while (nodePtr)
//     {
//         if(val == nodePtr->val)
//         { 
//             // first check to see if left lower left can replace
//             if (nodePtr->left)
//             {
//                 (nodePtr->left)->right = nodePtr->right;

//                 if(nodePtr == _root)
//                 {
//                     _root = nodePtr->left;
//                 } 
//                 else
//                 {
//                     if (prevNode->left == nodePtr)
//                     {
//                         prevNode->left = nodePtr->left;
//                     }
//                     else
//                     {
//                         prevNode->right = nodePtr->left;
//                     }
//                 }
//             }

//             else if(nodePtr->right)
//             {
//                 if(nodePtr == _root)
//                 {
//                     _root = nodePtr->right;
//                 } 
//                 else
//                 {
//                     if (prevNode->left == nodePtr)
//                     {
//                         prevNode->left = nodePtr->right;
//                     }
//                     else
//                     {
//                         prevNode->right = nodePtr->right;
//                     }
//                 }
                
//             }
     
//           // (nodePtr->left)->right = nodePtr->right;

//             delete nodePtr;
//             nodePtr = nullptr;
           
//         } 
//         else if (val < nodePtr->val)
//         {
//             prevNode = nodePtr;
//             nodePtr = nodePtr->left;
//         }
//         else
//         {
//             prevNode = nodePtr;
//             nodePtr = nodePtr->right; 
//         }
//     }

// }