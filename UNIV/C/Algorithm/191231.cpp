//�׷���-�迭
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 4

typedef struct GraphType {
	int n;		//������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICES];		// �迭�� �̸�
}GraphType;

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
			printf("%2d ",g->adj_mat[r][c]);

		}
		printf("\n");
	}
}

//������ �� ����(��, ����üũ~)
int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	//���� �߰�
	for (int i = 0; i < 4; i++) {
		insert_vertex(g, i);
	}
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);

	print_adj_mat(g);
}