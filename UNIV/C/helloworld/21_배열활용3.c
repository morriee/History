#include <stdio.h>

int main() {
	int n;
	int arr[100];

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int count = 0;					// count가 
	for (int i = 0; i < n; i++) {	// 이 조건을 만족하고
		if (arr[i] % 2 == 0) {		// 짝수이면
			count++;				// count에 1씩 더하라.
		}		
	}

	printf("%d\n", count);
}