#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
}ListNode;

ListNode *insert_first(ListNode *head, element value) {
	ListNode *node = (ListNode*)malloc(sizeof(ListNode));

	node->data = value;
	if (head == NULL) {	//ù���� ����ΰ��, �������Ḯ��Ʈ�� null�ּҰ� ����.
		head = node;
		node->link = head;		///node->link=node;		//ù���� �ڱⰡ �ڱ��ڽ��� ����Ų��.
	}
	else {
		node->link = head->link;
		head->link = node;//��尡 ����Ű�� ��ũ���� ���ο� ��忡
		//head=node;���� ù ��°  �Էµ� ��带 ����Ŵ
	}
	return head;
}

ListNode *insert_last(ListNode *head, element value) {
	ListNode *node = (ListNode*)malloc(sizeof(ListNode));

	node->data = value;
	if (head == NULL) {	//ù���� ����ΰ��, �������Ḯ��Ʈ�� null�ּҰ� ����.
		head = node;
		node->link = head;		///node->link=node;		//ù���� �ڱⰡ �ڱ��ڽ��� ����Ų��.
	}
	else {
		node->link = head->link;
		head->link = node;//��尡 ����Ű�� ��ũ���� ���ο� ��忡
		head = node;
	}
	return head;
}

void print_list(ListNode *head) {
	//���� ���� �����ؼ� ó������ �Դ�.(�ѹ������Ҵٴ� �ǹ�.�� ��� �����.)
	ListNode *p;
	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);	//last�ϰ�� �� ������ ��尡 ��������. �ֳ��ϸ� ��尡 ��������忡 �ֱ� ����
		p = p->link;
	} while (p != head);
	printf("%d\n\n", p->data);
}

int main() {
	ListNode *head = NULL;

	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	print_list(head);

	head = insert_first(head, 10);
	print_list(head);
}