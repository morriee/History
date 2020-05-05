// 제어문 :  if, while for 등의 프로그램의 흐름을 제어하는 구문들.

#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	if (n % 2 == 0) {
		printf("n은 짝수\n");
	}
	else {
		printf("n은 홀수\n");
	}
}