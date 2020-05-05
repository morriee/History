// 형변환 : 자료형을 다른 자료형으로 바꾸는 작업.

#include <stdio.h>

int main() {
	int math = 90, korean = 95, engllish = 96;
	int sum = math + korean + engllish;
	double avg = (double)sum / 3;

	printf("%f\n", avg);
}

// ** 자료형 **
// 정수 / 정수 = 정수
// 실수 / 정수 = 실수
// 정수 / 실수       는 안 할 수록 좋음. 하더라도 실수로 형변환을 한 뒤에 나누는 게 좋다.
// 실수 / 실수 = 실수

// 정수 + 정수 = 정수
// 정수 + 실수 = 실수
// 실수 + 실수 = 실수
// 빼기(-), 곱하기(*)도 똑같은 원리가 적용됨.