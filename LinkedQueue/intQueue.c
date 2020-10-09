#include <stdio.h>
#include <stdlib.h>
#include "intQueue.h"

void printLinkedQ(IntegerQueue *q) {
    if (q->front == NULL) {
        printf("[ ] size: %d", q->size);
    } else {
        Node *temp = q->front;
        printf("[ %d", temp->data);
        while (temp->next != NULL) {
            temp = temp->next;
            printf(", %d", temp->data);
        }
        printf(" ] size: %d", q->size);
    }
}

void enqueueLinkedQ(int newItem, IntegerQueue *q) {
    Node *newNode = (Node *)malloc(sizeof(Node));
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

int peekLinkedQ(IntegerQueue *q) {
    if (q->size == 0) return -1;
    else return q->front->data;
}

int dequeueLinkedQ(IntegerQueue *q) {
    int itemToReturn = -1;
    if (q->size == 0) {
        return -1;
    } else if (q->size == 1) {
        itemToReturn = q->front->data;
        Node *nodeToFree = q->front;
        q->front = NULL;
        q->back = NULL;
        free(nodeToFree);
        q->size--;
    } else {
        itemToReturn = q->front->data;
        Node *nodeToFree = q->front;
        q->front = nodeToFree->next;
        nodeToFree->next = NULL;
        free(nodeToFree);
        q->size--;
    }
    return itemToReturn;
}

void clearLinkedQ(IntegerQueue *q) {
    if (q->size > 0) {
        while (q->front != NULL) {
            dequeueLinkedQ(q);
        }
    }
}
