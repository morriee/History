// 무한 반복

#include <stdio.h>

int main() {
	int i = 1;

	while (true) {
		printf("%d ", i);
		i++;
	}
}

//  while문 안에 true를 적어주면 무한반복.
// true로 들어가면 무조건 조건에 부합하다는 뜻과도 같으므로 실행이됌.