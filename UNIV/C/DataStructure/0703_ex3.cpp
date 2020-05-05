//ppt52�����ڵ�
//�����̵����, ���ð�, �̷κ���
// �迭�� ������ ����
//�̷� Ž��

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACKSIZE 10
#define MAZE_SIZE 6

typedef struct {
	int r;	//���ȣ
	int c;	//����ȣ
}element;

typedef struct {
	element data[MAX_STACKSIZE];		//����,ĳ����,����ü ��� �����ϴ� �Ϳ� ���� ���ǉ�. ������ ����ü.
	int top;
}StackType;

//������ �ڷ�, ��������
element here = { 1,0 }, entry = { 1,0 };	//���� ��ġ, ���� ��ġ-->����ü�� �ʱⰪ�� ���������� ����.
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
		printf("������ ������\n");
		return;
	}
	else
		s->data[++s->top] = item;
}

element pop(StackType *s) {
	//underflow check!!
	if (is_empty(s)) {
		printf("������ �������\n");
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
			printf("\n>> �̵� ���: (%d, %d)\n", r, c);
}

void push_loc(StackType *s, int r, int c) {
	//���� ���� �Ѿ�� �迭�� maze���� r�� c�� ���������� ���� �ƴϾ����. ��, 1�� '.'�� �ƴϾ����.
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp;		//����ü�� �ӽú���
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);		//push(s,(r,c))
	}
}

int main() {
	int r, c;
	StackType s;
	init(&s);
	here = entry;		//������ġ�� ������ġ...������ġ�� ��� �ٲ����.

	while (maze[here.r][here.c] != 'x') {		//������ġ�� x�� �ƴϸ� ��� ��.
		r = here.r;
		c = here.c;

		//����θ� Ž�� push_loc()
		//���� here��ġ�� ������ ���� '.'ǥ��
		maze[r][c] = '.';
		print_maze();
		print_route(r, c);
		push_loc(&s, r - 1, c);		//���� �˻�
		push_loc(&s, r + 1, c);		//�Ʒ��� �˻�
		push_loc(&s, r, c - 1);		//���� �˻�
		push_loc(&s, r, c + 1);		//������ �˻�
		//->�� �˻翡 ���� ���ÿ� push,pop�Ҳ���.

		if (is_empty(&s)) {//������ ����ٸ� ���ӳ�
			printf(">> Ż�� ����:(\n");
			return 0;
		}
		else {
			here = pop(&s);		//here�� pop���� ������.(�� ������ ��������)
		}
	}//end while
	printf("---------------------\n");
	printf("\n<< �̷� Ż�� ����!! >>\n");
	return 0;
}