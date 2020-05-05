//ppt52과제코드
//스택이동경로, 스택값, 미로변경
// 배열로 구현한 스택
//미로 탐색

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACKSIZE 10
#define MAZE_SIZE 6

typedef struct {
	int r;	//행번호
	int c;	//열번호
}element;

typedef struct {
	element data[MAX_STACKSIZE];		//정수,캐릭터,구조체 등등 정의하는 것에 따라 정의됌. 지금은 구조체.
	int top;
}StackType;

//전역적 자료, 전역변수
element here = { 1,0 }, entry = { 1,0 };	//현재 위치, 시작 위치-->구조체의 초기값을 전역변수로 선언.
char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1','1','1','1','1','1'},
	{'e','0','0','0','0','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','0','0','1','1'},
	{'1','1','1','1','1','1'}

};

void init(StackType *s) {
	s->top = -1;
}

int is_full(StackType *s) {
	return (s->top >= MAX_STACKSIZE - 1);
}

int is_empty(StackType *s) {
	return (s->top == -1);
}

void push(StackType *s, element item) {
	//overflow check!!
	if (is_full(s)) {
		printf("스택이 차있음\n");
		return;
	}
	else
		s->data[++s->top] = item;
}

element pop(StackType *s) {
	//underflow check!!
	if (is_empty(s)) {
		printf("스택이 비어있음\n");
		exit(1); //stdlib.h
	}
	else
		return (s->data[s->top--]);
}

void print_maze() {
	printf("---------------------\n");
	for (int r = 0; r < MAZE_SIZE - 1; r++) {
		for (int c = 0; c < MAZE_SIZE - 1; c++) {
			printf("%3c", maze[r][c]);
		}
		printf("\n");
	}
}
void print_route(int r, int c) {
			printf("\n>> 이동 경로: (%d, %d)\n", r, c);
}

void push_loc(StackType *s, int r, int c) {
	//지금 현재 넘어온 배열의 maze값에 r과 c를 조사했을때 벽이 아니어야함. 즉, 1과 '.'이 아니어야함.
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp;		//구조체의 임시변수
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);		//push(s,(r,c))
	}
}

int main() {
	int r, c;
	StackType s;
	init(&s);
	here = entry;		//현재위치와 시작위치...현재위치가 계속 바뀔것임.

	while (maze[here.r][here.c] != 'x') {		//현재위치가 x가 아니면 계속 감.
		r = here.r;
		c = here.c;

		//사방경로를 탐색 push_loc()
		//현재 here위치를 지나온 곳은 '.'표시
		maze[r][c] = '.';
		print_maze();
		print_route(r, c);
		push_loc(&s, r - 1, c);		//위쪽 검사
		push_loc(&s, r + 1, c);		//아래쪽 검사
		push_loc(&s, r, c - 1);		//왼쪽 검사
		push_loc(&s, r, c + 1);		//오른쪽 검사
		//->이 검사에 따라 스택에 push,pop할꺼임.

		if (is_empty(&s)) {//스택이 비었다면 게임끝
			printf(">> 탈출 실패:(\n");
			return 0;
		}
		else {
			here = pop(&s);		//here의 pop에서 꺼내옴.(단 스택이 차있을시)
		}
	}//end while
	printf("---------------------\n");
	printf("\n<< 미로 탈출 성공!! >>\n");
	return 0;
}