//���߿��Ḯ��Ʈ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
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

void dinsert(DlistNode *before, element value) {		//before�� phead��...
	DlistNode *newnode = (DlistNode*)malloc(sizeof(DlistNode));
	//�����͸� ���� �Լ�
	newnode->data = value;	//10
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;

}

void print_dlist(DlistNode *phead) {
	DlistNode *p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("��| |%d| |�� ", p->data);
	}
	printf("\n");
}

int main() {
	DlistNode *head = (DlistNode*)malloc(sizeof(DlistNode));		
	//head�� ���۰� ���� ����ų���ֵ��� left�� right�� ���
	init(head);
	dinsert(head, 10);
	dinsert(head, 20);
	dinsert(head, 30);
	dinsert(head, 40);

	print_dlist(head);
}