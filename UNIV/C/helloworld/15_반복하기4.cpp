#include <stdio.h>

int main() {
	int n;

	do {
		printf("제발 0을 입력해주세요!!\n");
		scanf("%d", &n);
	} while (n != 0);
	printf("드디어 0을 입력하셨군요!\n");
}