//연결리스트
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


	//이걸 여기에 쓰면 무한 루프 돌아 멍청아. 
	//plist->head = plist->tail = temp; 
	
	
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;		//첫번째 노드인 경우 head와 tail모두 temp.
												////머리와 꼬리 모두 temp다.	값이 들어오고 다음식이 들어올때 삭제하는 코드가 없는 한 값이 그대로 저장된 상태서 계산.
	}
	else {
		plist->tail->link = temp;		//1
		plist->tail = temp;
	}
	plist->size++;	//..노드가 들어가면서 p타입이 계속해서 바뀜.
}

void poly_print(ListType *plist) {
	ListNode *p = plist->head;
	for (; p!=NULL; p = p->link) {		//초기화 부분을 바로 위에서함/조건부분은 p!= null 이나 p나 같음. 왜냐하면 c문법에서 p에 아무것도 없으면 거짓이기때문
		printf("%d, %d\n", p->coef, p->expon);
	}
	printf("\n");
}

void poly_add(ListType *plist1, ListType *plist2, ListType *plist3) {
	ListNode *a = plist1->head;		//list1이 가리키는 head값.
	ListNode *b = plist2->head;		// 두번째 노드의 list2가 가리키는 head값

	//a와 b가 가리키는 지수가 서로 같은가
	int sum;

	while (a && b) {		//a와b가 같을경우에만 아래 식 실행

		if (a->expon == b->expon) {	// 만약 같으면 둘의 계수를
			sum = a->coef + b->coef;	//더한다.....a의 계수와 b의 계수를 더하여 sum에 대입
			insert_last(plist3, sum, a->expon);	//c의 첫번째 노드가 완성이 됨.

			//같을 때 a,b둘 다 다음 노드로 전진.
			a = a->link;
			b = b->link;
		}

		//만약 a,b둘이 지수가 다르다면
		else if (a->expon < b->expon) {
			insert_last(plist3, b->coef, b->expon);		//b가 더크니까 b를 c노드에 적는다.
			b = b->link;	//그러니까 b만 전진한다.
		}
		//만약 a가 더 크다면
		else {
			insert_last(plist3, a->coef, a->expon);		//a가 클 경우 a를 c노드에 적는다(참고로 이 말은 그림으로 그렸을시 논리적인 형태를 말함.가상의 c)
			a = a->link;		//a만 전진한다.
		}
	}

	//b가 종료가 되었을때 남아있는 a다항식을 보낸다.
	for (; a; a = a->link) {
		insert_last(plist3, a->coef, a->expon);
	}
	//남아있는 b다항식을 보낸다.
	for (; b; b = b->link) {
		insert_last(plist3, b->coef, b->expon);
	}
}

int main() {
	ListType *list1, *list2, *list3;	//abc다항식 리스트타입(listheader) 담는 곳.head와 tail연결
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
	//printf("zzz");
	poly_add(list1, list2, list3);
	poly_print(list3);		//결과
}


/*
과제2

다항식을 단계적으로 그려오셈. 내가 이해한 대로.
다항식에 연결되는 과정을 listtype과 함께 그려오셈.
*/