// �� ������, �� ������

#include <stdio.h>

int main() {
	int a, b;
	scanf("%d%d", &a, &b);

	// bool: ������ ����� ���� (1����Ʈ = 8��Ʈ)
	bool p = a > b;

	// 2 > 3 -> ����
	// ��: 1, ���� : 0

	bool q = a < b;
	bool r = a == b; // ==: ����(�񱳿�����)

	// a >= b : a�� b���� ũ�ų� ����
	// a <= b : a�� b���� �۰ų� ����
	// a != b : a�� b�� �ƴϴ�

	printf("%d\n", p);
	printf("%d\n", q);
	printf("%d\n", r);
}