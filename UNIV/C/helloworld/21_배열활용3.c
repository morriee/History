#include <stdio.h>

int main() {
	int n;
	int arr[100];

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int count = 0;					// count�� 
	for (int i = 0; i < n; i++) {	// �� ������ �����ϰ�
		if (arr[i] % 2 == 0) {		// ¦���̸�
			count++;				// count�� 1�� ���϶�.
		}		
	}

	printf("%d\n", count);
}