//191226수업
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
	int heap_size;		// heap_size가 데이터의 개수를 알고 있게끔 설계했음.
}HeapType;

HeapType* create() {				//int 안됌.힙타입의 주소를 반환하기 때문.
	HeapType* temp = (HeapType*)malloc(sizeof(HeapType));						//데이터타입 이름을 주면 알아서 계산함.
	//malloc :동적할당
	return temp;
}

void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) {
	int i;
	h->heap_size  = h->heap_size + 1;		
	i = h->heap_size;
	//위의 두코드 합침 >>  i = ++(h->heap_size);

	//조건
	while (i != 1 && item.key > h->heap[i / 2].key) {
		h->heap[i] = h->heap[i / 2];
		i = i / 2;		//i가 가장 밑에 있는 자식이고 위의 부모와 계속 비교하여 가장 꼭대기인 1루트(부모)까지 올라가서 비교하는 것.
	}
	h->heap[i] = item;		// 데이터값이 더이상 비교할 때가 없을때 그 자리에 값을 넣는 것. 
}

void print_HeapArr(HeapType* h) {
	for (int i = 1; i <= h->heap_size; i++) {
		//printf("element %d번째 요소의 값은 %d\n", i, h->heap[i].key);
		printf("element %d번째 요소의 값은 %3d\n", i,h->heap[i].key);		//h->heap[i]:h가 heap라고 하는 아이의 i번째를 말함.
	}
	printf("\n");
}

element delete_max_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];	//가장 첫번째 노드값 저장해둔곳
	temp = h->heap[(h->heap_size)--];//가장 마지막 노드값 임시로 저장해두는 곳.
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		if (child < h->heap_size && h->heap[child].key < h->heap[child + 1].key)
			child++;	//오른쪽 자식노드값이 더큼.
		if (temp.key >= h->heap[child].key) break;		// 왼쪽 자식 노드 값이 더클 경우
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	//break가 걸렷을때..
	h->heap[parent] = temp;
	return item;
}

int main() {
	//element: 정적할당
	
	element e1 = { 2 }, e2 = { 1 }, e3 = { 3 }, e4 = { 5 }, e5 = { 7 }, e6 = { 12 };			//예제
	
	/*
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };		//멤버가 여러개면 {}안에 값을 더 넣으면 됌.
	위와 다른표현.
	element e1,e2, e3;
	e1.key = 10;
	e2.key = 5;
	e3.key = 30;
	*/


	//1.첫번째 ADT :메모리할당하기
	HeapType* heap = NULL;		//포인터는 초기화를 보통 NULL로함.
	heap = create();		//HeapType의 주소를 반환하는 함수

	//2. 두번째 ADT : 메모리 초기화 하기.
	init(heap);			//할당된 동적 메모리 초기화하는 함수(방 할당받고 청소해주는 역할)

	//3. 마지막 ADT : element 추가하기.
	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);
	insert_max_heap(heap, e4);
	insert_max_heap(heap, e5);
	insert_max_heap(heap, e6);

	//힙트리 배열 출력
	print_HeapArr(heap);		//주소를 호출하면 출력할 수 있다.

	//1순위 우선순위값 인출
	element res = delete_max_heap(heap);		//12
	print_HeapArr(heap);		//7,5,2,1,3
	//인출값 출력
	printf("우선순위 값 %3d:\n", res.key);

		// 2순위 우선순위값 인출
	res = delete_max_heap(heap);		//7
	print_HeapArr(heap);		//5,3,2,1
	printf("우선순위 값 %3d:\n", res.key);
}

