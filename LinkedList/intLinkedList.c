#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "intLinkedList.h"

void printLL(IntLL *list) {
    if (list->size == 0) printf("List: [ ] size: %d", list->size);
    else {
        Node *temp = list->head;
        printf("List: [ %d", temp->data);
        while (temp->next != NULL) {
            temp = temp->next;
            printf(", %d", temp->data);
        }
        printf(" ] size: %d", list->size);
    }
}

void insertAtEndLL(int newItem, IntLL *list) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = newItem;
    newNode->next = NULL;
    if (list->size == 0) {
        list->head = newNode;
        newNode->previous = NULL;
    } else {
        Node *temp = list->head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->previous = temp;
    }
    list->size++;
}

int removeFromHeadLL(IntLL *list) {
    int item = -1;
    if (list->size == 0) {
        printf("Cannot remove from an empty list");
    } else {
        item = list->head->data;
        Node *temp = list->head;
        if (list->head->next == NULL) {
            list->head = NULL;
        } else {
            list->head = list->head->next;
            list->head->previous = NULL;
        }
        free(temp);
        list->size--;
    }
    return item;
}

void removeItemLL(int item, IntLL *list) {
    Node *nodeToRemove = list->head;
    while (nodeToRemove != NULL && nodeToRemove->data != item) {
        nodeToRemove = nodeToRemove->next;
    }
    if (nodeToRemove == NULL) {
        printf("This list DOES NOT contain %d", item);
    } else if (nodeToRemove == list->head) {
        removeFromHeadLL(list);
        printf("%d was removed from the list", item);
    } else {
        if (nodeToRemove->previous != NULL)
            nodeToRemove->previous->next = nodeToRemove->next;
        if (nodeToRemove->next != NULL)
            nodeToRemove->next->previous = nodeToRemove->previous;
        free(nodeToRemove);
        list->size--;
        printf("%d was removed from the list", item);
    }
}

void clearLL(IntLL *list) {
    while (list->head != NULL) {
        removeFromHeadLL(list);
    }
}

bool containsLL(int item, IntLL *list) {
    Node *temp = list->head;
    while (temp != NULL) {
        if (temp->data == item) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int getIndexLL(int item, IntLL *list) {
    int index = 0;
    Node *temp = list->head;
    while (temp != NULL) {
        if (temp->data == item) {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return index;
}

void sortLL(IntLL *list) {
    if (list->size > 1) {
        Node *temp = list->head->next;
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
