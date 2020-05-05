//연결리스트를 활용하여 큐 만들기(강의자료 리스트2 ppt39)

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
	q->front = q->rear = NULL;		//새로 받은 노드는 하나도 없어요!
 }

int is_empty(LinkedQueueType *q) {
	return q->front == NULL;		// q->rear를 안하는 건, 주로 큐가 비는 것은 삭제했을 때 비기 때문임.
}
//underflow check
void enqueue(LinkedQueueType *q, element value) {
	// 동적할당->오버플로우체크안함
	QueueNode *temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = value;
	temp->link = NULL;		//초기값은 비어있으니 null...계산이 시작되면 여기에 값이 들어가겠지?


//첫번째 노드일때 temp 노드에 front, rear 모두 temp로...
//첫번째 노드가 아니면, else실행.
	if (is_empty(q)) {
		//첫번째 노드였을때만..
		q->front = temp;
		q->rear = temp;
	}
	else {		//노드가 이미 하나 이상이라면...레어에 대한 값을 연결을 해줌.
		q->rear->link = temp;		//레어를 주소에 연결하여 temp와 연결하기. 값이 들어갈때마다 레어가 바뀜.
		q->rear = temp;

	}

}

void print_queue(LinkedQueueType *q) {
	QueueNode *p;	//포인터값 넣을 포인터 변수 만듬.
	p = q->front;
	for (; p != NULL; p = p->link) { // 초기값 정해져 있으니까~,......>기말에 또낸대!!!!이번에 맞추자ㅠㅠㅠ
		printf("%d->", p->data);
	}
	printf("\n");
}

element dequeue(LinkedQueueType *q) {
	QueueNode *temp = q->front;		//삭제 될 값:큐의 프론트
	element data;
	if (is_empty(q)) {
		printf("큐가 비어있음\n");
		exit(1);
	}
	else {
		data = q->front->data;		//temp->data와 같음
		//큐가 가리키고 있는 프론트가 가지고 있는 링크값을 덮어쓰면 됌.
		q->front = q->front->link;	//temp->link;
		if (q->front == NULL) q->rear = NULL;		// 프론트가 널이라는 것은 모든 노드가 삭제 되었다는 뜻이니까 , 레어도 널로 해야 함.
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
	printf("큐 인출값: %d\n", item);
	print_queue(&queue);
}


//연결리스트 큐는 비어있을 때 null, 배열 큐는 비어있을 때 0;