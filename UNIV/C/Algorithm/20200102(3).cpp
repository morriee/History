//20년01월02일
//그래프-배열,큐(bfs)
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 5

typedef struct GraphType {
	int n;		//정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];		// 배열의 이름
}GraphType;

typedef int element;	//int형을 element형으로 재정의

typedef struct {
	element queue[MAX_VERTICES];
	int rear, front;		//data추가:rear, data 삭제: front
}QueueType;
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
void queue_init(QueueType* q) {
	/*원형큐에서 완전 중요한!
		front, rear의 초기값은 0.
		단, 직선큐는 -1부터 시작하므로 초기값을 -1로둠.
	*/
	q->front = q->rear = 0;
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

//자료구조가 배열이면 insert 시 overflow check!
int is_full(QueueType* q) {		//QueueType *q는 배열을 전달해줘야하므로.

	/*
		원형큐에서 제일 어려운 ㅠㅠ
		우리 눈으로는 공간 하나가 비지만(메모리 공간 하나를 버리지만) 가장 심플한 방법.
		따라서 데이터가 꽉찬 front와 하나 빈 rear를 메모리 공간이 같다고 친다.
	*/
	return (q->rear + 1) % MAX_VERTICES == q->front;
}

//자료구조에서 데이터 인출 시에는 underflow check!
int is_empty(QueueType* q) {	//QueueType *q는 배열을 전달해줘야하므로.
	return (q->front == q->rear);
}
//큐에 데이터 삽입
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		printf("큐가 포화상태임\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_VERTICES;
	q->queue[q->rear] = item;
}
//큐에서 데이터 인출, 삭제
element dequeue(QueueType* q) {		//0 1 2 3 4
	if (is_empty(q)) {
		printf("큐가 비어있음\n");
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
		v = dequeue(&q);		//맨처음에 꺼내진 애는 0이 들어갓다가 0이 나옴
		for (w = 0; w < g->n; w++) {
			if (g->adj_mat[v][w] && !visited[w]) {
				visited[w] = TRUE;
				printf("%d->", w);		//방문했다고 표시
				enqueue(&q, w);
			}
		}
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

	bfs_mat(g, 0);
	printf("\n");
	free(g);
}