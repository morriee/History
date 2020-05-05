//�߰���翡�� �� �ڵ� ��ä�� ��.
#include <stdio.h>
#include<stdlib.h>

typedef int element;			//int�� element�� �̸� ������
typedef struct ListNode {
	element data;		//int data
	struct ListNode *link;			//�����Ϸ��� ������ �������� ������ struct ListNode�� ListNode�� ������ �Ѱ��� ��
}ListNode;

ListNode* insert_first(ListNode *head, element value) {		//element value == int value
	//�Լ��� �����͸� �����ҽ� Ÿ���̸����� *�� �ȴ´�.
	//ListNode a1; �̷��� ���� �ʰ� <�����Ҵ�>���� �Ѵ�.
	ListNode *p;
	p =(ListNode*) malloc(sizeof(ListNode));							//malloc(�ʿ��� ũ��), �� ������ �Ҵ���-stdlib.h/standard library, �ּҰ����� �����Ϸ��� �׿� �´� �����ͺ����� �־����.
	//����ȯ�Ѱ�. ����Ʈ��带 *����Ʈ����.
																		//����Ʈ��� Ÿ���� ����Ʈũ�� �Ҵ�
	p->data = value;
	p->link = head;
	head = p;
	return head;
}
void print_list(ListNode* head) {
	for (ListNode *p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("\n");

	/*
printf("%d->", head->data);
	head = head->link;
*/
	  

}
ListNode * search_list(ListNode *head, element x) {
	ListNode *p = head;
	while (p != NULL) {		//p�� null�̸� ������ ������
		if (p->data == x)	return p;
		p = p->link;		//data�� �ƴ϶�link�� ���󰡸� �����Ͱ� ���� �Ǿ�����.
	}
	return NULL;
}

ListNode *delete_first(ListNode *head) {
	ListNode *removed;		//������ ����� �ּ�
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;		// head->link�� ���� �ּ� ����Ŵ.
	free(removed);		//..removed��� �ּҸ� �ع��Ŵ
	return head;		//remobed�� ����� ���ο� �ּҸ� ��ȯ��Ŵ

}

int main() {
	ListNode *head = NULL;		//*head�� ù��° �ּҸ� ��Ÿ��.

	for (int i = 0; i < 5; i++) {		//2�� �ְ� 7�� �־��. (�ǽ�)
		head = insert_first(head, i);
		print_list(head);
	}

	if (search_list(head, 2))	//..4�� ������ ����x������.
		printf("���� ������....\n");
	else
		printf("�������� �ʴ� ����....\n");
	
//	head = insert_first(head, 0);
//	head = insert_first(head, 1);
//	head = insert_first(head, 2);

//	print_list(head);

/*----------------------------------------------------6/27-------------------------------------------------------------*/
	
	head = delete_first(head);		//4�� ����Ű�� �ִ� ��ũ�� ������ ��尡 ��.
	print_list(head);		//3->2->1->0
}

//���� ���� 1,2,3�׷�����

/*0627 ���ð���: ������ ��带 �����ϴ� �Լ� delete()�� �ۼ�*/