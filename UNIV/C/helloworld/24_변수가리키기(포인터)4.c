#include <stdio.h>

int main() {
	int a = 10;

	int *ptr;
	ptr = &a;

	int **ptr_ptr;		// 포인터를 가리키는 포인터

	ptr_ptr = &ptr;		// 포인터를 가리키는 포인터에는 ptr의 주소값을 넣어줌.

	// ptr_ptr -> ptr ->a
	printf("a = %d\n", a);
	printf("&a = %d\n", &a);

	printf("ptr = %d\n", ptr);
	printf("&ptr = %d\n", &ptr);

	printf("ptr_ptr = %d\n", ptr_ptr);
	printf("*ptr_ptr = %d\n", *ptr_ptr);
	printf("**ptr_ptr = %d\n", **ptr_ptr);
}