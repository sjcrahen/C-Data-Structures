#include <stdio.h>
#include <stdlib.h>
#include "intBST.h"
#include "queue.h"

void enqueue(Queue *q, BSTNode *newItem) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->data = newItem;
    newNode->next = NULL;
    if (q->size == 0) {
        q->front = newNode;
        q->back = newNode;
    } else {
        q->back->next = newNode;
        q->back = newNode;
    }
    q->size++;
}

BSTNode * dequeue(Queue *q) {
    BSTNode *nodeToReturn = NULL;
    if (q->size > 0) {
        nodeToReturn = q->front->data;
        QueueNode *nodeToFree = q->front;
        if (q->size == 1) {
            q->front = NULL;
            q->back = NULL;
        } else {
            q->front = q->front->next;
            nodeToFree->next = NULL;
        }
        free(nodeToFree);
        q->size--;
    }
    return nodeToReturn;
}
