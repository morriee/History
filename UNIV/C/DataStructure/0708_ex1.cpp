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
	if (head == NULL) {	//첫번재 노드인경우, 원형연결리스트는 null주소가 없음.
		head = node;
		node->link = head;		///node->link=node;		//첫노드는 자기가 자기자신을 가리킨다.
	}
	else {
		node->link = head->link;
		head->link = node;//헤드가 가리키는 링크값을 새로운 노드에
		//head=node;헤드는 첫 번째  입력된 노드를 가리킴
	}
	return head;
}

ListNode *insert_last(ListNode *head, element value) {
	ListNode *node = (ListNode*)malloc(sizeof(ListNode));

	node->data = value;
	if (head == NULL) {	//첫번재 노드인경우, 원형연결리스트는 null주소가 없음.
		head = node;
		node->link = head;		///node->link=node;		//첫노드는 자기가 자기자신을 가리킨다.
	}
	else {
		node->link = head->link;
		head->link = node;//헤드가 가리키는 링크값을 새로운 노드에
		head = node;
	}
	return head;
}

void print_list(ListNode *head) {
	//헤드로 부터 시작해서 처음으로 왔다.(한바퀴돌았다는 의미.를 줘야 멈춘다.)
	ListNode *p;
	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);	//last일경우 맨 마지막 노드가 먼저나옴. 왜냐하면 헤드가 마지막노드에 있기 때문
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