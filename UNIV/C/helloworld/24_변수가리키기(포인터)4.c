#include <stdio.h>

int main() {
	int a = 10;

	int *ptr;
	ptr = &a;

	int **ptr_ptr;		// �����͸� ����Ű�� ������

	ptr_ptr = &ptr;		// �����͸� ����Ű�� �����Ϳ��� ptr�� �ּҰ��� �־���.

	// ptr_ptr -> ptr ->a
	printf("a = %d\n", a);
	printf("&a = %d\n", &a);

	printf("ptr = %d\n", ptr);
	printf("&ptr = %d\n", &ptr);

	printf("ptr_ptr = %d\n", ptr_ptr);
	printf("*ptr_ptr = %d\n", *ptr_ptr);
	printf("**ptr_ptr = %d\n", **ptr_ptr);
}