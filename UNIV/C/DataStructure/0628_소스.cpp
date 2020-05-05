#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int coef;	
	int expon;	
	struct ListNode *link;
}ListNode;

typedef struct ListType {
	int size;	
	ListNode *head;
	ListNode *tail;
}ListType;

ListType * create() {
	ListType *p = (ListType*)malloc(sizeof(ListType));	
	p->size = 0;
	p->head = p->tail = NULL;	
	return p;
}

void insert_last(ListType *plist, int coef, int expon) {		
	ListNode *temp = (ListNode*)malloc(sizeof(ListNode));
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;		

	
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;		
	}
	else {
		plist->tail->link = temp;		//1
		plist->tail = temp;
	}
	plist->size++;	
}

void poly_print(ListType *plist) {
	ListNode *p = plist->head;
	for (; p; p = p->link) {		
		printf("%d, %d\n", p->coef, p->expon);
	}
	printf("\n");
}

int main() {
	ListType *list1, *list2, *list3;	
	list1 = create();
	list2 = create();
	list3 = create();

	insert_last(list1, 3, 12);
	insert_last(list1, 2, 8);		//2,8ÀÌ tail.
	insert_last(list1, 1, 0);
	poly_print(list1);

	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);		//2,8ÀÌ tail.
	insert_last(list2, 10, 6);
	poly_print(list2);

}


