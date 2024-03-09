#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct Node {
	element data;
	struct Node* next;
}Node;

typedef struct {
	Node* head;
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
void insert_Last(listType* l, element e) {
	Node* newNode = createNode(e);
	if (l->head == NULL) {
		l->head = newNode;
		l->head->next = l->head;
	}
	else {
		Node* currentNode = l->head;
		while (currentNode->next != l->head) {
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
		newNode->next = l->head;
	}
}
void insert_Last2(listType* l, element e) {
	Node* newNode = createNode(e);
	if (l->head == NULL) {
		l->head = newNode;
		l->head->next = l->head;
	}
	else {
		newNode->next = l->head->next;
		l->head->next = newNode;
		l->head = newNode;
	}
}
void insert_First(listType* l, element e) {
	Node* newNode = createNode(e);
	if (l->head == NULL) {
		l->head = newNode;
		l->head->next = l->head;
	}
	else {
		newNode->next = l->head;
		Node* currentNode = l->head;
		while (currentNode->next != l->head) {
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
		l->head = newNode;
	}
}
void insert_First2(listType* l, element e) {
	Node* newNode = createNode(e);
	if (l->head == NULL) {
		l->head = newNode;
		l->head->next = l->head;
	}
	else {
		newNode->next = l->head->next;
		l->head->next = newNode;
	}
}
element deleteNode(listType* l, element e) {
	Node* currentNode = l->head;
	Node* prev = NULL;
	do{
		if (currentNode->data == e) break;
		prev = currentNode;
		currentNode = currentNode->next;
	} while (currentNode != l->head);
	if (l->head == NULL) {
		return 0;
	}
	else if (l->head == currentNode) {
		element outputdata = currentNode->data;
		prev->next = currentNode->next;
		l->head = l->head->next;
		free(currentNode);
		return outputdata;
	}
	else if (currentNode == l->head) return 0;
	else {
		element outputdata = currentNode->data;
		prev->next = currentNode->next;
		free(currentNode);
		return outputdata;
	}
	


}