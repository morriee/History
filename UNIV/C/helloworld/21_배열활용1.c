
// 목차
// 입력받은 숫자들을 거꾸로 출력
// 최대, 최소
// 짝수의 개수

#include <stdio.h>

int main() {
	int n;
	int arr[1000];	// 배열은 백만개 까지 가능

	printf("입력할 숫자의 개수 입력: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}							////-> 여기까지가 배열을 입력받는법.

	for (int i = n - 1; i >= 0; i--) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	
}