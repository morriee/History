//20��01��02��
//�׷���-�迭,����ť(bfs)
//(2)���� element�� char������ ������
#include <stdio.h>
#include <stdlib.h>

#define TURE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 5

typedef char element;	//int���� element������ ������
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int rear, front;		//data�߰�:rear, data ����: front
}QueueType;

void queue_init(QueueType* q) {
	/*����ť���� ���� �߿���!
		front, rear�� �ʱⰪ�� 0.
		��, ����ť�� -1���� �����ϹǷ� �ʱⰪ�� -1�ε�.
	*/
	q->front = q->rear = 0;
}

//�ڷᱸ���� �迭�̸� insert �� overflow check!
int is_full(QueueType* q) {		//QueueType *q�� �迭�� ����������ϹǷ�.

	/*
		����ť���� ���� ����� �Ф�
		�츮 �����δ� ���� �ϳ��� ������(�޸� ���� �ϳ��� ��������) ���� ������ ���.
		���� �����Ͱ� ���� front�� �ϳ� �� rear�� �޸� ������ ���ٰ� ģ��.
	*/
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

//�ڷᱸ������ ������ ���� �ÿ��� underflow check!
int is_empty(QueueType* q) {	//QueueType *q�� �迭�� ����������ϹǷ�.
	return (q->front == q->rear);
}
//ť�� ������ ����
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		printf("ť�� ��ȭ������\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}
//ť���� ������ ����, ����
element dequeue(QueueType* q) {
	if (is_empty(q)) {
		printf("ť�� �������\n");
		exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

int main() {
	QueueType q;			//����ü ����: 20byte+8byte
	queue_init(&q);			//QueueType�ȿ� �ִ� ������ �ʱ�ȭ ��Ű�� �ܰ�
	enqueue(&q, 'A');
	enqueue(&q, 'B');
	enqueue(&q, 'C');
	enqueue(&q, 'D');
	enqueue(&q, 'E');
	element ret = dequeue(&q);
	printf("%c\n", ret);	//A
	printf("%c\n", dequeue(&q));	//B
}