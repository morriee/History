//���Ḯ��Ʈ
#include <stdio.h>

//����ü ����
struct node
{	//ù��°��� ������ �ι�° ��� �ּ�.
	char data;
	struct node *link;		//�ڱ���������ü: �ڱⰡ �ڱⱸ��ü�� �����Ѵ�.
};

int main() {
	struct node a1, a2, a3;		//����ü��带 ������ �̸��� �־����.
	struct node *head;
	
	a1.data = 'A';
	a2.data = 'B';
	a3.data = 'C';

	//���ʿ� ������ ä������ ���� �����ؾ���. ����ü ������ ����Ǿ� �Ҵ����� ���� ������ ���� �������� ����Ǿ�����
	
	head = &a1;
	a1.link = &a2;		//a1��ũ�κп� a2�� �ּҸ� ����
	a2.link = &a3;
	a3.link = NULL; 

	//�����͸� �̿��Ͽ� ���(�����ʹ� ȭ��ǥ�� �����)
	printf("%c\n", head->data);		//a1.data -->'A'
	printf("%c\n", head->link->data);		//a2.data --->B
	printf("%c\n", head->link->link->data);		//a3.data--->C
	//link->link ->link �ݺ���. for�����..
	//����->�����忡 �ڵ带 ���� �׸��� �׷�����.
}