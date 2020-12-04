#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "intBST.h"

// wrapper for use with Queue
typedef struct queueNode {
    BSTNode *data;
    struct queueNode *next;
} QueueNode;

// Queue
typedef struct queue {
    QueueNode *front;
    QueueNode *back;
    int size;
} Queue;

void enqueue(Queue *q, BSTNode *newNode);
BSTNode * dequeue(Queue *q);

#endif // QUEUE_H_INCLUDED
