//����ü - "���� �ٸ� Ÿ��"�� ���ؼ��� ���� ������ ������ �޸� ����
//�迭�� ���� - "���� �ڷ���"�� ���� ������ �޸� ����

#include <stdio.h>

// �ΰ��� �����͸� ���������� ������.
//����ü ����- Ʋ�� ����
struct person {
	int no;	//number
	double weight;
};

int main() {

	//����ü ������ ���� - �Ҵ�� �޸� �̸�
	struct person a;		

	// int a[2];

	a.no = 100;
	a.weight = 98.5;		//������ �޸𸮿� ����.
	printf("a.no = %d\n", a.no);
	printf("a.weight = %f\n", a.weight);
										/*�߸��� ǥ���
												person.no ------(x)
												person.a --------(x)
										*/

	// ������ ���� p�� ����
	struct person *p;		//p���� �ּҸ� ����.
	p = &a;		//a �޸��� �ּҸ� �����ͺ��� p�� �ִ´�.
	printf("����ü a�� �ּ�: %d\n", p);
	printf("p->no = %d\n", p->no);
	printf("p->weight = %f\n", p->weight);
}