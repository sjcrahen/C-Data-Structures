#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "intLinkedList.h"

int main(int argc, char *argv[]) {
    // test add
    printLL();
    printf("\n\n----- test add -----");
    printf("\ntest add to empty list: ");
    insertAtEndLL(5);
    printLL();
    printf("\ntest add to non-empty list: ");
    insertAtEndLL(9);
    insertAtEndLL(3);
    insertAtEndLL(6);
    printLL();

    // test remove
    printf("\n\n----- test remove -----");
    printf("\ntest remove head item: ");
    int item = removeFromHeadLL();
    printf("removed %d", item);
    printf("\n");
    printLL();
    printf("\ntest remove given item (6): ");
    removeItemLL(6);
    printf("\n");
    printLL();
    printf("\ntest remove given item (6): ");
    removeItemLL(6);
    printf("\ntest clear: ");
    clearLL();
    printLL();
    printf("\ntest remove from empty list: ");
    removeFromHeadLL();

    // test search for item
    printf("\n\n----- test search -----");
    insertAtEndLL(9);
    insertAtEndLL(4);
    insertAtEndLL(7);
    insertAtEndLL(2);
    insertAtEndLL(5);
    printf("\n");
    printLL();
    printf("\ntest search for (2): ");
    if (containsLL(2)) {
        int index = getIndexLL(2);
        printf("This list contains 2 at index %d", index);
    } else {
        printf("This list DOES NOT contain 2");
    }
    printf("\ntest search for (3): ");
    if (containsLL(3)) {
        int index = getIndexLL(3);
        printf("This list contains 3 at index %d", index);
    } else {
        printf("This list DOES NOT contain 3");
    }

    // test sort list
    printf("\n\n----- test sort -----");
    sortLL();
    printf("\ntest sort: ");
    printLL();
    printf("\n");
    clearLL();

    return 0;
}
