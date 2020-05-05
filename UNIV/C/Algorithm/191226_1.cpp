//191226����
//�켱���� ť
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNING
#define MAX_ELEMENT 10		// �������� �ִ� ũ�� :10

//����ü ����
typedef struct {
	int key;
}element;

typedef struct {
	element heap[MAX_ELEMENT];		//data Ÿ�� ���������� element Ÿ������ ����.�Ȱ��� �����ε� �� ����? ���� �������..
	int heap_size;		// heap_size�� �������� ������ �˰� �ְԲ� ��������.
}HeapType;

HeapType* create() {				//int �ȉ�.��Ÿ���� �ּҸ� ��ȯ�ϱ� ����.
	HeapType* temp = (HeapType*)malloc(sizeof(HeapType));						//������Ÿ�� �̸��� �ָ� �˾Ƽ� �����.
	//malloc :�����Ҵ�
	return temp;
}

void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) {
	int i;
	h->heap_size  = h->heap_size + 1;		
	i = h->heap_size;
	//���� ���ڵ� ��ħ >>  i = ++(h->heap_size);

	//����
	while (i != 1 && item.key > h->heap[i / 2].key) {
		h->heap[i] = h->heap[i / 2];
		i = i / 2;		//i�� ���� �ؿ� �ִ� �ڽ��̰� ���� �θ�� ��� ���Ͽ� ���� ������� 1��Ʈ(�θ�)���� �ö󰡼� ���ϴ� ��.
	}
	h->heap[i] = item;		// �����Ͱ��� ���̻� ���� ���� ������ �� �ڸ��� ���� �ִ� ��. 
}

void print_HeapArr(HeapType* h) {
	for (int i = 1; i <= h->heap_size; i++) {
		//printf("element %d��° ����� ���� %d\n", i, h->heap[i].key);
		printf("element %d��° ����� ���� %3d\n", i,h->heap[i].key);		//h->heap[i]:h�� heap��� �ϴ� ������ i��°�� ����.
	}
	printf("\n");
}

element delete_max_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];	//���� ù��° ��尪 �����صа�
	temp = h->heap[(h->heap_size)--];//���� ������ ��尪 �ӽ÷� �����صδ� ��.
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		if (child < h->heap_size && h->heap[child].key < h->heap[child + 1].key)
			child++;	//������ �ڽĳ�尪�� ��ŭ.
		if (temp.key >= h->heap[child].key) break;		// ���� �ڽ� ��� ���� ��Ŭ ���
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	//break�� �ɷ�����..
	h->heap[parent] = temp;
	return item;
}

int main() {
	//element: �����Ҵ�
	
	element e1 = { 2 }, e2 = { 1 }, e3 = { 3 }, e4 = { 5 }, e5 = { 7 }, e6 = { 12 };			//����
	
	/*
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };		//����� �������� {}�ȿ� ���� �� ������ ��.
	���� �ٸ�ǥ��.
	element e1,e2, e3;
	e1.key = 10;
	e2.key = 5;
	e3.key = 30;
	*/


	//1.ù��° ADT :�޸��Ҵ��ϱ�
	HeapType* heap = NULL;		//�����ʹ� �ʱ�ȭ�� ���� NULL����.
	heap = create();		//HeapType�� �ּҸ� ��ȯ�ϴ� �Լ�

	//2. �ι�° ADT : �޸� �ʱ�ȭ �ϱ�.
	init(heap);			//�Ҵ�� ���� �޸� �ʱ�ȭ�ϴ� �Լ�(�� �Ҵ�ް� û�����ִ� ����)

	//3. ������ ADT : element �߰��ϱ�.
	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);
	insert_max_heap(heap, e4);
	insert_max_heap(heap, e5);
	insert_max_heap(heap, e6);

	//��Ʈ�� �迭 ���
	print_HeapArr(heap);		//�ּҸ� ȣ���ϸ� ����� �� �ִ�.

	//1���� �켱������ ����
	element res = delete_max_heap(heap);		//12
	print_HeapArr(heap);		//7,5,2,1,3
	//���Ⱚ ���
	printf("�켱���� �� %3d:\n", res.key);

		// 2���� �켱������ ����
	res = delete_max_heap(heap);		//7
	print_HeapArr(heap);		//5,3,2,1
	printf("�켱���� �� %3d:\n", res.key);
}

