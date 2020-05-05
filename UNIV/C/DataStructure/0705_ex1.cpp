//�迭�� Ȱ���Ͽ� ť�� �����(�����ڷ� ť)

#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void init_queue(QueueType *q) {
	q->rear = 0;
	q->front = 0;
}

int is_full(QueueType *q) {
	//�����ִ�.. ������ Ȯ������ ��
	//q->front == q->rear...�̷����ϸ� ����ִ� ���� �ڵ尡 �Ȱ���. 

	//��� +1�� ���ϰ� ��ü ť�������� �������� ����..�����ϱ����� �޸��ϳ�����
	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);	//->�Ǹ�����ť�� ������ ����Ǵ� �ڵ�
}

//�����Լ�
void enqueue(QueueType *q, element ele) {
	//�����͸� �����Ҷ��� �׻� �����ִ��� Ȯ���ؾ���. ����)�����Ҵ�
	//overflow check!!
	if (is_full(q)) {
		printf("ť�� ��������\n");
		return;
	}
	//���⼭ MAX_QUEUE_SIZE���� ����ť.
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;		// 1 2 3 4 0 1 2 ... +1�� �ؼ� �ֱ� ������ 0������ ���� ����
	//ť�� ���� �ִ� data�� �迭���� ť�� ��� ������ �־���..
	q->data[q->rear] = ele;
}

int is_empty(QueueType *q) {
	return (q->front == q->rear);
}

element dequeue(QueueType *q) {
	//underflow check!!
	if (is_empty(q)) {
		printf("ť�� ��� �־��~~\n");
		exit(1);		//return �� �ؾ��ϴµ� element�� ������ ���� �����Ƿ� exit()��.
	}
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;			// 1 2 3 4 0 1 2 ...
		
		//�̰͵� ���ٷ� ���������.
		int ele = q->data[q->front];
		return ele;
	}
}

void queue_print(QueueType *q) {
	printf("QUEUE(front = %d, rear =%d)\n", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;			//���� �� ��.
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;//WHAT?!?!?!
			printf("%3d | ", q->data[i]);		//ť�� ����Ű�� �ִ� �迭 data�� i
			if (i == q->rear) break;		// i�� ���� ť�� ����Ű�� �ִ� ����� ���ٸ� ���⼭ ��� ����
		} while (i != q->front);
	}
	printf("\n");
}

int main() {
	QueueType queue;	//����ü����. 28byte�Ҵ��
	int ele;		//element data��.
	init_queue(&queue);		//����ť�� front, rear �ʱⰪ�� 0���� �Ѵ�.

	printf("ť�� �����͸� �߰��ϴ� �ܰ�\n");

	while(!is_full(&queue)) {		//0�϶� ���̵Ǽ� �Ʒ� �ڵ� ����
		printf("���� �Է�>>");
		scanf_s("%d", &ele);		// ������ 1~4���� �ۿ� �ȵ�...������ ����ť�� �޸� �ϳ� ���ȱ� ������.
		enqueue(&queue, ele);
	}
	printf("ť�� �� �� ������~~~~\n");

	printf("ť���� ������ ���� �ܰ�\n");

	ele = dequeue(&queue);		//1
	printf("ť���� ������ ��=%d\n",ele);		//1
	//  �� ���Ʒ� ele�� dequeue�� ���� ��� �ٸ� ���.

	//ť�迭�� ���
	queue_print(&queue);//->1�� �����ؼ� ������ �ȴ�
	
	printf("ť���� ������ �� = %d\n", dequeue(&queue));		//������ �ѹ��� ��û�����Ƿ� 2�� ����.
	printf("���� ť :");
	queue_print(&queue);
	
	// for������ ���� �ʰ� �̷��� ���� ���� �������� �״�ַ� ��µ�. ���� ���� ����.->�ʱ��̻���.
	enqueue(&queue, 50);	// index 0, rear =0
	enqueue(&queue, 60);	// index 1, rear =1
	queue_print(&queue);	// front= 2, rear =1

	//�̻��� ť
	printf("�̻��� ť\n");		// �迭�� ���������� ������ �̻�����
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		printf("%3d | ", queue.data[i]);
	}
}

