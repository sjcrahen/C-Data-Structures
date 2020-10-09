#include <stdio.h>
#include <stdlib.h>
#include "intArrayStack.h"

void printArrayStack(int stack[], int size) {
    if (size == 0) printf("-EMPTY STACK-");
    else {
        printf("Stack: [ %d", stack[0]);
        for (int i = 1; i < size; i++) {
            printf(", %d", stack[i]);
        }
        printf(" ]");
    }
}

void push(int item, int stack[], int *size, int capacity) {
    if (*size == capacity) // stack is full
        printf("-STACK OVERFLOW-");
    else
        stack[(*size)++] = item;
}

int peek(int stack[], int size) {
    if (size == 0) {
        printf("-EMPTY STACK-");
        return -1;
    } else
        return stack[size - 1];
}

int pop(int stack[], int *size) {
    if (*size == 0) {
        printf("-EMPTY STACK-");
        return -1;
    } else {
        int itemToReturn = stack[--*size];
        return itemToReturn;
    }
}
