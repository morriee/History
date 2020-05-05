/*
1. 두 숫자를 입력받아서 그 숫자들의 합을 출력하는 프로그램을 만들어 보세요.
*/

#include <stdio.h>

int main() {
	int a, b;

	scanf_s("%d%d", &a, &b);

	printf("%d + %d = %d\n", a, b, a + b);
}