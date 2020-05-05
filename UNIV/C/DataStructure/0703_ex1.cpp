//�����Ҵ��Ͽ� ���ø����.
//is_full������. Ȯ���Ұ�.

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
	element  *data;
	int capacity;
	int top;
}StackType;

void init_stack(StackType *s) {
	s->top = -1;	//-1�� �����Ͱ� ���ٴ� �ǹ�
	s->capacity = 1;
	s->data = (element *)malloc(s->capacity * sizeof(element));//->���� �޸��Ҵ��ϴ� ����.
						//			1               4
}

int is_full(StackType *s) {
	//capacity�� �ִ� �뷮.
	return s->top == s->capacity - 1;		//capacity�� �迭�� �����̹Ƿ� �ε�����ȣ�δ� -1 ���̳�.
}

void push(StackType *s, element item) {

	if (is_full(s)) {//is_full �� ���̸�...
		//�޸𸮰� �����ϸ� �뷮(capacity)�� �ø���
		s->capacity *= 2;
		//���� s�� ����Ű�� �������� �ּҿ� ����� �߰�.
		s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++s->top] = item;
}

int is_empty(StackType *s) {
	return (s->top == -1);
}

element pop(StackType *s) {
	if (is_empty(s)) {
		printf("������ �������\n");
		exit(1);
	}
	else {

		printf("���� ����. top ��ġ �ϳ� �Ʒ��� ����");
		return s->data[s->top--];
	}		//s�� ����Ű�� �����Ϳ� s�� ����Ű�� top�� ���� �� ���� ����
}
element peek(StackType *s) {
	if (is_empty(s)) {
		printf("������ �������.\n");
		exit(1);
	}

	else {
		printf("�������� Ȯ��. top��ġ�� �״��");
		return s->data[(s->top)];
	}
}
int main() {
	StackType s;		//element ,int, int ->12����Ʈ �޸� �Ҵ�Ǿ�����
	init_stack(&s);
	for (int i = 1; i <= 10; i++)
		push(&s, i);
	printf("pop value = %d\n", pop(&s));

	//���� �޸� ��ȯ
	free(s.data);		//�����ִ� ������ �ּҸ� ��ȯ��.
}