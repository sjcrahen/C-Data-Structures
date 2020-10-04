#include <stdio.h>
#include <stdlib.h>
#include "intQueue.h"

Node *front = NULL;
Node *back = NULL;
int size = 0;

void printLinkedQ() {
    if (front == NULL) {
        printf("[ ] size: %d", size);
    } else {
        Node *temp = front;
        printf("[ %d", temp->data);
        while (temp->next != NULL) {
            temp = temp->next;
            printf(", %d", temp->data);
        }
        printf(" ] size: %d", size);
    }
}

void enqueueLinkedQ(int newItem) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = newItem;
    newNode->next = NULL;
    if (size == 0) {
        front = newNode;
        back = newNode;
    } else {
        back->next = newNode;
        back = newNode;
    }
    size++;
}

int peekLinkedQ() {
    if (size == 0) return -1;
    else return front->data;
}

int dequeueLinkedQ() {
    int itemToReturn = -1;
    if (size == 0) {
        return -1;
    } else if (size == 1) {
        itemToReturn = front->data;
        Node *nodeToFree = front;
        front = NULL;
        back = NULL;
        free(nodeToFree);
        size--;
    } else {
        itemToReturn = front->data;
        Node *nodeToFree = front;
        front = nodeToFree->next;
        nodeToFree->next = NULL;
        free(nodeToFree);
        size--;
    }
    return itemToReturn;
}

void clearLinkedQ() {
    if (size > 0) {
        while (front != NULL) {
            dequeueLinkedQ();
        }
    }
}
