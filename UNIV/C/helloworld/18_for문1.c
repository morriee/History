// break : 반복문 한개를 빠져 나옴.
// continue
// 중첩 for 문

/* 숫자 입력 -> 숫자 출력
	1번째: 7
	2번째: 5
	..
	15번째 끗
*/

#include <stdio.h>

int main() {
	for (int i = 1; ; i++) {
		int k;
		scanf("%d", &k);

		if (k == 0)  // if문에 문장이 한개면 중괄호를 생략해도 됌.
			break;


		printf("%d번쨰: %d\n", i, k); // if문에 안걸리면 출력.
	}
}