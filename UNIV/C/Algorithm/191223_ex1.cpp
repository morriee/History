#include <stdio.h>

int gugudan(int n);
int main() {
	int n;
	printf("���� �Է��ϼ���>> ");
	scanf_s("%d\n", &n);


	gugudan(n);
	return 0;
}

int gugudan(int n) {
	int gob = 0;
	for (int i = 1; i < 10; i++) {
		int res = n * i;
		printf("%d x %d = %d\n", n, i, res);
	}//�������� res ����
	return 0;
}