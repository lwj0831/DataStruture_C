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
	q->front = q->rear = -1;
}
int is_full(queueType* q) {
	return q->rear == MAX_QUEUE_SIZE-1;
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
	q->arr[++q->rear] = e;
}
element dequeue(queueType* q) {
	if (is_empty(q))error("queue empty");
	return q->arr[++q->front];
}
element peek(queueType* q) {
	if (is_empty(q))error("queue empty");
	return q->arr[q->front +1];
}