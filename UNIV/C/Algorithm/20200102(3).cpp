//20��01��02��
//�׷���-�迭,ť(bfs)
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 5

typedef struct GraphType {
	int n;		//������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICES];		// �迭�� �̸�
}GraphType;

typedef int element;	//int���� element������ ������

typedef struct {
	element queue[MAX_VERTICES];
	int rear, front;		//data�߰�:rear, data ����: front
}QueueType;
//�����迭, 0���� �ʱ�ȭ��
int visited[MAX_VERTICES];

void init(GraphType* g) {
	g->n = 0;	//n=0 �ȵ�. g�� ������ �� n�� 0�̴�.
	for (int r = 0; r < MAX_VERTICES; r++) {
		for (int c = 0; c < MAX_VERTICES; c++) {
			g->adj_mat[r][c] = 0;		//g�� ����Ű�� �迭�� 0�̴�.
		}
	}
}
void queue_init(QueueType* q) {
	/*����ť���� ���� �߿���!
		front, rear�� �ʱⰪ�� 0.
		��, ����ť�� -1���� �����ϹǷ� �ʱⰪ�� -1�ε�.
	*/
	q->front = q->rear = 0;
}

void insert_vertex(GraphType* g, int v) {
	if ((g->n + 1) > MAX_VERTICES) {
		printf("�׷��� �������� �ʰ�\n");
		return;
	}
	g->n++;		// n�� ������ �ϳ��� �߰��ϰ� ������ max�� 4�� ������ �� 4�����϶��� �߰��� �� �ֵ��� �ڵ带 «.
}

void insert_edge(GraphType* g, int start, int end) {
	if (start >= g->n || end >= g->n) {
		printf("�׷��� ���� ��ȣ ����\n");
		return;
	}
	g->adj_mat[start][end] = 1;		//g�� ����Ű���ִ� ��������� �����Ѵ�(�� 1�� �����ϴ� ������ ǥ��)
	g->adj_mat[end][start] = 1;
}

void print_adj_mat(GraphType* g) {
	for (int r = 0; r < MAX_VERTICES; r++) {
		for (int c = 0; c < MAX_VERTICES; c++) {
			printf("%2d ", g->adj_mat[r][c]);

		}
		printf("\n");
	}
}

//�ڷᱸ���� �迭�̸� insert �� overflow check!
int is_full(QueueType* q) {		//QueueType *q�� �迭�� ����������ϹǷ�.

	/*
		����ť���� ���� ����� �Ф�
		�츮 �����δ� ���� �ϳ��� ������(�޸� ���� �ϳ��� ��������) ���� ������ ���.
		���� �����Ͱ� ���� front�� �ϳ� �� rear�� �޸� ������ ���ٰ� ģ��.
	*/
	return (q->rear + 1) % MAX_VERTICES == q->front;
}

//�ڷᱸ������ ������ ���� �ÿ��� underflow check!
int is_empty(QueueType* q) {	//QueueType *q�� �迭�� ����������ϹǷ�.
	return (q->front == q->rear);
}
//ť�� ������ ����
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		printf("ť�� ��ȭ������\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_VERTICES;
	q->queue[q->rear] = item;
}
//ť���� ������ ����, ����
element dequeue(QueueType* q) {		//0 1 2 3 4
	if (is_empty(q)) {
		printf("ť�� �������\n");
		exit(1);
	}
	q->front = (q->front + 1) % MAX_VERTICES;
	return q->queue[q->front];
}

void bfs_mat(GraphType* g, int v) {
	int w;
	QueueType q;
	queue_init(&q);
	visited[v] = TRUE;
	printf("%d->", v);
	enqueue(&q, v);
	while (!is_empty(&q)) {
		v = dequeue(&q);		//��ó���� ������ �ִ� 0�� ���ٰ� 0�� ����
		for (w = 0; w < g->n; w++) {
			if (g->adj_mat[v][w] && !visited[w]) {
				visited[w] = TRUE;
				printf("%d->", w);		//�湮�ߴٰ� ǥ��
				enqueue(&q, w);
			}
		}
	}
}

int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	//���� �߰�
	for (int i = 0; i < MAX_VERTICES; i++) {
		insert_vertex(g, i);
	}
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 1, 4);
	insert_edge(g, 3, 4);

	//	print_adj_mat(g);

	bfs_mat(g, 0);
	printf("\n");
	free(g);
}