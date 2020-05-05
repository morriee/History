#include <stdio.h>

int main() {
	int a = 5;
	int b = 3;

	int hap = a + b;
	int cha = a - b;
	int gop = a * b;
	int mok = a / b;

	printf("%d + %d = %d\n", a, b, hap);
	printf("%d - %d = %d\n", a, b, cha);
	printf("%d * %d = %d\n", a, b, gop);
	printf("%d / %d = %d\n", a, b, mok);
}

// 이 프로젝트는 변수가 5와 3으로 정해져 있기 때문에 프로그램을 실행시키면 같은 화면만 뜨므로 재미가 없다.
// 따라서 이번 강의 시간에는 직접 입력을 받아 사용하는 프로그램을 알려주려한다.