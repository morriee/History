// 중첩 if문
// 중괄호 코딩 스타일

#include <stdio.h>

int main() {
	int a, b, c;

	scanf("%d%d%d", &a, &b, &c);

	if (a > b) {
		// a > b > c
		// a > c > b
		// c > a > b

		if (a > c) printf("%d\n", a);
		else printf("%d\n", c);
	} else if (b > c) printf("%d\n", b);  // b > a
		else  printf("%d\n", c);  // c > b
}