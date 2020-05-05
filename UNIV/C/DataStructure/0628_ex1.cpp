//���Ḯ��Ʈ
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int coef;	//���
	int expon;	//����
	struct ListNode *link;
}ListNode;

typedef struct ListType {
	int size;	//���� ���׽� ���� �ִ� ����
	ListNode *head;
	ListNode *tail;
}ListType;

ListType * create() {
	ListType *p = (ListType*)malloc(sizeof(ListType));	//��� 3�� �޸��Ҵ�
	p->size = 0;
	p->head = p->tail = NULL;	//÷�� size,head,tail �� ���� ����
	return p;
}

void insert_last(ListType *plist, int coef, int expon) {		// plist�� list1,2,3,�� ���� ������ ������ ����.
	ListNode *temp = (ListNode*)malloc(sizeof(ListNode));
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;		//�ʱⰪ�� ����. �����̵Ǹ� ���⿡ ���̵���¡.


	//�̰� ���⿡ ���� ���� ���� ���� ��û��. 
	//plist->head = plist->tail = temp; 
	
	
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;		//ù��° ����� ��� head�� tail��� temp.
												////�Ӹ��� ���� ��� temp��.	���� ������ �������� ���ö� �����ϴ� �ڵ尡 ���� �� ���� �״�� ����� ���¼� ���.
	}
	else {
		plist->tail->link = temp;		//1
		plist->tail = temp;
	}
	plist->size++;	//..��尡 ���鼭 pŸ���� ����ؼ� �ٲ�.
}

void poly_print(ListType *plist) {
	ListNode *p = plist->head;
	for (; p!=NULL; p = p->link) {		//�ʱ�ȭ �κ��� �ٷ� ��������/���Ǻκ��� p!= null �̳� p�� ����. �ֳ��ϸ� c�������� p�� �ƹ��͵� ������ �����̱⶧��
		printf("%d, %d\n", p->coef, p->expon);
	}
	printf("\n");
}

void poly_add(ListType *plist1, ListType *plist2, ListType *plist3) {
	ListNode *a = plist1->head;		//list1�� ����Ű�� head��.
	ListNode *b = plist2->head;		// �ι�° ����� list2�� ����Ű�� head��

	//a�� b�� ����Ű�� ������ ���� ������
	int sum;

	while (a && b) {		//a��b�� ������쿡�� �Ʒ� �� ����

		if (a->expon == b->expon) {	// ���� ������ ���� �����
			sum = a->coef + b->coef;	//���Ѵ�.....a�� ����� b�� ����� ���Ͽ� sum�� ����
			insert_last(plist3, sum, a->expon);	//c�� ù��° ��尡 �ϼ��� ��.

			//���� �� a,b�� �� ���� ���� ����.
			a = a->link;
			b = b->link;
		}

		//���� a,b���� ������ �ٸ��ٸ�
		else if (a->expon < b->expon) {
			insert_last(plist3, b->coef, b->expon);		//b�� ��ũ�ϱ� b�� c��忡 ���´�.
			b = b->link;	//�׷��ϱ� b�� �����Ѵ�.
		}
		//���� a�� �� ũ�ٸ�
		else {
			insert_last(plist3, a->coef, a->expon);		//a�� Ŭ ��� a�� c��忡 ���´�(����� �� ���� �׸����� �׷����� ������ ���¸� ����.������ c)
			a = a->link;		//a�� �����Ѵ�.
		}
	}

	//b�� ���ᰡ �Ǿ����� �����ִ� a���׽��� ������.
	for (; a; a = a->link) {
		insert_last(plist3, a->coef, a->expon);
	}
	//�����ִ� b���׽��� ������.
	for (; b; b = b->link) {
		insert_last(plist3, b->coef, b->expon);
	}
}

int main() {
	ListType *list1, *list2, *list3;	//abc���׽� ����ƮŸ��(listheader) ��� ��.head�� tail����
	list1 = create();
	list2 = create();
	list3 = create();

	insert_last(list1, 3, 12);
	insert_last(list1, 2, 8);		//2,8�� tail.
	insert_last(list1, 1, 0);
	poly_print(list1);

	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);		//2,8�� tail.
	insert_last(list2, 10, 6);
	poly_print(list2);
	//printf("zzz");
	poly_add(list1, list2, list3);
	poly_print(list3);		//���
}


/*
����2

���׽��� �ܰ������� �׷�����. ���� ������ ���.
���׽Ŀ� ����Ǵ� ������ listtype�� �Բ� �׷�����.
*/