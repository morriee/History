//배열을 활용하여 큐를 만들기(강의자료 큐)

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
	//꽉차있다.. 눈으로 확인했을 때
	//q->front == q->rear...이렇게하면 비어있는 경우와 코드가 똑같음. 

	//레어에 +1을 더하고 전체 큐사이즈의 나머지와 비교함..구분하기위해 메모리하나포기
	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);	//->맨마지막큐가 앞으로 연결되는 코드
}

//삽입함수
void enqueue(QueueType *q, element ele) {
	//데이터를 삽입할때는 항상 꽉차있는지 확인해야함. 예외)동적할당
	//overflow check!!
	if (is_full(q)) {
		printf("큐가 꽉차있음\n");
		return;
	}
	//여기서 MAX_QUEUE_SIZE빼면 선형큐.
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;		// 1 2 3 4 0 1 2 ... +1을 해서 넣기 때문에 0번부터 들어가지 않음
	//큐가 갖고 있는 data의 배열에서 큐의 레어에 변수를 넣어줌..
	q->data[q->rear] = ele;
}

int is_empty(QueueType *q) {
	return (q->front == q->rear);
}

element dequeue(QueueType *q) {
	//underflow check!!
	if (is_empty(q)) {
		printf("큐가 비어 있어요~~\n");
		exit(1);		//return 을 해야하는데 element와 문법이 맞지 않으므로 exit()임.
	}
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;			// 1 2 3 4 0 1 2 ...
		
		//이것도 한줄로 만들수있음.
		int ele = q->data[q->front];
		return ele;
	}
}

void queue_print(QueueType *q) {
	printf("QUEUE(front = %d, rear =%d)\n", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;			//인출 된 값.
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;//WHAT?!?!?!
			printf("%3d | ", q->data[i]);		//큐가 가리키고 있는 배열 data의 i
			if (i == q->rear) break;		// i의 값이 큐가 가리키고 있는 레어값과 같다면 여기서 계산 멈춤
		} while (i != q->front);
	}
	printf("\n");
}

int main() {
	QueueType queue;	//구조체변수. 28byte할당됌
	int ele;		//element data값.
	init_queue(&queue);		//원형큐의 front, rear 초기값은 0으로 한다.

	printf("큐에 데이터를 추가하는 단계\n");

	while(!is_full(&queue)) {		//0일때 참이되서 아래 코드 수행
		printf("정수 입력>>");
		scanf_s("%d", &ele);		// 데이터 1~4까지 밖에 안들어감...이유는 원형큐로 메모리 하나 버렸기 때문임.
		enqueue(&queue, ele);
	}
	printf("큐가 다 차 있음요~~~~\n");

	printf("큐에서 데이터 삭제 단계\n");

	ele = dequeue(&queue);		//1
	printf("큐에서 인출한 값=%d\n",ele);		//1
	//  요 위아래 ele와 dequeue는 같은 결과 다른 방법.

	//큐배열을 출력
	queue_print(&queue);//->1은 인출해서 나오면 안댐
	
	printf("큐에서 인출한 값 = %d\n", dequeue(&queue));		//삭제를 한번더 요청했으므로 2가 나옴.
	printf("정상 큐 :");
	queue_print(&queue);
	
	// for문으로 찍지 않고 이렇게 값을 딱딱 찍어버리면 그대애로 출력됨. 값이 돌지 않음.->필기이상함.
	enqueue(&queue, 50);	// index 0, rear =0
	enqueue(&queue, 60);	// index 1, rear =1
	queue_print(&queue);	// front= 2, rear =1

	//이상한 큐
	printf("이상한 큐\n");		// 배열을 물리적으로 찍으면 이상해짐
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		printf("%3d | ", queue.data[i]);
	}
}

