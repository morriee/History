// 문자열:  문자들이 열거

#include <stdio.h>

int main() {
	char arr[]="Hello, world!";		// 문자열 선언 = 초기값지정.

	printf("배열의 크기: %d\n",sizeof(arr) / sizeof(char));  //-> 14
	//printf("%s\n", arr);


	// 문자열 입력받기

	char s[100];	

	scanf("%s", s);		// &붙이면 오류.

	printf("%s\n", s);
}