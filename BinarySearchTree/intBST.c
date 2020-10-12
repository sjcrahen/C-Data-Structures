#include <stdio.h>
#include <stdlib.h>
#include "intBST.h"
#include "queue.h"

BSTNode * insertItemBST(BSTNode *tree, int newItem) {
    BSTNode *temp, *parent;
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->data = newItem;
    newNode->left = NULL;
    newNode->right = NULL;
    if (tree == NULL) {
        tree = newNode;
        tree->left = NULL;
        tree->right = NULL;
    } else {
        parent = NULL;
        temp = tree;
        while (temp != NULL) {
            parent = temp;
            if (newItem < temp->data)
                temp = temp->left;
            else
                temp = temp->right;

        }
        if (newItem < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
    }
    return tree;
}

void preOrderTraversal(BSTNode *tree) {
    if (tree != NULL) {
        printf("%d ", tree->data);
        preOrderTraversal(tree->left);
        preOrderTraversal(tree->right);
    }
}

void inOrderTraversal(BSTNode *tree) {
    if (tree != NULL) {
        inOrderTraversal(tree->left);
        printf("%d ", tree->data);
        inOrderTraversal(tree->right);
    }
}

void postOrderTraversal(BSTNode *tree) {
    if (tree != NULL) {
        postOrderTraversal(tree->left);
        postOrderTraversal(tree->right);
        printf("%d ", tree->data);
    }
}

void levelOrderTraversal(BSTNode *tree) {
    if (tree != NULL) {
        Queue queue, *q;
        queue.front = NULL;
        queue.back = NULL;
        queue.size = 0;
        q = &queue;

        enqueue(q, tree);
        while (q->size > 0) {
            BSTNode *node = dequeue(q);
            printf("%d ", node->data);
            if (node->left != NULL) {
                enqueue(q, node->left);
            }
            if (node->right != NULL) {
                enqueue(q, node->right);
            }
        }
    }
}

BSTNode * removeItemBST(BSTNode *tree, int itemToRemove) {
    BSTNode *nodeToRemove, *parent, *newChild, *parentOfSuccessor, *successor;

    // find node to remove
    parent = NULL;
    nodeToRemove = tree;
    while (nodeToRemove != NULL && itemToRemove != nodeToRemove->data) {
        parent = nodeToRemove;
        nodeToRemove = itemToRemove < nodeToRemove->data ? nodeToRemove->left : nodeToRemove->right;
    }
    if (nodeToRemove == NULL) {
        printf("%d is not in this tree\n", itemToRemove);
        return tree;
    }

    // locate new child node
    if (nodeToRemove->left == NULL) {
        newChild = nodeToRemove->right;
    } else if (nodeToRemove->right == NULL) {
        newChild = nodeToRemove->left;
    } else { // nodeToRemove has two children
        parentOfSuccessor = nodeToRemove;
        successor = nodeToRemove->right;
        while (successor->left != NULL) { // find successor
            parentOfSuccessor = successor;
            successor = successor->left;
        }
        // link nodes to replace node to remove
        if (parentOfSuccessor == nodeToRemove) {
            successor->left = nodeToRemove->left;
        } else {
            successor->left = nodeToRemove->left;
            parentOfSuccessor->left = successor->right;
            successor->right = nodeToRemove->right;
        }
        newChild = successor;
    }

    // set parent to point to newChild
    if (parent->left == nodeToRemove) {
        parent->left = newChild;
    } else {
        parent->right = newChild;
    }
    nodeToRemove->left = NULL;
    nodeToRemove->right = NULL;
    free(nodeToRemove);
    return tree;
}

int getHeightBST(BSTNode *tree) {
    if (tree == NULL) {
        return 0;
    } else {
        int leftTreeHeight = getHeightBST(tree->left);
        int rightTreeHeight = getHeightBST(tree->right);
        return 1 + (leftTreeHeight > rightTreeHeight ? leftTreeHeight : rightTreeHeight);
    }
}

BSTNode * deleteBST(BSTNode *tree) {
    if (tree != NULL) {
        deleteBST(tree->left);
        deleteBST(tree->right);
        tree = NULL;
        free(tree);
    }
}

void printTreeNode(BSTNode *node) {
    if (node == NULL)
        printf("\nNULL");
    else {
        printf("\nnode: ");
        printf("\ndata: %d", node->data);
        printf("\nleft: %s", node->left == NULL ? "NULL" : "notNULL");
        printf("\nright: %s", node->right == NULL ? "NULL" : "notNULL");
    }
}
