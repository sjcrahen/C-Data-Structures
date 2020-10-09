#ifndef INTQUEUE_H_INCLUDED
#define INTQUEUE_H_INCLUDED

typedef struct node {
    struct node *next;
    int data;
} Node;

typedef struct intQueue {
    Node *front;
    Node *back;
    int size;
} IntegerQueue;

void enqueueLinkedQ(int newItem, IntegerQueue *q);
int dequeueLinkedQ(IntegerQueue *q);
int peekLinkedQ(IntegerQueue *q);
void printLinkedQ(IntegerQueue *q);
void clearLinkedQ(IntegerQueue *q);

#endif // INTQUEUE_H_INCLUDED
