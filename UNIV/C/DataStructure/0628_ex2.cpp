//����

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACKSIZE 5		//������ ���ϰ� �迭�� ũ�⸦ �ø��� ����
typedef int element;

//����ü ������.���� �޸��Ҵ� ����.->���ο���
typedef struct {
	element data[MAX_STACKSIZE];		//4*5=20byte
	int top;	//4byte
}StackType;			//stacktype�̶�� �տ��� ���൵ �ڿ��� �̸������� �ص� ��.(c����)

void init(StackType *s) {
	s->top = -1;		//s�� top�� ���� -1�� �ʱ�ȭ �Ͻÿ�. �ּҷ� �Ѿ�ͼ� �����ͷ� �޸𸮰� �����Ǵϱ� ���� �ƴ϶� ȭ��ǥ�� ���.
}

int is_full(StackType *s) {
	return (s->top >= MAX_STACKSIZE - 1);	//...�ڷᱸ���� �Լ��� ���� �� ���� ������ �� �̾ƾ�.
}

void push(StackType *s, element item) {	//StackType s��� �ϸ� �� �޸𸮸� �Ҵ��ϴ� ����. main�� push�� ���þ��� �޸𸮰� ��! ����� ����. �׷��ϱ� �ּҷ� �����Ͽ� �ϳ��� �޸𸮷� �����Ѵ�.
	//overflow check!!
	if (is_full(s)) {		
		printf("������ ���� ����..\n");
		return;
	}
	else {
		//����ü�� �� ���ε� �����͸� ����ϴ� ȭ��ǥ�� �����ϴ°�.
		//����(s)�� 1���� ���Ѽ� 0���� ����� data�� �ִ´�.
		s->data[++s->top] = item;		// s->top = s->top + 1; 
	}
}

int is_empty(StackType *s) {
	return (s->top == -1);
}

element pop(StackType *s) {
	//������ ���� ������ �ִ� �� Ȯ���Ѵ�-->underflow check!!
	if (is_empty(s)) {
		printf("������ �������. ��� ������ �����;���\n");
		exit(1);		//return�� �ָ� ��ȯ�Ҳ� ���⶧���� exit���� ��.exit()--->stdlib.h
	}
	//������ ������� �ʴٸ�..
	else {
		return s->data[(s->top)--];		// s�� ����Ű�� data�迭�� s�� ����Ű�� top�� �ϳ��� ����.
		/* �Ʒ� �ڵ�� �ٷ� ���� �ڵ�� ������ �ڵ�
		int item = s->data[s->top];		//����(s)�� �ִ� �������� top�� ��ġ�� �ִ� ���� ���� item�� �֤��´�.
		s->top--;		//��������top--;
		return item;
		*/
	}
}

element peek(StackType *s) {
	//������ ���� ������ �ִ� �� Ȯ���Ѵ�-->underflow check!!
	if (is_empty(s)) {
		printf("������ �������. ��� ������ �����;���\n");
		exit(1);		//return�� �ָ� ��ȯ�Ҳ� ���⶧���� exit���� ��.exit()--->stdlib.h
	}
	//������ ������� �ʴٸ�..
	else {
		return s->data[(s->top)];		//top�� ���� �ִ� �� Ȯ�θ� �ϴ°Ŵϱ�, top--�� ���� �ʴ´�. pop���� ������ ������
	}
}

void print_stack(StackType *s) {
	for (int i = s->top; i >= 0; i--) {
		printf("%3d", s->data[i]);
	}
	printf("\n --������ top�� = %d--\n", s->data[s->top]);		//3
}

int main() {
	StackType s;		//�� 24byte
	init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	//������ �迭���� ����Ͻÿ�

	for (int i = s.top; i >=0; i--) {		//i< MAX_STACKSIZE���� �ϸ� 4,5�� ������ ������ ���� ����.
		printf("%3d", s.data[i]);		//main������ s�� ����ü ��!��!��.�׷��� ȭ��ǥ�� �ƴ϶� ����. 
	}
	printf("\n������ top�� = %d\n", s.data[s.top]);		//3

	push(&s, 4);
	push(&s, 5);
	push(&s, 6);
	


	//������ �迭���� ����Ͻÿ�.---->�Լ� pirnt_stack(&s) �� �����
	for (int i = s.top; i >= 0; i--) {
		printf("%3d", s.data[i]);
	}
	printf("\npop value=%d\n", pop(&s));		//4
	
	//peek�Լ������
	printf("peek value=%d\n", peek(&s));		//3
	
	//������ �迭���� ����Ͻÿ�.
	for (int i = s.top; i >= 0; i--) {
		printf("%3d", s.data[i]);
	}

	//->�Լ� pirnt_stack(&s) �� �����
	print_stack(&s);
}
