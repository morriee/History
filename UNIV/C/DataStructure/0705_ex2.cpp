//���Ḯ��Ʈ�� Ȱ���Ͽ� ť �����(�����ڷ� ����Ʈ2 ppt39)

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode{
	element data;
	struct QueueNode *link;
}QueueNode;

typedef struct {
	QueueNode *front, *rear;
}LinkedQueueType;

void init(LinkedQueueType *q) {
	q->front = q->rear = NULL;		//���� ���� ���� �ϳ��� �����!
 }

int is_empty(LinkedQueueType *q) {
	return q->front == NULL;		// q->rear�� ���ϴ� ��, �ַ� ť�� ��� ���� �������� �� ��� ������.
}
//underflow check
void enqueue(LinkedQueueType *q, element value) {
	// �����Ҵ�->�����÷ο�üũ����
	QueueNode *temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = value;
	temp->link = NULL;		//�ʱⰪ�� ��������� null...����� ���۵Ǹ� ���⿡ ���� ������?


//ù��° ����϶� temp ��忡 front, rear ��� temp��...
//ù��° ��尡 �ƴϸ�, else����.
	if (is_empty(q)) {
		//ù��° ��忴������..
		q->front = temp;
		q->rear = temp;
	}
	else {		//��尡 �̹� �ϳ� �̻��̶��...��� ���� ���� ������ ����.
		q->rear->link = temp;		//��� �ּҿ� �����Ͽ� temp�� �����ϱ�. ���� �������� ��� �ٲ�.
		q->rear = temp;

	}

}

void print_queue(LinkedQueueType *q) {
	QueueNode *p;	//�����Ͱ� ���� ������ ���� ����.
	p = q->front;
	for (; p != NULL; p = p->link) { // �ʱⰪ ������ �����ϱ�~,......>�⸻�� �ǳ���!!!!�̹��� �����ڤФФ�
		printf("%d->", p->data);
	}
	printf("\n");
}

element dequeue(LinkedQueueType *q) {
	QueueNode *temp = q->front;		//���� �� ��:ť�� ����Ʈ
	element data;
	if (is_empty(q)) {
		printf("ť�� �������\n");
		exit(1);
	}
	else {
		data = q->front->data;		//temp->data�� ����
		//ť�� ����Ű�� �ִ� ����Ʈ�� ������ �ִ� ��ũ���� ����� ��.
		q->front = q->front->link;	//temp->link;
		if (q->front == NULL) q->rear = NULL;		// ����Ʈ�� ���̶�� ���� ��� ��尡 ���� �Ǿ��ٴ� ���̴ϱ� , ��� �η� �ؾ� ��.
		free(temp);
		return data;
	}

}

int main() {
	LinkedQueueType queue;
	init(&queue);

	enqueue(&queue, 1);
	enqueue(&queue, 2);
	enqueue(&queue, 3);
	
	print_queue(&queue);

	element item = dequeue(&queue);
	printf("ť ���Ⱚ: %d\n", item);
	print_queue(&queue);
}


//���Ḯ��Ʈ ť�� ������� �� null, �迭 ť�� ������� �� 0;