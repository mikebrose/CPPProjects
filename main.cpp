#include <iostream>
#include "BinaryTree.h"

int main() {
    std::cout << "Hello" << std::endl;
    BinaryTree tree;
    tree.insertNode(6);
    tree.insertNode(3);
    tree.insertNode(1);
    tree.insertNode(2);
    tree.insertNode(2);
    tree.insertNode(3);
    tree.insertNode(12);
    tree.insertNode(10);
    tree.insertNode(13);
    tree.insertNode(15);
    tree.remove(1);
    
    tree.search(7);
    return 0;
}


//                      6
//                /           \
//            3                  12
//       /       \             /       \
//  1               3       10          13
//     \                                  \
//      2                                   15
//        \
//         2        