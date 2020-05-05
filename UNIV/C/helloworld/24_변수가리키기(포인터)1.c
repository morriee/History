// 포인터(pointer): 변수의 주소를 저장하는 변수
// 가리키는 자

#include <stdio.h>

int main() {
	int a = 20;

	int *ptr_a;		//포인터 선언,, 내가 가리킬 형의 변수를 일단 적고,별표하고, 포인터의 이름을 정해줌

	/*cf)
		char c ='h';
		char *ptr_c;
	*/

	ptr_a = &a;			// 포인터 a에 a의 주솟값을 넣은 상태
						// &a  ,, a의 주솟값

	//printf("%d\n", ptr_a);		// 실행시킬때마다 Ram의 상황이 조금씩 달라지므로 a라는 변수가 상황에 따라 그 위치가 계속해서 바뀌기 때문이다.
							// 따라서 실행할때 마다 주솟값이 바뀔수 있다.
	printf("a의 값: %d\n", a);
	printf("a의 주솟값 : %d\n", &a);
	printf("ptr_a에 저장된 값 : %d\n", ptr_a);
	printf("ptr_a가 가리키는 변수의 값 : %d\n", *ptr_a);		// 포인트선언과 다름.. ptr_a의 변수 자체를 사용하고 싶을 때 쓰는 형식
											//	*ptr_a = a

}								