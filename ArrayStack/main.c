#include <stdio.h>
#include <stdlib.h>
#include "intArrayStack.h"

int main()
{
    printArrayStack();

    // test push
    printf("\n\n----- test push -----");
    printf("\ntest push to empty stack: ");
    push(5);
    printArrayStack();
    printf("\ntest push to full capacity stack: ");
    push(7);
    push(4);
    printArrayStack();
    printf("\ntest doubling stack capacity: ");
    push(11);
    push(17);
    push(3);
    printArrayStack();

    // test peek
    printf("\n\n----- test peek -----");
    printf("\ntest peek: ");
    int item = peek();
    if (item != -1) {
        printf("%d is on the top of the stack", item);
    } else {
        printf("empty stack");
    }

    // test pop
    printf("\n\n----- test pop -----");
    printf("\ntest pop: ");
    item = pop();
    if (item != -1) {
        printf("returned %d", item);
    } else {
        printf("empty stack");
    }
    printf("\n");
    printArrayStack();
    printf("\ntest halving stack capacity: ");
    pop();
    printArrayStack();

    // test empty stack
    printf("\n\n----- test empty stack -----");
    pop();
    pop();
    pop();
    pop();
    printf("\n");
    printArrayStack();
    printf("\ntest peek on empty stack: ");
    item = peek();
    if (item != -1) {
        printf("%d is on the top of the stack", item);
    } else {
        printf("empty stack");
    }
    printf("\ntest pop on empty stack: ");
    item == pop();
    if (item != -1) {
        printf("returned %d", item);
    } else {
        printf("empty stack");
    }
    printf("\n");

    return 0;
}
