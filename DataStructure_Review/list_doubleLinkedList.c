#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct Node {
	element data;
	struct Node* prev;
	struct Node* next;
}Node;

typedef struct {
	Node* head;
}DDLType;

DDLType* createDDL() {
	DDLType* newDDL = (DDLType*)malloc(sizeof(DDLType));
	return newDDL;
}
void init_DDL(DDLType* d) {
	d->head = (Node*)malloc(sizeof(Node));
	d->head->next = d->head->prev = d->head;
}
void error(const char* message) {
	fprintf(stderr, "%s", message);
	exit(1);
}
Node* createNode(element e) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = e;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}
void insertNode(DDLType* d,element e) {
	Node* newNode = createNode(e);
	newNode->next = d->head->next;
	newNode->prev = d->head;
	d->head->next->prev = newNode;
	d->head->next = newNode;
}
element deleteNode(DDLType* d,Node* removed) {
	if (d->head == removed)error("head node cannot removed");
	removed->next->prev = removed->prev;
	removed->prev->next = removed->next;
	element outputdata = removed->data;
	free(removed);
	return outputdata;
}