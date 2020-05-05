#include <stdio.h>

int main() {
	// 1, 2, 4, 8, 16, 32, ...

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i *= 2) {
		printf("%d\n", i);
	}

	printf("%d\n", i); // 중괄호 안에서 선언된 변수들은 중괄호 안에서만 실행된다.
}


// i *= 2 == i = i * 2 : i에다가 2를 곱하고 i에 대입하라.(i에다 두배를 해라)