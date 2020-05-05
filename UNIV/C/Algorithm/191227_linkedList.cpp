//연결리스트: 다항식
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int coef;	//계수
	int expon;	//지수
	ListNode* link;		//자기참조구조체: 자기랑 똑같은 애를 주소로 갖는다.
};

//각 노드의 길이
typedef struct ListType {
	int size;
	ListNode* head;		// 다항식은 가변적이므로 head, tail을 포인터로 선언.
	ListNode* tail;
}ListType;

ListType* create() {
	ListType* plist = (ListType*)malloc(sizeof(ListType));		//알아서 ListNode사이즈만큼 메모리 할당.
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

void insert_last(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));		//3과12를 저장할 공간마련.
	
	temp->coef = coef;		//3
	temp->expon = expon;	//12
	temp->link = NULL;		//링크(다른 노드 없음)

	if (plist->tail == NULL) {		//내가 첫번째 노드인라면 아래를 수행하세요.첫번째 노드가 아니라면 tail에 데이터가 있습니다.
		plist->head = temp;
		plist->tail = temp;
	}
	else {	// 두번째 이상의 노드라면 저를 수행하세요
		plist->tail->link = temp;		// 기존의 tail이 가리키는 link부분을 새로 들어온 노드의 link부분으로 이어주세요.
		plist->tail = temp;			//이은 부분을 묶어주세요(==주소를 새로들어온 노드의 link로 바꿔주세요)
	}
	plist->size++;		//새로운 노드가 들어오면 메모리를 증가시켜 주세요.
}

void printPoly(ListType* plist) {

	ListNode* p = plist->head;		//head를 따라가면 3과12가 있음.
	printf("polynomial = ");
	for (; p != NULL; p = p->link) {		//for문의 앞의 초기화부분은 바로 윗부분에 있기 때문에 생략.
		printf("%dx^%d + ", p->coef, p->expon);
	}
	printf("\n");
	
}

void poly_add(ListType* plist1, ListType* plist2, ListType* plist3) {
	ListNode* a = plist1->head;		//.. 다항식 a의 포인터가 3하고 12를 값을 가져온다.
	ListNode* b = plist2->head;
	int sum;	//덧셈결과를 저장할 메모리 공간.

	while (a && b) {		//다항식a와 b를 계산할께요.
		if (a->expon == b->expon) {		//다항식 a,b의 지수값이 같으면 아래를 수행하세요
			sum = a->coef + b->coef;		//계수끼리 더하세요.
			if (sum != 0) {
				insert_last(plist3, sum, a->expon);	// 더한 값을 노드생성함수로 결과저장할주소가진변수와 더한 결과값과, 다항식a의 지수값을 보내세요.
			}
			//..다음 노드로 전진.
			a = a->link; 
			b = b->link;
		}
		else if (a->expon < b->expon) {		// 한쪽 지수가 더 크면 더할 필요없으니 그냥 그대로 노드를 생성하면 됨.
			insert_last(plist3, b->coef, b->expon);
			//..다음 노드로 전진.
			b = b->link;
		}
		else {
			insert_last(plist3, a->coef, a->expon);
			//..다음 노드로 전진.
			a = a->link;
		}
	}

	//아래는 다항식 둘중 하나만 식이 더 남아있을 경우에 수행함.
	for(; a!=NULL; a=a->link)
		insert_last(plist3, a->coef, a->expon);

	for(; b!=NULL; b=b->link)
		insert_last(plist3, b->coef, b->expon);
}

int main() {

	//식 세개. 더하고 결과를 내려면 서로 식을 공유해야되니 주소도 공유를 해야함.그래서 포인터선언.
	ListType *list1, *list2, *list3;	

	//노드 생성 -> 동적 생성(malloc()함수, stdlib.h)-필요할때마다 생성
	list1 = create();
	list2 = create();
	list3 = create();

	//노드 삽입
	//다항식 a 
	insert_last(list1,3,12);	//처음 데이터 3x의 12제곱
	insert_last(list1, 2, 8);	//두번째 데이터 2x의 8제곱
	insert_last(list1, 1, 0);	//세번째 데이터 1

	//다항식 b
	insert_last(list1, 8, 12);	//처음 데이터 8x의 12제곱
	insert_last(list1, -3, 10);	//두번째 데이터 -3x의 10제곱
	insert_last(list1, 10, 6);	//세번째 데이터 10x의 6제곱
	
	//노드 출력
	printPoly(list1);
	printPoly(list2);

	//두 다항식을 더함
	poly_add(list1, list2, list3);	// 식두개와 결과를 담을 식 한개를 전달
	printPoly(list3);


	free(list1); free(list2); free(list3);
}