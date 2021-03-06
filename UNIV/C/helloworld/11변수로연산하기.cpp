// 비교 연산자, 논리 연산자

#include <stdio.h>

int main() {
	int a, b;
	scanf("%d%d", &a, &b);

	// bool: 진리값 저장용 변수 (1바이트 = 8비트)
	bool p = a > b;

	// 2 > 3 -> 거짓
	// 참: 1, 거짓 : 0

	bool q = a < b;
	bool r = a == b; // ==: 같다(비교연산자)

	// a >= b : a는 b보다 크거나 같다
	// a <= b : a는 b보다 작거나 같다
	// a != b : a는 b가 아니다

	printf("%d\n", p);
	printf("%d\n", q);
	printf("%d\n", r);
}