#include<stdio.h>
#include<stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;

typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}stackType;

stackType* create_stack() {
	stackType* newStack = (stackType*)malloc(sizeof(stackType));
	return newStack;
}
void init_stack(stackType* s) {
	s->top = -1;
}
int is_full(stackType* s) {
	return s->top == MAX_STACK_SIZE;
}
int is_empty(stackType* s) {
	return s->top == -1;
}
void error(const char* message) {
	fprintf(stderr, "%s", message);
	exit(1);
}
void push(stackType* s, element e) {
	if (is_full(s)) error("stack full");
	s->stack[++s->top] = e;
}
element pop(stackType* s) {
	if (is_empty(s))error("stack empty");
	return s->stack[s->top--];
}
element peek(stackType* s) {
	if (is_empty(s))error("stack empty");
	return s->stack[s->top];
}

