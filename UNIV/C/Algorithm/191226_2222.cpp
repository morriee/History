#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENT 10
typedef struct {
	int key;
}element;

typedef struct {
	element heap[MAX_ELEMENT + 1];
	int heap_size;
} HeapType;

HeapType* create() {				//int 안됌.힙타입의 주소를 반환하기 때문.
	HeapType* temp = (HeapType*)malloc(sizeof(HeapType));						//데이터타입 이름을 주면 알아서 계산함.
	//malloc :동적할당
	return temp;
}

//초기화 함수
void init(HeapType* h) {
	h->heap_size = 0;
}

//삽입함수
void insert_max_heap(HeapType* h, element item)
{
	int i = ++(h->heap_size);

	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;

}
//출력함수
void print_HeapArr(HeapType* h) {
	for (int i = 1; i <= h->heap_size; i++) {
		printf("element %d번째 요소의 값은 %3d\n", i, h->heap[i].key);		//h->heap[i]:h가 heap라고 하는 아이의 i번째를 말함.
	}
	printf("\n");
}

//삭제 함수
int delete_max_heap(HeapType* h) {
	int parent = 1, child = 2;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];

	while (child <= h->heap_size) {
		if ((child <= h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
			child++;

		if (temp.key >= h->heap[child].key) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;

	}
	h->heap[parent] = temp;
	return item.key;
}
//히프정렬
void heap_sort(element arr[], int size) {
	HeapType h;
	init(&h);

	for (int i = 1; i <= size; i++)
		insert_max_heap(&h, arr[i]);

	for (int i = size; i > 0; i--)
		arr[i].key = delete_max_heap(&h);
}

void main() {
	element arr[MAX_ELEMENT];

	printf("max heap -내림차순\n정렬이전배열: ");
	for (int i = 1; i <= MAX_ELEMENT; i++) {
		arr[i].key = rand() % MAX_ELEMENT;
		printf("%d ", arr[i]);
	}
	printf("\n");

	heap_sort(arr, MAX_ELEMENT);
	
	printf("정렬이후배열: ");
	for (int i = MAX_ELEMENT; i > 0; i--)
		printf("%d ", arr[i]);

	printf("\n");
	system("pause");
}
