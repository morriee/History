//�׷���-�������
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 3

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


//��������
void in_degree(GraphType* g) {
	int degree;
	printf("�������� >> \n");
	for (int i = 0; i < g->n; i++) {
		degree = 0;	//�ʱ�ȭ
		for (int j = 0; j < g->n; j++) {
			if (g->adj_mat[j][i]) {
				degree++;	//����1����
			}
		}
			printf("%d ", degree);
	}
	printf("\n\n");
}

//��������
void out_degree(GraphType* g) {
	int degree;
	printf("�������� >> \n");
	for (int i = 0; i < g->n; i++) {
		degree = 0;
		for (int j = 0; j < g->n; j++) {
			if (g->adj_mat[i][j])
				degree++;
		}
		printf("%d ", degree);
	}
	printf("\n\n");
}

void print_adj_mat(GraphType* g) {
	printf("�迭 >> \n");
	for (int r = 0; r < MAX_VERTICES; r++) {
		for (int c = 0; c < MAX_VERTICES; c++) {
			printf("%2d ", g->adj_mat[r][c]);
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
	for (int i = 0; i < MAX_VERTICES; i++) {
		insert_vertex(g, i);
	}
	insert_edge(g, 0, 1);
	insert_edge(g, 1, 0);
	insert_edge(g, 1, 2);

	print_adj_mat(g);
	printf("\n");

	in_degree(g);
	out_degree(g);
}