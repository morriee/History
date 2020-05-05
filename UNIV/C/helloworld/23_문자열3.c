#include <stdio.h>
#include <string.h>

int main() {
	char str1[] = "sample";
	char str2[] = "simple";

	int cmp = strcmp(str1, str2);		// 사전순 str1 > str2  =  -1 반대면 1 반환 같으면 0반환

	printf("%d\n", cmp);
}