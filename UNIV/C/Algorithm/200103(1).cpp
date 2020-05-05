//200103 dijstra algorithm

#include <stdio.h>
#include <limits.h>

#define INF 100000	// ���Ѵ� ��ȣ ���
#define MAX_VERTICES 7
#define TRUE 1
#define FALSE 0

typedef struct GraphType {
	int n;		//������ ��
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int distance[MAX_VERTICES];		//���� ���� 0���� ������ ���������� ���� �ִ� ��� ���� ����
int found[MAX_VERTICES];		//�湮�� ���� ǥ��, ���� s�� �ش�

int choose(int distance[], int n, int found[]) {
	int i, min, minpos;
	min = INT_MAX;		//���ȭ�� ���� �ҷ���. ���� ū��
	minpos = -1;		//0������ �������Ϸ���
	for (int i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;	//���� ���� ���� ��
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
	//distance�� s���տ� ���� �ʱ�ȭ
	for (i = 0; i < g->n; i++) {
		distance[i] = g->weight[start][i];		//���� ������ ���� i���� �� �湮�� ���� �־���.
		found[i] = FALSE;
	}
	found[start] = TRUE;
	distance[start] = 0;

	//�ٽ� �˰���
	for (i = 0; i < g->n; i++) {
		//�ּ� ���߰��� ���� ������ �����ϴ� �Լ� ȣ��
		print_distance(g);
		u = choose(distance, g->n, found);
		found[u] = TRUE;		//4���� �湮�� ���̶� ġ��
		for (w = 0; w < g->n; w++) 
			if (!found[w]) 	//w�� �湮�� ���� ����
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