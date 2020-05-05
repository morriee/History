/*
3. 알파벳을 입력받아서 그 다음 알파벳을 출력하는 프로그램을 만들어 보세요.
*/

#include <stdio.h>
int main() {
	char alpha;

	scanf_s("%c", &alpha);

	char nextalpha = alpha + 1;

	printf("%c\n", nextalpha);
}
