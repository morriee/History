

#include <stdio.h>
#include<stdlib.h>

typedef int element;			
typedef struct ListNode {
	element data;	
	struct ListNode *link;		
}ListNode;

ListNode* insert_first(ListNode *head, element value) {		
	ListNode *p;
	p = (ListNode*)malloc(sizeof(ListNode));							
															
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

}
ListNode * search_list(ListNode *head, element x) {
	ListNode *p = head;
	while (p != NULL) {		
		if (p->data == x)	return p;
		p = p->link;		
	}
	return NULL;
}

ListNode *delete_first(ListNode *head) {
	ListNode *removed;		
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;		
	free(removed);		
	return head;		

}

ListNode *concat_list(ListNode *head1, ListNode *head2) {
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		ListNode *p = head1;
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = head2;
		return head1;
	}
}

//두 개의 연결리스트를 하나의 리스트로 합침
int main() {
	ListNode *head1 = NULL;
	ListNode *head2 = NULL;

	head1 = insert_first(head1, 10);
	head1 = insert_first(head1, 20);
	head1 = insert_first(head1, 30);

	head2 = insert_first(head2, 40);
	head2 = insert_first(head2, 50);

	print_list(head1);
	print_list(head2);

	ListNode *head3 = concat_list(head1, head2);
}

