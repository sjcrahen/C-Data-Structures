#ifndef INTLINKEDLIST_H_INCLUDED
#define INTLINKEDLIST_H_INCLUDED

typedef struct node {
    struct node *next;
    struct node *previous;
    int data;
} Node;

typedef struct intLinkedList {
    Node *head;
    int size;
} IntLL;

void printLL(IntLL *list);
void insertAtEndLL(int newItem, IntLL *list);
int removeFromHeadLL(IntLL *list);
void clearLL(IntLL *list);
bool containsLL(int item, IntLL *list);
int getIndexLL(int item, IntLL *list);
void removeItemLL(int item, IntLL *list);
void sortLL(IntLL *list);

#endif // INTLINKEDLIST_H_INCLUDED
