//�׷���-���Ḯ��Ʈ

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 4

typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType {
	int n;	//������ ����
	GraphNode* adj_list[MAX_VERTICES];		//�迭�� ���� ������ �����͸� ������.
};

void init(GraphType* g) {
	g->n = NULL;
	for (int v = 0; v < MAX_VERTICES; v++) {
		g->adj_list[v] = NULL;
	}
}

void insert_vertex(GraphType* g, int v) {
	if ((g->n + 1) > MAX_VERTICES) {
		printf("�׷��� ���� ���� �ʰ�\n");	//����üũ
		return;
	}
	g->n++;
}

//���Ḯ��Ʈ ������ �����.
void insert_edge(GraphType* g, int u, int v) {
	//0,1�� ���� ������ ���� ������.(������ ����޾ƾ� �ǹǷ�)
	//�޸� �Ҵ�
	GraphNode* node;
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];		//g->adj_list[0]
	g->adj_list[u] = node;
}

void print_adj_list(GraphType* g) {
	for (int i = 0; i < MAX_VERTICES; i++) {
		GraphNode* p = g->adj_list[i];
		printf("���� %d ", i);
		while (p!= NULL) {
			printf("-> %2d ", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}

//������ �� ����(��, ����üũ~)
int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);	//

	for (int v = 0; v < MAX_VERTICES; v++) {
		insert_vertex(g, v);
	}
	//��������
	insert_edge(g, 0, 1);
	insert_edge(g, 1, 0);
	insert_edge(g, 0, 2);
	insert_edge(g, 2, 0);
	insert_edge(g, 0, 3);
	insert_edge(g, 3, 0);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 3, 2);

	print_adj_list(g);
}