//20년01월02일
//그래프-배열,스택(dfs)
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 5

typedef struct GraphType {
	int n;		//정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];		// 배열의 이름
}GraphType;

//전역배열, 0으로 초기화됨
int visited[MAX_VERTICES];	

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

void print_adj_mat(GraphType* g) {
	for (int r = 0; r < MAX_VERTICES; r++) {
		for (int c = 0; c < MAX_VERTICES; c++) {
			printf("%2d ", g->adj_mat[r][c]);

		}
		printf("\n");
	}
}

//정점의 수 증가(단, 에러체크~)
//깊이 우선 탐색
void dfs_mat(GraphType* g, int v) {
	int w;	//v에게 인접한 정점찾기 위해 선언한 변수
	visited[v] = TRUE;		//방문했을시엔 1을 넣는다.
	printf("%d->", v);
	for (w = 0; w < g->n; w++) {
		if (g->adj_mat[v][w] && !visited[w])
			dfs_mat(g, w);	//그래프 g에서 찾은 값 w.
	}
}

int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	//정점 추가
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