#include <stdio.h>
#include <stdlib.h>
#include "intQueue.h"

int main() {

    printf("-----  test printLinkedQueue  -----");
    printf("\nempty queue: ");
    printLinkedQ();

    printf("\n\n-----  test enqueueLinkedQueue  -----");
    printf("\ntest enqueue on empty queue: ");
    enqueueLinkedQ(3);
    printLinkedQ();
    printf("\ntest enqueue on non-empty queue: ");
    enqueueLinkedQ(4);
    enqueueLinkedQ(7);
    printLinkedQ();

    printf("\n\n-----  test clearLinkedQueue  -----");
    printf("\ntest clear: ");
    clearLinkedQ();
    printLinkedQ();

    printf("\n\n-----  test peekLinkedQueue  -----");
    printf("\ntest peek on empty queue: ");
    int front = peekLinkedQ();
    if (front == -1) printf("empty queue");
    else printf("%d is in front of queue", front);
    enqueueLinkedQ(2);
    enqueueLinkedQ(5);
    enqueueLinkedQ(8);
    printf("\ntest peek on non-empty queue: ");
    printLinkedQ();
    front = peekLinkedQ();
    if (front == -1) printf("\nempty queue");
    else printf("\n%d is in front of queue", front);

    printf("\n\n-----  test dequeueLinkedQueue  -----");
    printf("\nqueue: ");
    printLinkedQ();
    printf("\ntest dequeue: ");
    int item = dequeueLinkedQ();
    if (item == -1) printf("empty queue");
    else printf("dequeued %d", item);
    printf("\nqueue: ");
    printLinkedQ();
    printf("\ntest dequeue: ");
    item = dequeueLinkedQ();
    if (item == -1) printf("empty queue");
    else printf("dequeued %d", item);
    printf("\nqueue: ");
    printLinkedQ();
    printf("\ntest dequeue: ");
    item = dequeueLinkedQ();
    if (item == -1) printf("empty queue");
    else printf("dequeued %d", item);
    printf("\nqueue: ");
    printLinkedQ();
    printf("\ntest dequeue on empty queue: ");
    item = dequeueLinkedQ();
    if (item == -1) printf("empty queue");
    else printf("dequeued %d", item);

    return 0;
}
