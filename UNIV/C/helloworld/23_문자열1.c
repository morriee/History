// ���ڿ�:  ���ڵ��� ����

#include <stdio.h>

int main() {
	char arr[]="Hello, world!";		// ���ڿ� ���� = �ʱⰪ����.

	printf("�迭�� ũ��: %d\n",sizeof(arr) / sizeof(char));  //-> 14
	//printf("%s\n", arr);


	// ���ڿ� �Է¹ޱ�

	char s[100];	

	scanf("%s", s);		// &���̸� ����.

	printf("%s\n", s);
}