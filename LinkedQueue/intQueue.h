#ifndef INTQUEUE_H_INCLUDED
#define INTQUEUE_H_INCLUDED
#include "linkedListNodeInt.h"

typedef struct queue {
    Node *front;
    Node *back;
    int size;
} Queue;

void enqueueLinkedQ(int newItem, Queue *q);
int dequeueLinkedQ(Queue *q);
int peekLinkedQ(Queue *q);
void printLinkedQ(Queue *q);
void clearLinkedQ(Queue *q);

#endif // INTQUEUE_H_INCLUDED
