#ifndef INTARRAYSTACK_H_INCLUDED
#define INTARRAYSTACK_H_INCLUDED

void push(int item, int stack[], int *size, int capacity);
int peek(int stack[], int size);
int pop(int stack[], int *size);
void printArrayStack(int stack[], int size);

#endif // INTARRAYSTACK_H_INCLUDED
