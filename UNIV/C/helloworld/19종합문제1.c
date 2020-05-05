// 연산자 : + - / * % += -= ++ -- && || !
// 조건문 : if() switch()
// 반복문 : while() for()

// 1. 시험점수 입력
//  90 ~ 100 A 
//  80 ~ 89 B
//  70 ~ 79 C 
//  60 ~ 69 D 
//  50 ~ 59 E 

#include <stdio.h>

int main() {
	int score;
	scanf("%d", &score);  // &(앤퍼센트)를 붙이는 것을 초기화 라구함.

	if (score > 100 || score < 0)
		printf("잘못 입력하셨습니다.\n");
	else {

		if (score >= 90)
			printf("A\n");
		else if ( score >= 80)
			printf("B\n");
		else if (score >= 70)
			printf("C\n");
		else if (score >= 60)
			printf("D\n");
		else 
			printf("E\n");
	}
	
}