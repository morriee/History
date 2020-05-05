// 입력과 출력을 깔끔하게 정리 할 수록 뇌구조가 잘 짜여있는것.
#include <stdio.h>

void test1() {	//반환하지 않기로 했으니, 여기서 출력문찍기.
	int sum = 0;	
	for (int i = 1; i < 11; i++) {
		sum += i;
	}	
	printf("test1()의 sum = %d ", sum);
}

int test2() {	// 정수형으로 반환하기로 하였으니, 여기서 출력을 찍으면 살짝 웃긴것.
	int sum = 0;
	for (int i = 1; i < 11; i++) {
		sum += i;
	}
	return sum;
}

void test3(int x) {
	int sum = 0;
	for (int i = 1; i < x; i++) {
		sum += i;
	}
	printf("test3()의 sum = %d ", sum);
}

int test4(int x) {	
	int sum=0;
	for (int i = 1; i < x; i++) {
	 sum += i;
	}
	printf("test4()의 sum = %d ", sum);
	return 0;
}

int main() {
	int res;	//선언문:메모리를요청한다.

	test1();
	printf("\n");

	//함수의 결과를 반환하여 쓰려면, 결과를 저장할 값을 둘 변수를 만들어줘야 사용가능.
	res = test2();
	printf("test2()의 sum = %d ", res);
	//또는 호출하여 반환한다는 논리를 사용하여 다음과 같이 해도 괜춘
	printf("test2()의 sum = %d ", test2());
	printf("\n");

	int x = 10;		//지역변수의 선언 + 초기화
	test3(x);	//x는 실매개변수: 변수, 상수, 수식도 가능.
	printf("\n");

	test4(100);
	printf("test4()의 sum =%d\n", test4(x));
	printf("test4()의 sum = %d\n", test4(34));
	printf("\n");

}

