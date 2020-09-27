#include <stdio.h>
#include <stdlib.h>
#include "intArrayStack.h"

#define DEFAULT_CAPACITY 2

int *stack;
int size = 0, capacity = DEFAULT_CAPACITY;

void printArrayStack() {
    if (size == 0) printf("Stack: [ ] size: %d capacity: %d", size, capacity);
    else {
        printf("Stack: [ %d", stack[0]);
        for (int i = 1; i < size && i < capacity; i++) {
            printf(", %d", stack[i]);
        }
        printf(" ] size: %d capacity: %d", size, capacity);
    }
}

void push(int item) {
    if (size == 0) {
        stack = (int *)malloc(sizeof(int)*capacity);
    }
    if (size == capacity) {
        doubleStackCapacity();
    }
    stack[size++] = item;
}

void doubleStackCapacity() {
    stack = (int *)realloc(stack, sizeof(int)*capacity*2);
    capacity *= 2;
}

int peek() {
    if (size == 0)
        return -1;
    else
        return stack[size - 1];
}

int pop() {
    if (size == 0) {
        return -1;
    } else {
        int itemToReturn = stack[--size];
        if (size <= capacity/2) {
            halveStackCapacity();
        }
        return itemToReturn;
    }
}

void halveStackCapacity() {
    if (capacity/2 >= DEFAULT_CAPACITY) {
        stack = (int *)realloc(stack, sizeof(int)*capacity/2);
        capacity /= 2;
    }
}
