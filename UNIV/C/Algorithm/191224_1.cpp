#define _CRT_SECURE_NO_WARNING
// 배열의 기초
#include <stdio.h>

int main() {
	int a[] = {-1000, 2,1,5,7,3 };		//0번째 인덱스는 비므로 아무값이나 넣어줌.
	for (int i = 1; i <= 5; i++) {			//0번째 인덱스는 제외함.
		printf("%3d", a[i]);
	}
	printf("\n노드 1의 왼쪽 자식노드와 오른쪽 자식노드를 찾아보자\n");
	printf("노드1의 왼쪽 노드:%d", a[2 * 2]);		//7
	printf("노드1의 오른쪽 노드:%d", a[2 * 2+1]);		//3
}

/* 중간고사
	 완전 이진트리 : 왼쪽에서 오른쪽으로 채워나감.
									  2
								1         5
							7     3

		2 1 5 7 3	 - 값
	[  1 2 3 4 5  ]  - 인덱스
*/