//200103 dijstra algorithm

#include <stdio.h>
#include <limits.h>

#define INF 100000	// 무한대 기호 대신
#define MAX_VERTICES 7
#define TRUE 1
#define FALSE 0

typedef struct GraphType {
	int n;		//정점의 수
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int distance[MAX_VERTICES];		//시작 정점 0에서 나머지 정점까지에 대한 최단 경로 값을 저장
int found[MAX_VERTICES];		//방문한 정점 표시, 집합 s에 해당

int choose(int distance[], int n, int found[]) {
	int i, min, minpos;
	min = INT_MAX;		//상수화된 값을 불러옴. 가장 큰수
	minpos = -1;		//0번부터 뒤지게하려고
	for (int i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;	//가장 작은 값이 들어감
		}
	}
	return minpos;
}

void print_distance(GraphType *g) {
	for (int i = 0; i < g->n; i++) {
		if (distance[i] == INF)
			printf("%3c", '*');
			//printf("  * ");
		else
			printf("%3d", distance[i]);
	}
		printf("\n");
}

void shortest_path(GraphType* g, int start) {
	int i, u, w;
	//distance와 s집합에 대해 초기화
	for (i = 0; i < g->n; i++) {
		distance[i] = g->weight[start][i];		//시작 값에서 부터 i까지 의 방문한 값을 넣어줌.
		found[i] = FALSE;
	}
	found[start] = TRUE;
	distance[start] = 0;

	//핵심 알고리즘
	for (i = 0; i < g->n; i++) {
		//최소 가중값을 갖는 정점을 선택하는 함수 호출
		print_distance(g);
		u = choose(distance, g->n, found);
		found[u] = TRUE;		//4번은 방문한 것이라 치고
		for (w = 0; w < g->n; w++) 
			if (!found[w]) 	//w에 방문한 적이 없고
				if (distance[u] + g->weight[u][w] < distance[w]) 
					distance[w] = distance[u] + g->weight[u][w];
	}
}



int main() {
	GraphType g = { 7,
	{
		{0, 7, INF, INF, 3, 10, INF},
		{7, 0, 4, 10, 2, 6, INF},
		{INF, 4, 0, 2, INF, INF, INF},
		{INF, 10, 2, 0, 11, 9, 4},
		{3, 2, INF, 11, 0, INF, 5},
		{10, 6, INF, 9, INF, 0, INF},
		{INF, INF, INF, 4, 5, INF, 0}
	}

	};
	shortest_path(&g, 0);
}