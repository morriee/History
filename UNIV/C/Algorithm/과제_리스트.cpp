//그래프-인접리스트

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 3

typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType {
	int n;	//정점의 개수
	GraphNode* adj_list[MAX_VERTICES];		//배열에 행의 각각에 포인터를 연결함.
};

void init(GraphType* g) {
	g->n = NULL;
	for (int v = 0; v < MAX_VERTICES; v++) {
		g->adj_list[v] = NULL;
	}
}

void insert_vertex(GraphType* g, int v) {
	if ((g->n + 1) > MAX_VERTICES) {
		printf("그래프 정점 개수 초과\n");	//에러체크
		return;
	}
	g->n++;
}

//연결리스트 구현과 비슷함.
void insert_edge(GraphType* g, int u, int v) {
	//0,1을 받을 공간을 먼저 만들어라.(간선을 연결받아야 되므로)
	//메모리 할당
	GraphNode* node;
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];		//g->adj_list[0]
	g->adj_list[u] = node;
}

//진입차수
void in_degree(GraphType* g) {
	int degree;
	printf("진입차수 >> \n");
	for (int v = 0; v < MAX_VERTICES; v++) {
		degree = 0;
		if (g->adj_list[v]) {
			degree++;
		}
	}
	printf("%d ", degree);
	
	printf("\n\n");
}

//진출차수
void out_degree(GraphType* g) {
	int degree;
	printf("진출차수 >> \n");
	for (int v = 0; v < MAX_VERTICES; v++) {
		degree = 0;
		if (g->adj_list[v]) {
			degree++;
		}
	}
	printf("%d ", degree);
}

void print_adj_list(GraphType* g) {
	printf("연결리스트 >> \n");
	for (int i = 0; i < MAX_VERTICES; i++) {
		GraphNode* p = g->adj_list[i];
		printf("정점 %d ", i);
		while (p != NULL) {
			printf("-> %2d ", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}

//정점의 수 증가(단, 에러체크~)
int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);	//

	for (int v = 0; v < MAX_VERTICES; v++) {
		insert_vertex(g, v);
	}
	//간선연결
	insert_edge(g, 0, 1);
	insert_edge(g, 1, 0);
	insert_edge(g, 1, 2);

	print_adj_list(g);
	printf("\n");
	out_degree(g);
	printf("\n\n");
}