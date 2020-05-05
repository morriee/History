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
	int heap_size;
}HeapType;

int main() {
	//element: �����Ҵ�
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };		//����� �������� {}�ȿ� ���� �� ������ ��.
	/*���� �ٸ�ǥ��.
	element e1,e2, e3;
	e1.key = 10;
	e2.key = 5;
	e3.key = 30;
	*/
	
	
	//1.ù��° ADT :�޸��Ҵ��ϱ�
	HeapType* heap=NULL;		//�����ʹ� �ʱ�ȭ�� ���� NULL����.
	heap = create();		//HeapType�� �ּҸ� ��ȯ�ϴ� �Լ�

	//2. �ι�° ADT : �޸� �ʱ�ȭ �ϱ�.
	init(heap);			//�Ҵ�� ���� �޸� �ʱ�ȭ�ϴ� �Լ�(�� �Ҵ�ް� û�����ִ� ����)

	//3. ������ ADT : element �߰��ϱ�.
	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);
}

HeapType*  create() {				//int �ȉ�.��Ÿ���� �ּҸ� ��ȯ�ϱ� ����.
	HeapType* temp = (HeapType *)malloc(sizeof(HeapType));						//������Ÿ�� �̸��� �ָ� �˾Ƽ� �����.
	//malloc :�����Ҵ�
	return temp;
}

void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) {
	int i;
	i = h->heap_size + 1;		//i=++(h->heap_size);
	
	//����
	while (i != 1 && item.key > h->heap[i / 2].key) {
		h->heap[i] = h->heap[i / 2];
			i = i / 2;		//i�� ���� �ؿ� �ִ� �ڽ��̰� ���� �θ�� ��� ���Ͽ� ���� ������� 1��Ʈ(�θ�)���� �ö󰡼� ���ϴ� ��.
	}
	h->heap[i] = item;		// �����Ͱ��� ���̻� ���� ���� ������ �� �ڸ��� ���� �ִ� ��. 
}