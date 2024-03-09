#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct Node {
	element data;
	struct Node* next;
}Node;

typedef struct {
	Node* top;
}stackType;

stackType* create_stack() {
	stackType* newStack = (stackType*)malloc(sizeof(stackType));
	return newStack;
}
void init_stack(stackType* s) {
	s->top = NULL;
}
int is_empty(stackType* s) {
	return s->top == NULL;
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
void push(stackType* s, element e) {
	Node* newNode = createNode(e);
	newNode->next = s->top;
	s->top = newNode;
}
element pop(stackType* s) {
	if (is_empty(s))error("stack empty");
	Node* output = s->top;
	element outputdata = output->data;
	s->top = s->top->next;
	free(output);
	return outputdata;
}
