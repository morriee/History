
// ����
// �Է¹��� ���ڵ��� �Ųٷ� ���
// �ִ�, �ּ�
// ¦���� ����

#include <stdio.h>

int main() {
	int n;
	int arr[1000];	// �迭�� �鸸�� ���� ����

	printf("�Է��� ������ ���� �Է�: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}							////-> ��������� �迭�� �Է¹޴¹�.

	for (int i = n - 1; i >= 0; i--) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	
}