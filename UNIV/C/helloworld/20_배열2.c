#include <stdio.h>l

int main() {
	int arr[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };

	sizeof(arr);

	for (int i = 0; i < sizeof(arr) / sizeof(int) - 1; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}