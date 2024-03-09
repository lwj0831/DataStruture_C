#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICLES 100

typedef int element;

typedef struct Node {
	element data;
	struct Node* next;
}Node;

typedef struct {
	Node* adj_list[MAX_VERTICLES];
	int n;
}graphType;

graphType* create_graph() {
	graphType* newGraph = (graphType*)malloc(sizeof(graphType));
	return newGraph;
}
void init_graph(graphType* g) {
	for (int i = 0; i < MAX_VERTICLES; i++) {
		g->adj_list[i] = NULL;
	}
	g->n = 0;
}
void error(const char* message) {
	fprintf(stderr, "%s", message);
	exit(1);
}
void insert_vertex(graphType* g) {
	if (g->n >= MAX_VERTICLES) error("verticles full");
	g->n++;
}
Node* createNode(element e) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = e;
	newNode->next = NULL;
	return newNode;
}
void insert_edge(graphType* g, int s, int e) {
	if (s < 0 && s >= g->n && e < 0 && e >= g->n)error("index error");
	Node* newNode = createNode(e);
	newNode->next = g->adj_list[s];
	g->adj_list[s] = newNode;
}
void print_Graph(graphType* g) {
	for (int i = 0; i < g->n; i++) {
		for (Node* currentNode = g->adj_list[i]; currentNode; currentNode = currentNode->next) {
			printf("%d ", currentNode->data);
		}
		printf("\n");
	}
}
//////////////////////////////////////////
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
	q->front = q->rear = -1;
}
int is_full(queueType* q) {
	return q->rear == MAX_QUEUE_SIZE - 1;
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
	q->arr[++q->rear] = e;
}
element dequeue(queueType* q) {
	if (is_empty(q))error("queue empty");
	return q->arr[++q->front];
}
//////////////////////////////////////////////
int visited[MAX_VERTICLES] = { 0 };

void dfs(graphType* g, int s) {
	visited[s] = 1;
	printf("%d ", s);
	for (Node* currentNode = g->adj_list[s]; currentNode; currentNode = currentNode->next) {
		if (!visited[currentNode->data]) {
			dfs(g, currentNode->data);
		}
	}
}
void bfs(graphType* g, int s) {
	queueType* q = create_queue();
	init_queue(q);

	enqueue(q, s);
	visited[s] = 1;
	printf("%d ", s);
	while (!is_empty(q)) {
		element o = dequeue(q);
		for (Node* currentNode = g->adj_list[s]; currentNode; currentNode = currentNode->next) {
			if (!visited[currentNode->data]) {
				visited[currentNode->data] = 1;
				printf("%d ", currentNode->data);
				enqueue(q, currentNode->data);
			}
		}
	}
}
