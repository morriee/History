//�迭�� �Լ�

#include <stdio.h>

void test(int b[]) {		//int *b == int b[]  : b�� �ּҰ��� ���޵�->���� b�� �����ͺ���.
	b[1] = 100;
}

int main() {
	int a[3] = { 10,20,30 };

	test(a);		// �ּ����ޱ��: �迭�� �� ��ü�� ���� ->�迭�� �̸��� ���� �ּ���
	for (int i = 0; i < 3; i++) printf("%3d\n", a[i]);
}