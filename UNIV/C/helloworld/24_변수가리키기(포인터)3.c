#include <stdio.h>

int main() {
	int a = 10;

	int *ptr;
	ptr = &a;

	printf("a�� �� : %d\n", a);

	*ptr = 20;		// *ptr�� �ּҰ� ����Ű�� ������ ����.,,, ���� ���� a�� ����
					// *ptr == a
	

	printf("a�� �� : %d\n", a);
}