//������ Ȱ��
//2.����ǥ��� ���

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACKSIZE 10
typedef char element;		//������ Ÿ���� ������ �ٲ��� �ʾƵ���.(0701)

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
		int item = s->data[s->top];		//����(s)�� �ִ� �������� top�� ��ġ�� �ִ� ���� ���� item�� �ִ´�.
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

int check_matching(const char *in) {//0701
	StackType s;
	init(&s);
	char ch, open_ch;
	int n = strlen(in);		//{a[(i+1)]=0;} --> ���ڿ����� 13, string.h
	for (int i = 0; i < n; i++) {
		ch = in[i];		//ù��° ���ڸ� ch�� ����.

		//��ȣ�� ������ ����
		switch (ch)
		{
			//���� ���
		case '(': case '[': case '{':	//���� ������ �ѹ��� ������ �ִ�.
			push(&s, ch);
			break;

			//���� ���
		case ')': case ']': case '}':

			//������ ���������,,
			if (is_empty(&s)) return 0; //��ȣ�����߻�

			//������ ������...
			else {
				open_ch = pop(&s);

				//������ ��ȣ�� ¦���� �´��� Ȯ��
				if ((open_ch == '(' && ch != ')') ||		//������ ch�� ���� ���� ch�� �ٸ� ���(���⼭ ch�� ��ȣ�� �������.. ��ȣ�� ���ڿ��� ġȯ�Ѱ�.
					(open_ch == '[' && ch != ']') ||
					(open_ch == '{' && ch != '}'))
					return 0; //��ȣ ���� �߻��ϰ��-->break;
			}
			break;
		}
	}

	//���ÿ� ���� ���� �ִٸ�...
	if (!is_empty(&s)) return 0;		//��ȣ ���� �߻�...������ ��� ���� �ڿ��� ���ÿ� ��ȣ�� �����ִ� ���
	return 1;		// ������ �ùٸ��� �� �Ǿ������� 1��ȯ.
}

int eval(const char exp[]) {		//0701....exp[]: ���ڿ��� ������ �迭
	StackType s;
	init(&s);
	int op1, op2, value;
	char ch;
	int len = strlen(exp);		//82/3-32*+ ---> ���ڿ����� 9
	for (int i = 0; i < len; i++) {
		ch = exp[i];		//i�� 0�ϰ�� ���ڿ��� �� ù��°�� 8�� ��.

		//4���� �����ڰ� �ƴϸ� �����̴�.
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			value = ch - '0';		//���ڷμ��� 8�� ���ڷ� �ٲ۰�.(�ƽ�Ű�ڵ�����)
			push(&s,value);
		}

		//���࿡ �� �κ�(ó���� 0��° �κ�)�� �����ڰ� �ƴ϶��...
		else {
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch)
			{
				//������ �������� ��� �׿� �´� ������ �� �� ���ÿ� �ִ´�.
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
	printf("���� 82/3-32*+ �� ��� = %d\n",result1);		//7
	
	int result2 = eval("2584/*+72*-");
	printf("���� 2584/*+72*- �� ��� = %d\n", result2);		//-2
}
