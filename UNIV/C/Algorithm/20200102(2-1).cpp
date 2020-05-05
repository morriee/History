//20년01월02일
//그래프-배열,원형큐(bfs)
//(2)에서 element를 char형으로 변경함
#include <stdio.h>
#include <stdlib.h>

#define TURE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 5

typedef char element;	//int형을 element형으로 재저의
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int rear, front;		//data추가:rear, data 삭제: front
}QueueType;

void queue_init(QueueType* q) {
	/*원형큐에서 완전 중요한!
		front, rear의 초기값은 0.
		단, 직선큐는 -1부터 시작하므로 초기값을 -1로둠.
	*/
	q->front = q->rear = 0;
}

//자료구조가 배열이면 insert 시 overflow check!
int is_full(QueueType* q) {		//QueueType *q는 배열을 전달해줘야하므로.

	/*
		원형큐에서 제일 어려운 ㅠㅠ
		우리 눈으로는 공간 하나가 비지만(메모리 공간 하나를 버리지만) 가장 심플한 방법.
		따라서 데이터가 꽉찬 front와 하나 빈 rear를 메모리 공간이 같다고 친다.
	*/
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
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
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}
//큐에서 데이터 인출, 삭제
element dequeue(QueueType* q) {
	if (is_empty(q)) {
		printf("큐가 비어있음\n");
		exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

int main() {
	QueueType q;			//구조체 변수: 20byte+8byte
	queue_init(&q);			//QueueType안에 있는 변수들 초기화 시키는 단계
	enqueue(&q, 'A');
	enqueue(&q, 'B');
	enqueue(&q, 'C');
	enqueue(&q, 'D');
	enqueue(&q, 'E');
	element ret = dequeue(&q);
	printf("%c\n", ret);	//A
	printf("%c\n", dequeue(&q));	//B
}