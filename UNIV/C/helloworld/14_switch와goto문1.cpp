// switch 

#include <stdio.h>

int main() {
	int choice;

	makeChoice:

	printf("�� ���� : 1\n");
	printf("�ҷ����� : 2\n");
	printf("���� : 3\n");
	printf("ũ���� : 4\n");

	scanf("%d", &choice);

	switch (choice) {
	case 1:
		printf("�� ���� �Դϴ�.\n");
		break; // �Է��� ������ �߰�ȣ �����γ��� ���α׷��� ������.

	case 2:
		printf("�ҷ����� �Դϴ�.\n");
		break;

	case 3:
		printf("���� �Դϴ�.\n");
		break;

	case 4:
		printf("ũ���� �Դϴ�.\n");
		break;
	default:
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
		goto makeChoice;
		break;
	}
	/*
	if (choice == 1) {
		printf("�� ���� �Դϴ�.");
	}
	else if (choice == 2) {
		printf("�ҷ����� �Դϴ�.");
	}
	else if (choice == 3) {
		printf("���� �Դϴ�.");
	}
	else if (choice == 4) {
		printf("ũ���� �Դϴ�.");
	}
	else {
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
	}
	*/

}