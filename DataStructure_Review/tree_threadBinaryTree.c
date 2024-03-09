#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct Node {
	element data;
	struct Node* left;
	struct Node* right;
	int is_thread;
}Node;

Node* createNode(element e) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = e;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->is_thread = 0;
	return newNode;
}

Node* find_successor(Node* node) {
	node = node->right;
	if (node == NULL || node->is_thread) {
		return node;
	}
	else {
		while (node->left != NULL) {
			node = node->left;
		}
		return node;
	}
}
void thread_inorder(Node* root) {
	while (root->left != NULL)root = root->left;
	while (root != NULL) {
		printf("%d", root->data);
		root = find_successor(root);
	}

}