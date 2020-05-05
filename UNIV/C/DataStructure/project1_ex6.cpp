//매개변수 전달 기법
//1. 값 전달 기법-별도의 메모리공간이 요구됨.
//2. 주소 전달 기법

#include <stdio.h>

void swap1(int x, int y) { //값이 복사되어 전달됨. 그래서 x와y에 대한 공간이 필요함.

	//값 회전
	int tmp = x;
	x = y;
	y = tmp;
	printf("x = %d, y = %d\n", x, y);	//20, 10
}

void swap2(int *x, int *y) {//a와b의 주소를 전달받아야되기 때문에 주소를 담는 변수( 포인터변수)를 사용하기. 여기서 x는 포인터변수라고 머리핀꼳은거고,
	int tmp = *x;	//여기서 *x는 x의 주소로 가시오라는 뜻.
	*x = *y;
	*y = tmp;	//tmp는 주소가 아니라 값을 저장한 데이터변수값.
	printf("*x = %d, *y = %d\n", *x, *y);
}

int main() {
	int a = 10, b = 20;
	
	//두 수를 교환하는 함수
	swap1(a, b);
	printf("a =%d, b=%d\n", a, b);	//10,20

	//주소를 전달하는 함수
	swap2(&a, &b);
	printf("a = %d, b = %d\n", a, b);	//20,10
}