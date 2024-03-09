#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef int element;

typedef struct {
	element arr[MAX_QUEUE_SIZE];
	int rear;
	int front;
}queueType;

queueType* create_queue() {
	queueType* newQueue = (queueType*)malloc(sizeof(queueType));
	return newQueue;
}
void init_queue(queueType* q) {
	q->front = q->rear = 0;
}
int is_full(queueType* q) {
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}
int is_empty(queueType* q) {
	return q->front == q->rear;
}
void error(const char* message) {
	fprintf(stderr, "%s", message);
	exit(1);
}
void enqueue(queueType* q, element e) {
	if (is_full(q))error("queue full");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->arr[q->rear] = e;
}
element dequeue(queueType* q) {
	if (is_empty(q))error("queue empty");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->arr[q->front];
}

#define BUCKETS 10
#define DIGITS 3

void radix_sort(int arr[], int n) {
	queueType* queue_arr[BUCKETS];
	for (int i = 0; i < BUCKETS; i++) {
		queue_arr[i] = create_queue();
		init_queue(queue_arr[i]);
	}

	for (int i = 0; i < DIGITS; i++) {
		int div = 10;
		for (int j = 0; j < n; j++) {
			enqueue(queue_arr[arr[j] / div%10], arr[j]);
		}
		for (int j = 0,k=0; j < BUCKETS; j++) {
			while (!is_empty(queue_arr[j])) {
				arr[k++] = dequeue(queue_arr[j]);
			}
		}
		div *= 10;
	}
}