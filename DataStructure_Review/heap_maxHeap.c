#include<stdio.h>
#include<stdlib.h>

#define MAX_HEAP_SIZE 100

typedef int element;

typedef struct {
	element heap[MAX_HEAP_SIZE];
	int heap_size;
}heapType;

heapType* createHeap() {
	heapType* newHeap = (heapType*)malloc(sizeof(heapType));
	return newHeap;
}
void init_heap(heapType* h) {
	h->heap_size = 0;
}
int is_full(heapType* h) {
	return h->heap_size == MAX_HEAP_SIZE;
}
int is_empty(heapType* h) {
	return h->heap_size == 0;
}
void insert_max_heap(heapType* h, element e) {
	int i = ++h->heap_size;
	while (i > 1 && h->heap[i/2]<e) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = e;
}
element delete_max_heap(heapType* h) {
	element temp = h->heap[h->heap_size--];
	element outputdata = h->heap[1];

	int parent_index = 1;
	int child_index = 2;
	while (child_index <= h->heap_size) {
		if (h->heap[child_index] < h->heap[child_index + 1]) child_index++;
		if (h->heap[child_index] <= temp) break;
		h->heap[parent_index] = h->heap[child_index];
		parent_index = child_index;
		child_index *= 2;
	}
	h->heap[parent_index] = temp;
	return outputdata;
}

