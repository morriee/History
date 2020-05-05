#include <stdio.h>
#include <string.h>

int main() {
	char str[] = "Hello";
	char str2[100];
	char str3[100] = "Hello";

	//문자열의 길이 출력
	int len;		// 길이 저장

	sizeof(str) / sizeof(char) - 1;		// null문자를 제외한 나머지 계산.. -1


	len = strlen(str);		// strlen() : 문자열의 길이 계산함수
	printf("문자열의 길이는 %d\n", len);
	
	strcpy(str2, str);			//  strcpy(문자를 받아야할 거(사본), 원본)
	// 문자열 전체를 따른 문자열로 복사
	printf("str2의 값 : %s\n", str2);

	strcat(str3, "World!");		// 특정한 문자열 뒤에 특정 문자열을 덧붙여주는 함수
	printf("%s\n", str3);
}