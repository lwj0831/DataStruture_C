#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct {
	element* data;
	int top;
	int capacity;
}stackType;

stackType* create_stack() {
	stackType* newStack = (stackType*)malloc(sizeof(stackType));
	return newStack;
}
void init_stack(stackType* s) {
	s->top = -1;
	s->capacity = 1;
}
int is_full(stackType* s) {
	return s->top == s->capacity-1;
}
int is_empty(stackType* s) {
	return s->top == -1;
}
void error(const char* message) {
	fprintf(stderr, "%s", message);
	exit(1);
}
void push(stackType* s, element e) {
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (element*)realloc(s->data,s->capacity);
	}
	s->data[++s->top] = e;
}
element pop(stackType* s) {
	if (is_empty(s))error("stack empty");
	return s->data[s->top--];
}
element peek(stackType* s) {
	if (is_empty(s))error("stack empty");
	return s->data[s->top];
}

