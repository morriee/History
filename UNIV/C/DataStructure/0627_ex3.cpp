#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int coef;	//계수
	int expon;	//지수
	struct ListNode *link;
}ListNode;

typedef struct ListType {
	int size;	//각각 다항식 개수 넣는 변수
	ListNode *head;
	ListNode *tail;
}ListType;

ListType * create() {
	ListType *p = (ListType*)malloc(sizeof(ListType));	//멤버 3개 메모리할당
	p->size = 0;
	p->head = p->tail = NULL;	//첨엔 size,head,tail 값 없는 상태
	return p;
}

void insert_last(ListType *plist, int coef, int expon) {		// plist는 list1,2,3,다 들어가기 때문에 저렇게 지음.
	ListNode *temp = (ListNode*)malloc(sizeof(ListNode));
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;		//초기값은 없음. 실행이되면 여기에 값이들어가겠징.

	plist->head = plist->tail = temp; //머리와 꼬리 모두 temp다.	값이 들어오고 다음식이 들어올때 삭제하는 코드가 없는 한 값이 그대로 저장된 상태서 계산.
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;		//첫번째 노드인 경우 head와 tail모두 temp.
	}
	else {
		plist->tail->link = temp;		//1
		plist->tail = temp;
	}
	plist->size++;	//..노드가 들어가면서 p타입이 계속해서 바뀜.
}

void poly_print(ListType *plist) {
	ListNode *p = plist->head;
	for (; p; p=p->link) {		//초기화 부분을 바로 위에서함/조건부분은 p!= null 이나 p나 같음. 왜냐하면 c문법에서 p에 아무것도 없으면 거짓이기때문
		printf("%d, %d\n", p->coef, p->expon);
	}
	printf("\n");
}

int main() {
	ListType *list1, *list2, *list3;	//abc다항식 리스트타입(listheader) 담는 곳.
	list1 = create();
	list2 = create();
	list3 = create();

	insert_last(list1, 3, 12);
	insert_last(list1, 2, 8);		//2,8이 tail.
	insert_last(list1, 1, 0);
	poly_print(list1);

	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);		//2,8이 tail.
	insert_last(list2, 10, 6);
	poly_print(list2);

}


/*
과제2

다항식을 단계적으로 그려오셈. 내가 이해한 대로.
다항식에 연결되는 과정을 listtype과 함께 그려오셈.
*/