// ���� �ڸ����� 3,6,9�� ��� * ǥ��
// 1 2 * 4 5 * 7 8 * 10 11 12 * 14 15 * 17 ...n

#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		int k = i % 10;	// i�� ���� �ڸ��� 
		if (k == 3 || k == 6 || k == 9) {
			printf("* ");
		}
		else {
			printf("%d", i);
		}
	}
	printf("\n");
}