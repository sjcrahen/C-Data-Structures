#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "intLinkedList.h"

int main(int argc, char *argv[]) {
    IntLL list, *listp;
    list.head = NULL;
    list.size = 0;
    listp = &list;

    // test add
    printLL(listp);

    printf("\n\n----- test add -----");
    printf("\ntest add to empty list: ");
    insertAtEndLL(5, listp);
    printLL(listp);
    printf("\ntest add to non-empty list: ");
    insertAtEndLL(9, listp);
    insertAtEndLL(3, listp);
    insertAtEndLL(6, listp);
    printLL(listp);

    // test remove
    printf("\n\n----- test remove -----");
    printf("\ntest remove head item: ");
    int item = removeFromHeadLL(listp);
    printf("removed %d", item);
    printf("\n");
    printLL(listp);
    printf("\ntest remove given item (6): ");
    removeItemLL(6, listp);
    printf("\n");
    printLL(listp);
    printf("\ntest remove given item (6): ");
    removeItemLL(6, listp);
    printf("\ntest clear: ");
    clearLL(listp);
    printLL(listp);
    printf("\ntest remove from empty list: ");
    removeFromHeadLL(listp);

    // test search for item
    printf("\n\n----- test search -----");
    insertAtEndLL(9, listp);
    insertAtEndLL(4, listp);
    insertAtEndLL(7, listp);
    insertAtEndLL(2, listp);
    insertAtEndLL(5, listp);
    printf("\n");
    printLL(listp);
    printf("\ntest search for (2): ");
    if (containsLL(2, listp)) {
        int index = getIndexLL(2, listp);
        printf("This list contains 2 at index %d", index);
    } else {
        printf("This list DOES NOT contain 2");
    }
    printf("\ntest search for (3): ");
    if (containsLL(3, listp)) {
        int index = getIndexLL(3, listp);
        printf("This list contains 3 at index %d", index);
    } else {
        printf("This list DOES NOT contain 3");
    }

    // test sort list
    printf("\n\n----- test sort -----");
    sortLL(listp);
    printf("\ntest sort: ");
    printLL(listp);
    printf("\n");
    clearLL(listp);

    return 0;
}
