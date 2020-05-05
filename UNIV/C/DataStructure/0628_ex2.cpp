//스택

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACKSIZE 5		//굉장히 편리하게 배열의 크기를 늘릴수 있음
typedef int element;

//구조체 정의함.아직 메모리할당 안함.->메인에서
typedef struct {
	element data[MAX_STACKSIZE];		//4*5=20byte
	int top;	//4byte
}StackType;			//stacktype이라고 앞에는 안줘도 뒤에만 이름재정의 해도 됨.(c문법)

void init(StackType *s) {
	s->top = -1;		//s의 top의 값을 -1로 초기화 하시오. 주소로 넘어와서 포인터로 메모리가 공유되니까 점이 아니라 화살표로 사용.
}

int is_full(StackType *s) {
	return (s->top >= MAX_STACKSIZE - 1);	//...자료구조는 함수를 뽑을 수 있을 때까진 다 뽑아씀.
}

void push(StackType *s, element item) {	//StackType s라고 하면 또 메모리를 할당하는 거임. main의 push와 관련없는 메모리가 또! 생기는 것임. 그러니까 주소로 연결하여 하나의 메모리로 공유한다.
	//overflow check!!
	if (is_full(s)) {		
		printf("스택이 꽉차 있음..\n");
		return;
	}
	else {
		//구조체는 다 점인데 포인터를 사용하니 화살표로 연결하는것.
		//스택(s)을 1증가 시켜서 0으로 만들고 data를 넣는다.
		s->data[++s->top] = item;		// s->top = s->top + 1; 
	}
}

int is_empty(StackType *s) {
	return (s->top == -1);
}

element pop(StackType *s) {
	//꺼내올 때는 데이터 있는 지 확인한다-->underflow check!!
	if (is_empty(s)) {
		printf("스택이 비어있음. 고로 꺼내줄 데이터없웅\n");
		exit(1);		//return을 주면 반환할께 없기때문에 exit으로 씀.exit()--->stdlib.h
	}
	//스택이 비어있지 않다면..
	else {
		return s->data[(s->top)--];		// s가 가리키는 data배열에 s가 가리키는 top을 하나씩 감소.
		/* 아래 코드는 바로 위의 코드와 동일한 코드
		int item = s->data[s->top];		//스택(s)에 있는 데이터중 top의 위치에 있는 것을 꺼내 item에 넣ㄴ는다.
		s->top--;		//꺼냇으니top--;
		return item;
		*/
	}
}

element peek(StackType *s) {
	//꺼내올 때는 데이터 있는 지 확인한다-->underflow check!!
	if (is_empty(s)) {
		printf("스택이 비어있음. 고로 꺼내줄 데이터없웅\n");
		exit(1);		//return을 주면 반환할께 없기때문에 exit으로 씀.exit()--->stdlib.h
	}
	//스택이 비어있지 않다면..
	else {
		return s->data[(s->top)];		//top에 뭐가 있는 지 확인만 하는거니까, top--를 하지 않는다. pop과의 유일한 차이점
	}
}

void print_stack(StackType *s) {
	for (int i = s->top; i >= 0; i--) {
		printf("%3d", s->data[i]);
	}
	printf("\n --스택의 top값 = %d--\n", s->data[s->top]);		//3
}

int main() {
	StackType s;		//총 24byte
	init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	//스택의 배열값을 출력하시오

	for (int i = s.top; i >=0; i--) {		//i< MAX_STACKSIZE까지 하면 4,5는 없으니 쓰레기 값이 나옴.
		printf("%3d", s.data[i]);		//main에서의 s는 구조체 변!수!임.그래서 화살표가 아니라 점임. 
	}
	printf("\n스택의 top값 = %d\n", s.data[s.top]);		//3

	push(&s, 4);
	push(&s, 5);
	push(&s, 6);
	


	//스택의 배열값을 출력하시오.---->함수 pirnt_stack(&s) 로 만들기
	for (int i = s.top; i >= 0; i--) {
		printf("%3d", s.data[i]);
	}
	printf("\npop value=%d\n", pop(&s));		//4
	
	//peek함수만들기
	printf("peek value=%d\n", peek(&s));		//3
	
	//스택의 배열값을 출력하시오.
	for (int i = s.top; i >= 0; i--) {
		printf("%3d", s.data[i]);
	}

	//->함수 pirnt_stack(&s) 로 만들기
	print_stack(&s);
}
