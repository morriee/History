//스택의 활용
//2.후위표기법 계산

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACKSIZE 10
typedef char element;		//데이터 타입을 일일히 바꾸지 않아도됌.(0701)

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
		int item = s->data[s->top];		//스택(s)에 있는 데이터중 top의 위치에 있는 것을 꺼내 item에 넣는다.
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

int check_matching(const char *in) {//0701
	StackType s;
	init(&s);
	char ch, open_ch;
	int n = strlen(in);		//{a[(i+1)]=0;} --> 문자열길이 13, string.h
	for (int i = 0; i < n; i++) {
		ch = in[i];		//첫번째 문자를 ch에 넣음.

		//괄호의 성분을 조사
		switch (ch)
		{
			//열린 경우
		case '(': case '[': case '{':	//같은 성분은 한번에 모을수 있다.
			push(&s, ch);
			break;

			//닫힌 경우
		case ')': case ']': case '}':

			//스택이 비어있으면,,
			if (is_empty(&s)) return 0; //괄호오류발생

			//스택이 있으면...
			else {
				open_ch = pop(&s);

				//꺼내온 괄호가 짝꿍이 맞는지 확인
				if ((open_ch == '(' && ch != ')') ||		//기존의 ch와 새로 넣은 ch와 다를 경우(여기서 ch엔 괄호가 들어있음.. 괄호를 문자열로 치환한것.
					(open_ch == '[' && ch != ']') ||
					(open_ch == '{' && ch != '}'))
					return 0; //괄호 오류 발생일경우-->break;
			}
			break;
		}
	}

	//스택에 뭔가 남아 있다면...
	if (!is_empty(&s)) return 0;		//괄호 오류 발생...연산이 모두 끝난 뒤에도 스택에 괄호가 남아있는 경우
	return 1;		// 수식이 올바르게 잘 되어있을때 1반환.
}

int eval(const char exp[]) {		//0701....exp[]: 문자열을 저장할 배열
	StackType s;
	init(&s);
	int op1, op2, value;
	char ch;
	int len = strlen(exp);		//82/3-32*+ ---> 문자열길이 9
	for (int i = 0; i < len; i++) {
		ch = exp[i];		//i가 0일경우 문자열의 맨 첫번째인 8이 들어감.

		//4개의 연산자가 아니면 숫자이다.
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			value = ch - '0';		//문자로서의 8을 숫자로 바꾼것.(아스키코드참고)
			push(&s,value);
		}

		//만약에 이 부분(처음엔 0번째 부분)에 연산자가 아니라면...
		else {
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch)
			{
				//각각의 연산자일 경우 그에 맞는 연산을 한 후 스택에 넣는다.
			case '+': push(&s, op1 + op2); break;
			case '-': push(&s, op1 - op2); break;
			case '*': push(&s, op1 * op2); break;
			case '/': push(&s, op1 / op2); break;
			
			}
		}
	}
	return pop(&s);
}

int main() {
	int result1 = eval("82/3-32*+");
	printf("연산 82/3-32*+ 의 결과 = %d\n",result1);		//7
	
	int result2 = eval("2584/*+72*-");
	printf("연산 2584/*+72*- 의 결과 = %d\n", result2);		//-2
}
