// 전치와 후치

#include <stdio.h>

int main() {
	int a = 10;
	int b;

	/*
	printf("=== 전치 증가 연산 ===\n");
	
	// ++a;  전치
	// a++;   후치
	

	b = ++a;
	printf("a : %d\n", a);
	printf("b : %d\n", b);
	

	printf("=== 후치 증가 연산 ===\n");

	b = a++;
	printf("a : %d\n", a);
	printf("b : %d\n", b);
	*/
	printf("=== 전치 증가 연산 또 다른 방법 ===\n");

	a++;  // 후치는 이게 b = a; 밑에 있으면 됌.
	b = a;
	printf("a : %d\n", a);
	printf("b : %d\n", b);

}