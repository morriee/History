//지역변수란
#include <stdio.h>

int main() {

	int sum = 0;	//지역변수-함수(블록{ }) 내에서 선언(메모리 요청)된 변수
					//모든 지역변수는 스택(LIFO)에 보관됨.

	for (int i=1; i < 11; i++) {
	
		sum += i;
	
	}	//지역변수는 블록이 끝나면 회수(소멸)
	
	printf("%d\n",sum);

}//sum지역변수는 이 블록에서 끝남