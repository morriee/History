//����������
//������ �ϱ��� ����� �����Ͽ� �������.

#include <stdio.h>

int g = 100;	//��������-�Ϲ� �޸𸮿� �Ҵ�. ���α׷� ����(����� ����)���� ������

int main() {
	int a = 1, b = 1;
	g++;
	{
		int a = 10, c = 11;
		printf("a = %d , b =%d\n", a, b);	
		printf("b=%d\n", ++b);		
		g++;

	}

	printf("a =%d, b = %d\n", a, b);	//1,2
	printf("g =%d\n", g);	//102



}