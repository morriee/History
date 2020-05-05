#include <stdio.h>

int main() {
	int a = 10;

	int *ptr;
	ptr = &a;

	printf("a의 값 : %d\n", a);

	*ptr = 20;		// *ptr은 주소가 가리키는 변수를 말함.,,, 따라서 변수 a와 동일
					// *ptr == a
	

	printf("a의 값 : %d\n", a);
}