//20��01��02��
//�׷���-�迭,����(dfs)
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 5

typedef struct GraphType {
	int n;		//������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICES];		// �迭�� �̸�
}GraphType;

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

//������ �� ����(��, ����üũ~)
//���� �켱 Ž��
void dfs_mat(GraphType* g, int v) {
	int w;	//v���� ������ ����ã�� ���� ������ ����
	visited[v] = TRUE;		//�湮�����ÿ� 1�� �ִ´�.
	printf("%d->", v);
	for (w = 0; w < g->n; w++) {
		if (g->adj_mat[v][w] && !visited[w])
			dfs_mat(g, w);	//�׷��� g���� ã�� �� w.
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

	dfs_mat(g, 0);
	printf("\n");
	free(g);
}