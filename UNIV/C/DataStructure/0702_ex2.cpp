//�ܼ����� ����Ʈ�� ����Ͽ� ���� ���� �Ҵ��ϱ�.
//�����ڷ�..ppt���Ḯ��Ʈ2-p.30

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct StackNode{
	element data;
	struct StackNode *link;		// ���Ḯ��Ʈ ����� ������link�κ�...�ڱ���������ü
}StackNode;
typedef struct {
	StackNode *top;		//����� �ּҸ� top�� ����
}LinkedStackType;

void init_stack(LinkedStackType *s) {
	s->top = NULL;		// null�� ����: �ּڰ��� ���� ������ -1�� �ƴ�
}

void push(LinkedStackType *s, element item) {
	StackNode *temp = (StackNode*)malloc(sizeof(StackNode));		//temp:�ӽú���..�޸𸮸� ����
	if (temp == NULL) {
		printf("�޸� �Ҵ翡��\n");
		return;
	}

	//������� �޸𸮸� �Ҵ�ް� �����Ͱ� ����Ǿ� ���� �����Ƿ� �������� �����������ϴ� �ڵ� ����
	temp->data = item;
	temp->link = s->top;		//null-> ������ ���γ�
	s->top = temp;	
}

int is_empty(LinkedStackType *s) {
	return (s->top == NULL);
}

//return���� �����ϱ� element
element pop(LinkedStackType *s) {
	//underflow check!!
	if (is_empty(s)) {
		printf("������ �������!\n");
		exit(1);
	}
	StackNode *temp;		//���ÿ� ����ϴ� �ӽú��� temp����
	temp = s->top;
	element item = temp->data;		//s->top->data
	s->top = temp->link;		//s->top->link
	free(temp);			//9�����
	return item;		//������ ������� top����
	//element item = s->top->data;
}

element peek(LinkedStackType *s) {
	//������ ���� ������ �ִ� �� Ȯ���Ѵ�-->underflow check!!
	if (is_empty(s)) {
		printf("������ �������. ��� ������ �����;���\n");
		exit(1);		//return�� �ָ� ��ȯ�Ҳ� ���⶧���� exit���� ��.exit()--->stdlib.h
	}
	//������ ������� �ʴٸ�..
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

