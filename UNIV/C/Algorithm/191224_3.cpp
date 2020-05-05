//우선순위 큐
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNING
#define MAX_ELEMENT 10		// 데이터의 최대 크기 :10

//구조체 정의
typedef struct {
	int key;
}element;

typedef struct {
	element heap[MAX_ELEMENT];		//data 타입 정수이지만 element 타입으로 정의.똑같은 정수인데 왜 꼬냐? 라임 맞출려고..
	int heap_size;
}HeapType;

int main() {
	//element: 정적할당
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };		//멤버가 여러개면 {}안에 값을 더 넣으면 됌.
	/*위와 다른표현.
	element e1,e2, e3;
	e1.key = 10;
	e2.key = 5;
	e3.key = 30;
	*/
	
	
	//1.첫번째 ADT :메모리할당하기
	HeapType* heap=NULL;		//포인터는 초기화를 보통 NULL로함.
	heap = create();		//HeapType의 주소를 반환하는 함수

	//2. 두번째 ADT : 메모리 초기화 하기.
	init(heap);			//할당된 동적 메모리 초기화하는 함수(방 할당받고 청소해주는 역할)

	//3. 마지막 ADT : element 추가하기.
	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);
}

HeapType*  create() {				//int 안됌.힙타입의 주소를 반환하기 때문.
	HeapType* temp = (HeapType *)malloc(sizeof(HeapType));						//데이터타입 이름을 주면 알아서 계산함.
	//malloc :동적할당
	return temp;
}

void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) {
	int i;
	i = h->heap_size + 1;		//i=++(h->heap_size);
	
	//조건
	while (i != 1 && item.key > h->heap[i / 2].key) {
		h->heap[i] = h->heap[i / 2];
			i = i / 2;		//i가 가장 밑에 있는 자식이고 위의 부모와 계속 비교하여 가장 꼭대기인 1루트(부모)까지 올라가서 비교하는 것.
	}
	h->heap[i] = item;		// 데이터값이 더이상 비교할 때가 없을때 그 자리에 값을 넣는 것. 
}