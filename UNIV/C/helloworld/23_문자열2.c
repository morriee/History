#include <stdio.h>
#include <string.h>

int main() {
	char str[] = "Hello";
	char str2[100];
	char str3[100] = "Hello";

	//���ڿ��� ���� ���
	int len;		// ���� ����

	sizeof(str) / sizeof(char) - 1;		// null���ڸ� ������ ������ ���.. -1


	len = strlen(str);		// strlen() : ���ڿ��� ���� ����Լ�
	printf("���ڿ��� ���̴� %d\n", len);
	
	strcpy(str2, str);			//  strcpy(���ڸ� �޾ƾ��� ��(�纻), ����)
	// ���ڿ� ��ü�� ���� ���ڿ��� ����
	printf("str2�� �� : %s\n", str2);

	strcat(str3, "World!");		// Ư���� ���ڿ� �ڿ� Ư�� ���ڿ��� ���ٿ��ִ� �Լ�
	printf("%s\n", str3);
}