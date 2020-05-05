// do-while

#include <stdio.h>

int main() {
	int i = 18;

	do {
		printf("%d\n", i);
		i++;
	} while (i <= 10);

}

// do-while 문은 i가 조건에 맞지 않더라도 do 를 한번은 실행시키고 while 의 조건으로 넘어가 완료시키는 반면
// whlie 문은 i가 while 의 조건에 맞지 않으면 아예 실행시키지 않는다.