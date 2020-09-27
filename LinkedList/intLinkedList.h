#ifndef INTLINKEDLIST_H_INCLUDED
#define INTLINKEDLIST_H_INCLUDED

typedef struct node {
    struct node *next;
    struct node *previous;
    int data;
} Node;

void printLL();
void insertAtEndLL(int newItem);
int removeFromHeadLL();
void clearLL();
int containsLL(int item);
int getIndexLL(int item);
void removeItemLL(int item);
void sortLL();

#endif // INTLINKEDLIST_H_INCLUDED
