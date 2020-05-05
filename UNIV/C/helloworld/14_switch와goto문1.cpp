// switch 

#include <stdio.h>

int main() {
	int choice;

	makeChoice:

	printf("새 게임 : 1\n");
	printf("불러오기 : 2\n");
	printf("설정 : 3\n");
	printf("크레딧 : 4\n");

	scanf("%d", &choice);

	switch (choice) {
	case 1:
		printf("새 게임 입니다.\n");
		break; // 입력이 맞으면 중괄호 밖으로나가 프로그램을 실행함.

	case 2:
		printf("불러오기 입니다.\n");
		break;

	case 3:
		printf("설정 입니다.\n");
		break;

	case 4:
		printf("크레딧 입니다.\n");
		break;
	default:
		printf("잘못 입력하셨습니다.\n");
		goto makeChoice;
		break;
	}
	/*
	if (choice == 1) {
		printf("새 게임 입니다.");
	}
	else if (choice == 2) {
		printf("불러오기 입니다.");
	}
	else if (choice == 3) {
		printf("설정 입니다.");
	}
	else if (choice == 4) {
		printf("크레딧 입니다.");
	}
	else {
		printf("잘못 입력하셨습니다.\n");
	}
	*/

}