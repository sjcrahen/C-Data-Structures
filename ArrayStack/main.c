#include <stdio.h>
#include <stdlib.h>
#include "intArrayStack.h"

int main() {

    int capacity = 2;
    int stack[capacity], size = 0;

    printArrayStack(stack, size);

    // test push
    printf("\n\n----- test push -----");
    printf("\ntest push to empty stack: ");
    printf("\npush(5): ");
    push(5, stack, &size, capacity);
    printArrayStack(stack, size); // [ 5 ]
    printf("\ntest push to full capacity stack: ");
    printf("\npush(7): ");
    push(7, stack, &size, capacity);
    printArrayStack(stack, size); // [ 5, 7 ]
    printf("\npush(4): ");
    push(4, stack, &size, capacity); // -STACK OVERFLOW-
    printf("\n");
    printArrayStack(stack, size); // [ 5, 7 ]

    // test peek
    printf("\n\n----- test peek -----");
    printf("\ntest peek: ");
    int item = peek(stack, size); // return 7
    if (item != -1) {
        printf("%d is on the top of the stack", item);
    }

    // test pop
    printf("\n\n----- test pop -----\n");
    printArrayStack(stack, size); // [ 5, 7]
    printf("\npop(7): ");
    item = pop(stack, &size); // pop 7
    if (item != -1) {
        printf("returned %d", item);
    }
    printf("\n");
    printArrayStack(stack, size); // [ 5 ]
    printf("\npop(5): ");
    item = pop(stack, &size); // pop 5
    if (item != -1) {
        printf("returned %d", item);
    }
    printf("\n");
    printArrayStack(stack, size);
    printf("\npop from empty stack: ");
    item = pop(stack, &size); // -EMPTY STACK-
    if (item != -1) {
        printf("returned %d", item);
    }

    // test empty stack
    printf("\n\n----- test empty stack -----");
    printf("\ntest print empty stack: ");
    printArrayStack(stack, size);
    printf("\ntest peek on empty stack: ");
    item = peek(stack, size);
    if (item != -1) {
        printf("%d is on the top of the stack", item);
    }
    printf("\ntest pop on empty stack: ");
    item = pop(stack, &size);
    if (item != -1) {
        printf("returned %d", item);
    }
    printf("\n");

    return 0;
}
