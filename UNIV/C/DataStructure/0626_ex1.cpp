#include <stdio.h>

struct person
{// �� ����ü�� ũ��� 20+4
	char name[20];	//�迭	
	int id;	//����
};

struct person input_st() {
	struct person s;		//struct person Ÿ���� �Ű����� s. �޸� 24byte����
	printf("�̸��Է�>>");
	gets_s(s.name);	//	== scanf_s("%s", s.name);	���ڿ��� �Է¹���
	printf("��ȣ�Է�>>");
	scanf_s("%d", &s.id);		//c++, cin>> �Է¹޴� �Լ�
	return s;

	/*
	gets--->string�� ����. ���� s�� ������ �������� ���ڿ��� ��´ٴ� ��.
	getc/getch/getchar�� ĳ������ ������. 
	
	*/


}//-->�Լ��� ������ ���������� �Ҹ�ȴ�*

void output_st(struct person *d);		//�Լ��� ����(prototype) : �����Ϸ����� �Ѽ��� ������ ����.
														// �� �κ� ������ ���������. �ֳ��ϸ� �������� ������ ���� ����̵Ǳ� ������, ���� �Ʒ��ʿ� output()�� �ִ� ���� �𸣰� ���ο� output()�� ���ǵ��� �ʾҴٰ� ������ ��.

int main() {
	struct person d;		//d: ����ü ����, ���� �޸𸮰� 24byte�Ҵ��.
	//�Է��� �־�� ��µ� ����.
	printf("----------------�Է��ϼ���----------------\n");
	d = input_st();		//struct person�̶�� Ÿ������ ����
	//d�� ������ ���� ����ü ����...output_st()���� ���Ұ���.
	printf("------------------���ȭ��-----------------\n");

	output_st(&d);		//����: ����°�.


	printf("����ü�� ũ��: %d\n", sizeof(struct person));		//������Ÿ��+ ����ü�̸� --->24
}

void output_st(struct person *d) {		//���⼭�� d�޸� ������ main������ d�޸� ������ ���� �ٸ� ������.�׷��� �Ȱ��� ���� �ι� �޸𸮸� �Ҵ���-->����
														// but, �ּҷ� ������ �޸𸮸� �����ϱ� ������ ȿ��������
	printf("�̸� : %s\n", d->name);
	printf("��ȣ : %d\n", d->id);			//�����ʹ� ȭ��ǥ.
}