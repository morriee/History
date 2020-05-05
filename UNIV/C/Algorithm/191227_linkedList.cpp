//���Ḯ��Ʈ: ���׽�
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int coef;	//���
	int expon;	//����
	ListNode* link;		//�ڱ���������ü: �ڱ�� �Ȱ��� �ָ� �ּҷ� ���´�.
};

//�� ����� ����
typedef struct ListType {
	int size;
	ListNode* head;		// ���׽��� �������̹Ƿ� head, tail�� �����ͷ� ����.
	ListNode* tail;
}ListType;

ListType* create() {
	ListType* plist = (ListType*)malloc(sizeof(ListType));		//�˾Ƽ� ListNode�����ŭ �޸� �Ҵ�.
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

void insert_last(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));		//3��12�� ������ ��������.
	
	temp->coef = coef;		//3
	temp->expon = expon;	//12
	temp->link = NULL;		//��ũ(�ٸ� ��� ����)

	if (plist->tail == NULL) {		//���� ù��° ����ζ�� �Ʒ��� �����ϼ���.ù��° ��尡 �ƴ϶�� tail�� �����Ͱ� �ֽ��ϴ�.
		plist->head = temp;
		plist->tail = temp;
	}
	else {	// �ι�° �̻��� ����� ���� �����ϼ���
		plist->tail->link = temp;		// ������ tail�� ����Ű�� link�κ��� ���� ���� ����� link�κ����� �̾��ּ���.
		plist->tail = temp;			//���� �κ��� �����ּ���(==�ּҸ� ���ε��� ����� link�� �ٲ��ּ���)
	}
	plist->size++;		//���ο� ��尡 ������ �޸𸮸� �������� �ּ���.
}

void printPoly(ListType* plist) {

	ListNode* p = plist->head;		//head�� ���󰡸� 3��12�� ����.
	printf("polynomial = ");
	for (; p != NULL; p = p->link) {		//for���� ���� �ʱ�ȭ�κ��� �ٷ� ���κп� �ֱ� ������ ����.
		printf("%dx^%d + ", p->coef, p->expon);
	}
	printf("\n");
	
}

void poly_add(ListType* plist1, ListType* plist2, ListType* plist3) {
	ListNode* a = plist1->head;		//.. ���׽� a�� �����Ͱ� 3�ϰ� 12�� ���� �����´�.
	ListNode* b = plist2->head;
	int sum;	//��������� ������ �޸� ����.

	while (a && b) {		//���׽�a�� b�� ����Ҳ���.
		if (a->expon == b->expon) {		//���׽� a,b�� �������� ������ �Ʒ��� �����ϼ���
			sum = a->coef + b->coef;		//������� ���ϼ���.
			if (sum != 0) {
				insert_last(plist3, sum, a->expon);	// ���� ���� �������Լ��� ����������ּҰ��������� ���� �������, ���׽�a�� �������� ��������.
			}
			//..���� ���� ����.
			a = a->link; 
			b = b->link;
		}
		else if (a->expon < b->expon) {		// ���� ������ �� ũ�� ���� �ʿ������ �׳� �״�� ��带 �����ϸ� ��.
			insert_last(plist3, b->coef, b->expon);
			//..���� ���� ����.
			b = b->link;
		}
		else {
			insert_last(plist3, a->coef, a->expon);
			//..���� ���� ����.
			a = a->link;
		}
	}

	//�Ʒ��� ���׽� ���� �ϳ��� ���� �� �������� ��쿡 ������.
	for(; a!=NULL; a=a->link)
		insert_last(plist3, a->coef, a->expon);

	for(; b!=NULL; b=b->link)
		insert_last(plist3, b->coef, b->expon);
}

int main() {

	//�� ����. ���ϰ� ����� ������ ���� ���� �����ؾߵǴ� �ּҵ� ������ �ؾ���.�׷��� �����ͼ���.
	ListType *list1, *list2, *list3;	

	//��� ���� -> ���� ����(malloc()�Լ�, stdlib.h)-�ʿ��Ҷ����� ����
	list1 = create();
	list2 = create();
	list3 = create();

	//��� ����
	//���׽� a 
	insert_last(list1,3,12);	//ó�� ������ 3x�� 12����
	insert_last(list1, 2, 8);	//�ι�° ������ 2x�� 8����
	insert_last(list1, 1, 0);	//����° ������ 1

	//���׽� b
	insert_last(list1, 8, 12);	//ó�� ������ 8x�� 12����
	insert_last(list1, -3, 10);	//�ι�° ������ -3x�� 10����
	insert_last(list1, 10, 6);	//����° ������ 10x�� 6����
	
	//��� ���
	printPoly(list1);
	printPoly(list2);

	//�� ���׽��� ����
	poly_add(list1, list2, list3);	// �ĵΰ��� ����� ���� �� �Ѱ��� ����
	printPoly(list3);


	free(list1); free(list2); free(list3);
}