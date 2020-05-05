#include <stdio.h>

int gugudan(int n);
int main() {
	int n;
	printf("단을 입력하세요>> ");
	scanf_s("%d\n", &n);


	gugudan(n);
	return 0;
}

int gugudan(int n) {
	int gob = 0;
	for (int i = 1; i < 10; i++) {
		int res = n * i;
		printf("%d x %d = %d\n", n, i, res);
	}//지역변수 res 제거
	return 0;
}