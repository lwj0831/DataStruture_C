#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct Node{
	element data;
	struct Node* left;
	struct Node* right;
}Node;

Node* createNode(element e) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = e;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void preorder(Node* root) {
	if (root != NULL) {
		printf("%d", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(Node* root) {
	if (root != NULL) {
		preorder(root->left);
		printf("%d", root->data);
		preorder(root->right);
	}
}
void postorder(Node* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d", root->data);
	}
}

Node* insert_Node(Node* root,element e) {
	if (root == NULL) return createNode(e);
	else if (root->data > e) insert_Node(root->left, e);
	else if (root->data < e) insert_Node(root->right, e);
	return root;
}
Node* find_min_Node(Node* root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}
Node* delete_Node(Node* root, element e) {
	if (root == NULL)return NULL;
	else if (root->data > e)delete_Node(root->left, e);
	else if (root->data < e)delete_Node(root->right, e);
	else {
		if (root->left == NULL) {
			Node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			Node* temp = root->left;
			free(root);
			return temp;
		}
		else {
			Node* temp = find_min_Node(root->right);
			root->data = temp->data;
			delete_Node(root->right, temp->data);
		}
	}
	return root;
}
///////////////////////////////////
#define MAX_QUEUE_SIZE 100
typedef Node* element;
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
void enqueue(queueType* q, element e) {
	if (is_full(q))error("queue full");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->arr[q->rear] = e;
}
element dequeue(queueType* q) {
	if (is_empty(q))error("queue empty");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->arr[q->front];
}
/////////////////////////////////////////
void level_order(Node* root) {
	queueType* q = create_queue();
	init_queue(q);
	if (root == NULL) return;
	enqueue(q, root);
	while (!is_empty(q)) {
		Node* output = dequeue(q);
		printf("%d", output->data);
		if (output->left) enqueue(q,output->left);
		if (output->right) enqueue(q,output->right);
	}
}
int get_node_count(Node* root) {
	if (root == NULL)return 0;
	else return get_node_count(root->left) + get_node_count(root->right) + 1;
}
int get_leaf_node(Node* root) {
	if (root->left == NULL && root->right == NULL)return 1;
	else return get_leaf_node(root->left) + get_leaf_node(root->right);
}
int get_min(int a, int b) {
	if (a > b)return b;
	else return a;
}
int get_height(Node* root) {
	if (root == NULL)return 0;
	else return get_min(get_height(root->left), get_height(root->right)) + 1;
}