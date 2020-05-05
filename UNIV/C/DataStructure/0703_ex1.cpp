//동적할당하여 스택만들기.
//is_full수정함. 확인할것.

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
	element  *data;
	int capacity;
	int top;
}StackType;

void init_stack(StackType *s) {
	s->top = -1;	//-1은 데이터가 없다는 의미
	s->capacity = 1;
	s->data = (element *)malloc(s->capacity * sizeof(element));//->힙에 메모리할당하는 과정.
						//			1               4
}

int is_full(StackType *s) {
	//capacity는 최대 용량.
	return s->top == s->capacity - 1;		//capacity가 배열의 개수이므로 인덱스번호로는 -1 차이남.
}

void push(StackType *s, element item) {

	if (is_full(s)) {//is_full 이 참이면...
		//메모리가 부족하면 용량(capacity)을 늘리자
		s->capacity *= 2;
		//현재 s가 가리키는 데이터의 주소에 사이즈를 추가.
		s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++s->top] = item;
}

int is_empty(StackType *s) {
	return (s->top == -1);
}

element pop(StackType *s) {
	if (is_empty(s)) {
		printf("스택이 비어잇음\n");
		exit(1);
	}
	else {

		printf("스택 있음. top 위치 하나 아래로 감소");
		return s->data[s->top--];
	}		//s가 가리키는 데이터에 s가 가리키는 top을 빼낸 후 개수 감소
}
element peek(StackType *s) {
	if (is_empty(s)) {
		printf("스택이 비어있음.\n");
		exit(1);
	}

	else {
		printf("스택있음 확인. top위치는 그대로");
		return s->data[(s->top)];
	}
}
int main() {
	StackType s;		//element ,int, int ->12바이트 메모리 할당되어있음
	init_stack(&s);
	for (int i = 1; i <= 10; i++)
		push(&s, i);
	printf("pop value = %d\n", pop(&s));

	//동적 메모리 반환
	free(s.data);		//힙에있는 데이터 주소를 반환함.
}