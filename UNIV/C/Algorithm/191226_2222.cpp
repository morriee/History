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

HeapType* create() {				//int �ȉ�.��Ÿ���� �ּҸ� ��ȯ�ϱ� ����.
	HeapType* temp = (HeapType*)malloc(sizeof(HeapType));						//������Ÿ�� �̸��� �ָ� �˾Ƽ� �����.
	//malloc :�����Ҵ�
	return temp;
}

//�ʱ�ȭ �Լ�
void init(HeapType* h) {
	h->heap_size = 0;
}

//�����Լ�
void insert_max_heap(HeapType* h, element item)
{
	int i = ++(h->heap_size);

	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;

}
//����Լ�
void print_HeapArr(HeapType* h) {
	for (int i = 1; i <= h->heap_size; i++) {
		printf("element %d��° ����� ���� %3d\n", i, h->heap[i].key);		//h->heap[i]:h�� heap��� �ϴ� ������ i��°�� ����.
	}
	printf("\n");
}

//���� �Լ�
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
//��������
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

	printf("max heap -��������\n���������迭: ");
	for (int i = 1; i <= MAX_ELEMENT; i++) {
		arr[i].key = rand() % MAX_ELEMENT;
		printf("%d ", arr[i]);
	}
	printf("\n");

	heap_sort(arr, MAX_ELEMENT);
	
	printf("�������Ĺ迭: ");
	for (int i = MAX_ELEMENT; i > 0; i--)
		printf("%d ", arr[i]);

	printf("\n");
	system("pause");
}
