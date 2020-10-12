#ifndef INTBST_H_INCLUDED
#define INTBST_H_INCLUDED

// BST Node
typedef struct bstNode {
    struct bstNode *left;
    struct bstNode *right;
    int data;
} BSTNode;

BSTNode * insertItemBST(BSTNode *tree, int newItem);
void preOrderTraversal(BSTNode *tree);
void inOrderTraversal(BSTNode *tree);
void postOrderTraversal(BSTNode *tree);
void levelOrderTraversal(BSTNode *tree);
BSTNode * removeItemBST(BSTNode *tree, int itemToRemove);
int getHeightBST(BSTNode *tree);
BSTNode * deleteBST(BSTNode *tree);
void printTreeNode(BSTNode *node);

#endif // INTBST_H_INCLUDED
