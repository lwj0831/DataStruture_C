#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct Node {
	element data;
	struct Node* next;
}Node;

typedef struct {
	Node* head;
	Node* tail;
}listType;

listType* create_list() {
	listType* newList = (listType*)malloc(sizeof(listType));
	return newList;
}
void init_List(listType* l) {
	l->head = NULL;
}
int is_empty(listType* l) {
	return l->head == NULL;
}
Node* createNode(element e) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = e;
	newNode->next = NULL;
	return newNode;
}
void insert_Last1(listType* l, element e) {
	if (l->head == NULL) {
		l->head = createNode(e);
	}
	else {
		Node* currentNode = l->head;
		while (currentNode->next != NULL) {
			currentNode = currentNode;
		}
		currentNode->next = createNode(e);
	}
}
void insert_Last2(listType* l, element e) {
	if (l->tail == NULL) {
		l->head = l->tail = createNode(e);
	}
	else {
		l->tail->next = createNode(e);
		l->tail = l->tail->next;
	}
}
void insert_Head(listType* l, element e) {
	if (l->head == NULL) {
		l->head = l->tail = createNode(e);
	}
	else {
		Node* newNode = createNode(e);
		newNode->next = l->head;
		l->head = newNode;
	}
}
void sorted_insert_List(listType* l, element e) {
	Node* currentNode = l->head;
	Node* prev = NULL;
	while (currentNode != NULL) {
		if (currentNode->data < e) break;
		prev = currentNode;
		currentNode = currentNode->next;
	}
	Node* newNode = createNode(e);
	if (l->head == NULL) {
		l->head = newNode;
	}
	else if (l->head == currentNode) {
		newNode->next = l->head;
		l->head = newNode;
	}
	else if (currentNode == NULL) {
		prev->next = newNode;
	}
	else {
		prev->next = newNode;
		newNode->next = currentNode;
	}
}
void sorted_insert_List2(listType* l, element e) {
	Node* currentNode = l->head;
	Node* prev = NULL;
	while (currentNode != NULL) {
		if (currentNode->data < e) break;
		prev = currentNode;
		currentNode = currentNode->next;
	}
	Node* newNode = createNode(e);
	if (l->head == NULL) {
		l->head = l->tail = newNode;
	}
	else if (l->head == currentNode) {
		newNode->next = l->head;
		l->head = newNode;
	}
	else if (currentNode == NULL) {
		prev->next = newNode;
		l->tail = newNode;
	}
	else {
		prev->next = newNode;
		newNode->next = currentNode;
	}
}
element delete_Node(listType* l, element e) {
	Node* currentNode = l->head;
	Node* prev = NULL;
	while (currentNode != NULL) {
		if (currentNode->data == e)break;
		else if (currentNode->data > e) return 0;
		prev = currentNode;
		currentNode = currentNode->next;
	}
	if (l->head == NULL) {
		return 0;
	}
	else if (l->head == currentNode) {
		Node* output = l->head;
		element outputdata = output->data;
		l->head = l->head->next;
		free(output);
		return outputdata;
	}
	else {
		element outputdata = currentNode->data;
		prev->next = currentNode->next;
		free(currentNode);
		return outputdata;
	}
}
void freeList(listType* l) {
	Node* currentNode = l->head;
	Node* prev = NULL;
	while (currentNode != NULL) {
		prev = currentNode;
		currentNode = currentNode->next;
		free(prev);
	}
}