#include <stdio.h>

int main() {
	/*
	// int : 32비트(4바이트), 정수를 담는 데 쓰임
	int a = 5;
	int b = 3;

	int hap = a + b;
	int cha = a - b;
	int gop = a * b;
	int mok = a / b;
	int namuji = a % b; // % : 나머지 연산자

	printf("%d + %d = %d\n", a, b, hap);
	printf("%d - %d = %d\n", a, b, cha);
	printf("%d * %d = %d\n", a, b, gop);
	printf("%d / %d = %d\n", a, b, mok);
	printf("%d %% %d = %d\n", a, b, namuji);




	// float : 32비트(4바이트), 실수를 담는 데 쓰임
	float a = 9.8;
	float b = 3.14;

	float hap = a + b;
	float cha = a - b;
	float gop = a * b;
	float mok = a / b;
	

	printf("%f + %f = %f\n", a, b, hap);
	printf("%f - %f = %f\n", a, b, cha);
	printf("%f * %f = %f\n", a, b, gop);
	printf("%f / %f = %f\n", a, b, mok);
	*/
	
	
	// double : 64비트(8바이트), 실수를 담는 데 쓰임
	// 저장 공간이 2배가 되면 표현 가능한 숫자의 개수는 제곱이 됩니다.

	double a = 9.8;
	double b = 3.14;

	double hap = a + b;
	double cha = a - b;
	double gop = a * b;
	double mok = a / b;


	printf("%f + %f = %f\n", a, b, hap);
	printf("%f - %f = %f\n", a, b, cha);
	printf("%f * %f = %f\n", a, b, gop);
	printf("%f / %f = %f\n", a, b, mok);
}

// float :부동소수점(floating point)