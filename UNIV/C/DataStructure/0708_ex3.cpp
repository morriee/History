//mp3������α׷������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[50];
typedef struct DlistNode {	//double list node
	struct DlistNode *llink;		//left link
	element data;
	struct DlistNode *rlink;		//right link
}DlistNode;

//llink,rlink ��� �ڱ��ڽ��� �ּҰ��� ������ �ʱ�ȭ
void init(DlistNode *phead) {
	//��� ����.
	phead->llink = phead;
	phead->rlink = phead;
}
DlistNode *current;		//��������

void dinsert(DlistNode *before, const element value) {		//before�� phead��...
	DlistNode *newnode = (DlistNode*)malloc(sizeof(DlistNode));
	//�����͸� ���� �Լ�
	strcpy(newnode->data, value);		//������ ���� ������ ������ ���ڿ��� �����ؾ��� element���� ���̸�
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;

}

void ddelete(DlistNode *head, DlistNode *removed) {
	if (head == removed) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

void print_list(DlistNode *phead) {
	//���� �÷��� �ǰ� �ִ� ���� #��ȣ �ֱ�.
	DlistNode *p;
	for (p = phead->rlink; p != phead; p = p->rlink) {		// �� �ڵ尡 ��带 �ѹ����� ����. Ž���Ⱑ �ѹ��� ���Ҵ� ��.�ѹ� �� �Ⱦ���.
		if (p == current) {
			printf("��|# %s #|��", p->data);
		}
		else { printf("��| %s |��", p->data); }
		printf("\n");
	}

}

int main() {
	DlistNode *head = (DlistNode*)malloc(sizeof(DlistNode));
	//head�� ���۰� ���� ����ų���ֵ��� left�� right�� ���
	init(head);
	dinsert(head, "������");//const
	dinsert(head, "�ѷ��ڽ���");
	dinsert(head, "12��");

	current = head->rlink;	//ù��° ���� 12��
	print_list(head);

	char ch;
	do {
		printf("����� �Է��Ͻÿ�.(<,>,q):  ");
		ch = getchar();		// getchar�� �ѱ��� �Է¹���
		if (ch == '<') {
			//���� �� ����
			current = current->llink;	//���� ���� ����== ���� ���� ����
			if (current == head) {		//���� ���� ���� ������..
				current = current->llink;
			}
		}
		else if (ch == '>'){
			//���� �� ����
			current = current ->rlink;	
			//�� ������ ��� ���� ���� ������ head�� ����.head���� ���� ����
			if (current == head) {
				current = current->rlink;
			}
		}
		print_list(head);
		getchar();	// ���ۿ� enterŰ�� �������� �ʰ� �ϴ� �ڵ�
	} while (ch != 'q');	//ť�� �ƴ� ��쿡 ���� ����.
}