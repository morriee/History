//중간고사에서 이 코드 통채로 냄.
#include <stdio.h>
#include<stdlib.h>

typedef int element;			//int를 element로 이름 재정의
typedef struct ListNode {
	element data;		//int data
	struct ListNode *link;			//컴파일러는 위에서 내려오기 때문에 struct ListNode를 ListNode로 재정의 한것을 모름
}ListNode;

ListNode* insert_first(ListNode *head, element value) {		//element value == int value
	//함수가 포인터를 리턴할시 타입이름에도 *를 꽂는다.
	//ListNode a1; 이렇게 하지 않고 <동적할당>으로 한다.
	ListNode *p;
	p =(ListNode*) malloc(sizeof(ListNode));							//malloc(필요한 크기), 힙 공간에 할당함-stdlib.h/standard library, 주소공간을 저장하려면 그에 맞는 포인터변수가 있어야함.
	//형변환한것. 리스트노드를 *리스트노드로.
																		//리스트노드 타입의 리스트크기 할당
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
	while (p != NULL) {		//p가 null이면 끝까지 간것임
		if (p->data == x)	return p;
		p = p->link;		//data가 아니라link를 따라가면 데이터가 돌게 되어있음.
	}
	return NULL;
}
int main() {
	ListNode *head = NULL;		//*head는 첫번째 주소를 나타냄.

	for (int i = 0; i < 5; i++) {		//2를 넣고 7을 넣어보셈. (실습)
		head = insert_first(head, i);
		print_list(head);
	}

	if (search_list(head, 2)) 
		printf("값이 존재함....\n");
	else
		printf("존재하지 않는 값임....\n");
	
//	head = insert_first(head, 0);
//	head = insert_first(head, 1);
//	head = insert_first(head, 2);

//	print_list(head);
}

//과제 각각 1,2,3그려오기