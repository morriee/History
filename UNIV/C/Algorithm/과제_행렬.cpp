//그래프-인접행렬
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 3

typedef struct GraphType {
	int n;		//정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];		// 배열의 이름
}GraphType;

void init(GraphType* g) {
	g->n = 0;	//n=0 안됨. g가 가지고 온 n은 0이다.
	for (int r = 0; r < MAX_VERTICES; r++) {
		for (int c = 0; c < MAX_VERTICES; c++) {
			g->adj_mat[r][c] = 0;		//g가 가리키는 배열은 0이다.
		}
	}
}

void insert_vertex(GraphType* g, int v) {
	if ((g->n + 1) > MAX_VERTICES) {
		printf("그래프 정점개수 초과\n");
		return;
	}
	g->n++;		// n의 개수를 하나씩 추가하고 싶은데 max를 4로 뒀으니 그 4이하일때만 추가할 수 있도록 코드를 짬.
}

void insert_edge(GraphType* g, int start, int end) {
	if (start >= g->n || end >= g->n) {
		printf("그래프 정점 번호 오류\n");
		return;
	}
	g->adj_mat[start][end] = 1;		//g가 가리키고있는 인접행렬이 존재한다(를 1을 대입하는 것으로 표시)
	g->adj_mat[end][start] = 1;
}


//진입차수
void in_degree(GraphType* g) {
	int degree;
	printf("진입차수 >> \n");
	for (int i = 0; i < g->n; i++) {
		degree = 0;	//초기화
		for (int j = 0; j < g->n; j++) {
			if (g->adj_mat[j][i]) {
				degree++;	//차수1증가
			}
		}
			printf("%d ", degree);
	}
	printf("\n\n");
}

//진출차수
void out_degree(GraphType* g) {
	int degree;
	printf("진출차수 >> \n");
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
	printf("배열 >> \n");
	for (int r = 0; r < MAX_VERTICES; r++) {
		for (int c = 0; c < MAX_VERTICES; c++) {
			printf("%2d ", g->adj_mat[r][c]);
		}
		printf("\n");
	}
}

//정점의 수 증가(단, 에러체크~)
int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	//정점 추가
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