#include <stdio.h>
#include <stdlib.h>
#include "intBST.h"
#include "queue.h"

BSTNode *tree;

int main() {

    //test functions on empty tree
    printf("-----  test functions on empty tree  -----");
    printf("\nlevel order: ");
    levelOrderTraversal(tree);
    printf("\npre-order: ");
    preOrderTraversal(tree);
    printf("\nin-order: ");
    inOrderTraversal(tree);
    printf("\npost-order: ");
    postOrderTraversal(tree);

    // add several items
    printf("\n\n-----  add items  -----");
    printf("\ninsert 29: ");
    tree = insertItemBST(tree, 29);
    printf("level order: ");
    levelOrderTraversal(tree);
    printf("\ninsert 35: ");
    tree = insertItemBST(tree, 35);
    printf("level order: ");
    levelOrderTraversal(tree);
    printf("\ninsert 17: ");
    tree = insertItemBST(tree, 17);
    printf("level order: ");
    levelOrderTraversal(tree);
    printf("\ninsert 41: ");
    tree = insertItemBST(tree, 41);
    printf("level order: ");
    levelOrderTraversal(tree);
    printf("\ninsert 19: ");
    tree = insertItemBST(tree, 19);
    printf("level order: ");
    levelOrderTraversal(tree);
    printf("\ninsert 32: ");
    tree = insertItemBST(tree, 32);
    printf("level order: ");
    levelOrderTraversal(tree);
    printf("\ninsert 8: ");
    tree = insertItemBST(tree, 8);
    printf("level order: ");
    levelOrderTraversal(tree);
    printf("\ninsert 23: ");
    tree = insertItemBST(tree, 23);
    printf("level order: ");
    levelOrderTraversal(tree);
    printf("\ninsert 31: ");
    tree = insertItemBST(tree, 31);
    printf("level order: ");
    levelOrderTraversal(tree);
    printf("\ninsert 27: ");
    tree = insertItemBST(tree, 27);
    printf("level order: ");
    levelOrderTraversal(tree);
    printf("\ninsert 18: ");
    tree = insertItemBST(tree, 18);
    printf("level order: ");
    levelOrderTraversal(tree);
    printf("\ninsert 37: ");
    tree = insertItemBST(tree, 37);
    printf("level order: ");
    levelOrderTraversal(tree);

    // test traversals
    printf("\n\n-----  test traversals  -----");
    printf("\nlevel order: ");
    levelOrderTraversal(tree);
    printf("\npre-order: ");
    preOrderTraversal(tree);
    printf("\nin-order: ");
    inOrderTraversal(tree);
    printf("\npost-order: ");
    postOrderTraversal(tree);

    // test others
    printf("\n\n-----  test other methods  -----");
    int height = getHeightBST(tree);
    printf("\nheight of tree: %d", height);

    // test removeItem
    printf("\n\n-----  test removeItem  -----");
    printf("\nremove 35: level order: ");
    tree = removeItemBST(tree, 35);
    levelOrderTraversal(tree);

    // test delete
    printf("\n\n-----  test delete  -----");
    printf("\ndelete tree: ");
    tree = deleteBST(tree);
    printf("level order: ");
    levelOrderTraversal(tree);

    return 0;
}
