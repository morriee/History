//단순연결 리스트를 사용하여 스택 동적 할당하기.
//강의자료..ppt연결리스트2-p.30

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct StackNode{
	element data;
	struct StackNode *link;		// 연결리스트 노드의 뒤쪽의link부분...자기참조구조체
}StackNode;
typedef struct {
	StackNode *top;		//노드의 주소를 top에 저장
}LinkedStackType;

void init_stack(LinkedStackType *s) {
	s->top = NULL;		// null인 이유: 주솟값이 없기 때문에 -1이 아님
}

void push(LinkedStackType *s, element item) {
	StackNode *temp = (StackNode*)malloc(sizeof(StackNode));		//temp:임시변수..메모리를 담을
	if (temp == NULL) {
		printf("메모리 할당에러\n");
		return;
	}

	//여기까진 메모리만 할당받고 데이터가 저장되어 있지 않으므로 이제부터 데이터저장하는 코드 ㄱㄱ
	temp->data = item;
	temp->link = s->top;		//null-> 노드들이 따로놈
	s->top = temp;	
}

int is_empty(LinkedStackType *s) {
	return (s->top == NULL);
}

//return값이 있으니까 element
element pop(LinkedStackType *s) {
	//underflow check!!
	if (is_empty(s)) {
		printf("스택이 비어있음!\n");
		exit(1);
	}
	StackNode *temp;		//스택에 사용하는 임시변수 temp만듬
	temp = s->top;
	element item = temp->data;		//s->top->data
	s->top = temp->link;		//s->top->link
	free(temp);			//9사라짐
	return item;		//데이터 사라지고 top연결
	//element item = s->top->data;
}

element peek(LinkedStackType *s) {
	//꺼내올 때는 데이터 있는 지 확인한다-->underflow check!!
	if (is_empty(s)) {
		printf("스택이 비어있음. 고로 꺼내줄 데이터없웅\n");
		exit(1);		//return을 주면 반환할께 없기때문에 exit으로 씀.exit()--->stdlib.h
	}
	//스택이 비어있지 않다면..
	else {

		StackNode *temp;		
		temp = s->top;
		element item = temp->data;		
		return item;//return s->top->data;
	}
}

int main() {
	LinkedStackType s;
	init_stack(&s);
	push(&s, 3);
	push(&s, 7);
	push(&s, 9);
	printf("pop value =%d\n",pop(&s));		//9

}

