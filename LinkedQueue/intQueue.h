#ifndef INTQUEUE_H_INCLUDED
#define INTQUEUE_H_INCLUDED

typedef struct node {
    struct node *next;
    int data;
} Node;

void enqueueLinkedQ(int newItem);
int dequeueLinkedQ();
int peekLinkedQ();
void printLinkedQ();
void clearLinkedQ();

#endif // INTQUEUE_H_INCLUDED
