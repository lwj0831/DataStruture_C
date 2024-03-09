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
void insert_rear(queueType* q, element e) {
	if (is_full(q))error("queue full");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->arr[q->rear] = e;
}
void insert_front(queueType* q, element e) {
	if (is_full(q))error("queue full");
	q->arr[q->front] = e;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}
element delete_front(queueType* q) {
	if (is_empty(q))error("queue empty");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->arr[q->front];
}
element delete_rear(queueType* q) {
	if (is_empty(q))error("queue empty");
	element outputdata = q->arr[q->rear];
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return outputdata;
}
element get_front(queueType* q) {
	if (is_empty(q))error("queue empty");
	return q->arr[(q->front + 1) % MAX_QUEUE_SIZE];
}
element get_rear(queueType* q) {
	if (is_empty(q))error("queue empty");
	return q->arr[(q->rear) % MAX_QUEUE_SIZE];
}
