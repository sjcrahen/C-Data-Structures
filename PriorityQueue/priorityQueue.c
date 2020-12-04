#include <stdio.h>
#define MAX_SIZE 100

int heap[MAX_SIZE];
int back = 0;

void reheap(int *heap, int lastIndex, int rootIndex) {
	int orphan = heap[rootIndex];
	int leftChildIndex = 2 * rootIndex;

	while (leftChildIndex <= lastIndex) {
		int largerChildIndex = leftChildIndex;
		int rightChildIndex = leftChildIndex + 1;
		if (rightChildIndex <= lastIndex && heap[largerChildIndex] < heap[rightChildIndex])
			largerChildIndex = rightChildIndex;
		if (orphan < heap[largerChildIndex]) {
			heap[rootIndex] = heap[largerChildIndex];
			rootIndex = largerChildIndex;
			leftChildIndex = 2 * rootIndex;
		} else
			break;
	}
	heap[rootIndex] = orphan;
}

void enqueue(int *heap, int newItem) {
	if (back < MAX_SIZE - 1) {
		int newIndex = ++back;
		int parentIndex = newIndex / 2;
		while (parentIndex > 0 && newItem > heap[parentIndex]) {
			heap[newIndex] = heap[parentIndex];
			newIndex = parentIndex;
			parentIndex = newIndex / 2;
		}
		heap[newIndex] = newItem;
	} else
		printf("error: queue is full\n");
}

int dequeue(int *heap) {
	int root;
	if (back > 0) {
		if (back == 1) {
			return heap[back--];
		} else {
			root = heap[1];	
			heap[1] = heap[back--];
			reheap(heap, back, 1);
		}
	}
	return root;
}

void printQueue(int *a, int lastIndex) {
	if (lastIndex < 1)
		printf("empty queue\n");
	for (int i = 1; i <= lastIndex; i++) {
		printf("%d ", a[i]);	
	}
	printf("\n");
}

int main() {
	int arr[] = {-1, 20, 40, 30, 10, 90, 70};
	int lastIndex = 6;
	printf("-----  test reheap  -----\n");
	printQueue(arr, lastIndex);
	for (int i = lastIndex / 2; i > 0; i--) {
		reheap(arr, lastIndex, i);
	}
	printQueue(arr, lastIndex);
	printf("-----  test enqueue  -----\n");
	printf("enqueue(17):\n");
	enqueue(heap, 17);
	printf("queue is: ");
	printQueue(heap, back);
	printf("enqueue(32):\n");
	enqueue(heap, 32);
	printf("queue is: ");
	printQueue(heap, back);
	printf("enqueue(25):\n");
	enqueue(heap, 25);
	printf("queue is: ");
	printQueue(heap, back);
	printf("enqueue(12):\n");
	enqueue(heap, 12);
	printf("queue is: ");
	printQueue(heap, back);
	printf("enqueue(47):\n");
	enqueue(heap, 47);
	printf("queue is: ");
	printQueue(heap, back);
	printf("enqueue(63):\n");
	enqueue(heap, 63);
	printf("queue is: ");
	printQueue(heap, back);
	printf("-----  test dequeue  ------\n");
	while (back > 0) {
		printf("dequeue: %d\n", dequeue(heap));
		printf("queue is: ");
		printQueue(heap, back);
	}
}
