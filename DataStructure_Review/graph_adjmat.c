#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICLES 100

typedef struct {
	int adj_mat[MAX_VERTICLES][MAX_VERTICLES];
	int n;
}graphType;

graphType* create_graph() {
	graphType* newGraph = (graphType*)malloc(sizeof(graphType));
	return newGraph;
}
void init_graph(graphType* g) {
	for (int i = 0; i < MAX_VERTICLES; i++) {
		for (int j = 0; j < MAX_VERTICLES; j++) {
			g->adj_mat[i][j] = 0;
		}
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
void insert_edge(graphType* g, int s, int e) {
	if (s < 0 && s >= g->n && e < 0 && e >= g->n)error("index error");
	g->adj_mat[s][e] = 1;
}
void print_Graph(graphType* g) {
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			printf("%d ", g->adj_mat[i][j]);
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
	for (int i = 0; i < g->n; i++) {
		if (!visited[i] && g->adj_mat[s][i]) {
			dfs(g, i);
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
		for (int i = 0; i < g->n; i++) {
			if (!visited[i] && g->adj_mat[o][i]) {
				visited[i] = 1;
				printf("%d ", i);
				enqueue(q, i);
			}
		}
	}
}

