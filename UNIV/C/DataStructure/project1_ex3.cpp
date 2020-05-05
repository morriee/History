//전역변수란
//실행을 하기전 결과값 예상하여 적어놓기.

#include <stdio.h>

int g = 100;	//전역변수-일반 메모리에 할당. 프로그램 시작(선언된 시작)에서 끝까지

int main() {
	int a = 1, b = 1;
	g++;
	{
		int a = 10, c = 11;
		printf("a = %d , b =%d\n", a, b);	
		printf("b=%d\n", ++b);		
		g++;

	}

	printf("a =%d, b = %d\n", a, b);	//1,2
	printf("g =%d\n", g);	//102



}