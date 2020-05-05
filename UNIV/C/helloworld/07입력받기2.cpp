#include <stdio.h>

int main() {
	float a, b;

	scanf_s("%f%f", &a, &b);  // &: 포인터( 스캔에프를 쓸때는 포인터인 &을 반드시 써야한다.
		//scanf : 입력 받는 자료형.

	float hap = a + b;
	float cha = a - b;
	float gop = a * b;
	float mok = a / b;

	printf("%f + %f = %f\n", a, b, hap);
	printf("%f - %f = %f\n", a, b, cha);
	printf("%f * %f = %f\n", a, b, gop);
	printf("%f / %f = %f\n", a, b, mok);
}