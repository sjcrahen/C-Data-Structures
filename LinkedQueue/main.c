#include <stdio.h>
#include <stdlib.h>
#include "intQueue.h"

int main() {

    IntegerQueue q, *qp;
    q.front = NULL;
    q.back = NULL;
    q.size = 0;
    qp = &q;

    printf("-----  test printLinkedQueue  -----");
    printf("\nempty queue: ");
    printLinkedQ(qp);

    printf("\n\n-----  test enqueueLinkedQueue  -----");
    printf("\ntest enqueue on empty queue: ");
    enqueueLinkedQ(3, qp);
    printLinkedQ(qp);
    printf("\ntest enqueue on non-empty queue: ");
    enqueueLinkedQ(4, qp);
    enqueueLinkedQ(7, qp);
    printLinkedQ(qp);

    printf("\n\n-----  test clearLinkedQueue  -----");
    printf("\ntest clear: ");
    clearLinkedQ(qp);
    printLinkedQ(qp);

    printf("\n\n-----  test peekLinkedQueue  -----");
    printf("\ntest peek on empty queue: ");
    int front = peekLinkedQ(qp);
    if (front == -1) printf("empty queue");
    else printf("%d is in front of queue", front);
    enqueueLinkedQ(2, qp);
    enqueueLinkedQ(5, qp);
    enqueueLinkedQ(8, qp);
    printf("\ntest peek on non-empty queue: ");
    printLinkedQ(qp);
    front = peekLinkedQ(qp);
    if (front == -1) printf("\nempty queue");
    else printf("\n%d is in front of queue", front);

    printf("\n\n-----  test dequeueLinkedQueue  -----");
    printf("\nqueue: ");
    printLinkedQ(qp);
    printf("\ntest dequeue: ");
    int item = dequeueLinkedQ(qp);
    if (item == -1) printf("empty queue");
    else printf("dequeued %d", item);
    printf("\nqueue: ");
    printLinkedQ(qp);
    printf("\ntest dequeue: ");
    item = dequeueLinkedQ(qp);
    if (item == -1) printf("empty queue");
    else printf("dequeued %d", item);
    printf("\nqueue: ");
    printLinkedQ(qp);
    printf("\ntest dequeue: ");
    item = dequeueLinkedQ(qp);
    if (item == -1) printf("empty queue");
    else printf("dequeued %d", item);
    printf("\nqueue: ");
    printLinkedQ(qp);
    printf("\ntest dequeue on empty queue: ");
    item = dequeueLinkedQ(qp);
    if (item == -1) printf("empty queue");
    else printf("dequeued %d", item);

    return 0;
}
