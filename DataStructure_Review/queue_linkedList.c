#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct Node {
	element data;
	struct Node* next;
}Node;

typedef struct {
	Node* rear;
	Node* front;
}queueType;

queueType* create_queue() {
	queueType* newQueue= (queueType*)malloc(sizeof(queueType));
	return newQueue;
}
void init_queue(queueType* q) {
	q->rear = q->front = NULL;
}
int is_empty(queueType* q) {
	q->front == NULL;
}
void error(const char* message) {
	fprintf(stderr, "%s", message);
	exit(1);
}
Node* createNode(element e) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = e;
	newNode->next = NULL;
	return newNode;
}
void enqueue(queueType* q, element e) {
	if (is_empty(q)) {
		q->rear = q->front = createNode(e);
	}
	else {
		Node* newNode = createNode(e);
		q->rear->next = newNode;
		q->rear = q->rear->next;
	}
}
element dequeue(queueType* q) {
	if (is_empty(q))error("queue empty");
	Node* output = q->front;
	element outputdata = q->front->data;
	q->front = q->front->next;
	free(output);
	return outputdata;
}