#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "intLinkedList.h"

Node *head = NULL;
int size = 0;

void printLL() {
    if (size == 0) printf("List: [ ] size: %d", size);
    else {
        Node *temp = head;
        printf("List: [ %d", temp->data);
        while (temp->next != NULL) {
            temp = temp->next;
            printf(", %d", temp->data);
        }
        printf(" ] size: %d", size);
    }
}

void insertAtEndLL(int newItem) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = newItem;
    newNode->next = NULL;
    if (size == 0) {
        head = newNode;
        newNode->previous = NULL;
    } else {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->previous = temp;
    }
    size++;
}

int removeFromHeadLL() {
    int item = -1;
    if (size == 0) {
        printf("Cannot remove from an empty list");
    } else {
        item = head->data;
        Node *temp = head;
        if (head->next == NULL) {
            head = NULL;
        } else {
            head = head->next;
            head->previous = NULL;
        }
        free(temp);
        size--;
    }
    return item;
}

void removeItemLL(int item) {
    Node *nodeToRemove = head;
    while (nodeToRemove != NULL && nodeToRemove->data != item) {
        nodeToRemove = nodeToRemove->next;
    }
    if (nodeToRemove == NULL) {
        printf("This list DOES NOT contain %d", item);
    } else if (nodeToRemove == head) {
        removeFromHeadLL();
        printf("%d was removed from the list", item);
    } else {
        if (nodeToRemove->previous != NULL)
            nodeToRemove->previous->next = nodeToRemove->next;
        if (nodeToRemove->next != NULL)
            nodeToRemove->next->previous = nodeToRemove->previous;
        free(nodeToRemove);
        size--;
        printf("%d was removed from the list", item);
    }
}

void clearLL() {
    while (head != NULL) {
        removeFromHeadLL();
    }
}

int containsLL(int item) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data == item) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int getIndexLL(int item) {
    int index = 0;
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data == item) {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return index;
}

void sortLL() {
    if (size > 1) {
        Node *temp = head->next;
        while (temp != NULL){
            if (temp->data < temp->previous->data) {
                int dataToInsert = temp->data;
                while (temp->previous != NULL && dataToInsert < temp->previous->data) {
                    temp->data = temp->previous->data;
                    temp = temp->previous;
                }
                temp->data = dataToInsert;
            }
            temp = temp->next;
        }
    }
}
