//배열과 함수

#include <stdio.h>

void test(int b[]) {		//int *b == int b[]  : b의 주소값이 전달됨->따라서 b는 포인터변수.
	b[1] = 100;
}

int main() {
	int a[3] = { 10,20,30 };

	test(a);		// 주소전달기법: 배열의 값 전체를 전달 ->배열의 이름은 시작 주소임
	for (int i = 0; i < 3; i++) printf("%3d\n", a[i]);
}