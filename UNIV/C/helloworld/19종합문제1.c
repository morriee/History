// ������ : + - / * % += -= ++ -- && || !
// ���ǹ� : if() switch()
// �ݺ��� : while() for()

// 1. �������� �Է�
//  90 ~ 100 A 
//  80 ~ 89 B
//  70 ~ 79 C 
//  60 ~ 69 D 
//  50 ~ 59 E 

#include <stdio.h>

int main() {
	int score;
	scanf("%d", &score);  // &(���ۼ�Ʈ)�� ���̴� ���� �ʱ�ȭ ����.

	if (score > 100 || score < 0)
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
	else {

		if (score >= 90)
			printf("A\n");
		else if ( score >= 80)
			printf("B\n");
		else if (score >= 70)
			printf("C\n");
		else if (score >= 60)
			printf("D\n");
		else 
			printf("E\n");
	}
	
}