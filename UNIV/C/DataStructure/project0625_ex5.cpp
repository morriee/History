//서로**다른 타입을 가진 기억 장소의 연속적인 모임을 허용한 것
//구조체 , 사용자 정의 자료형

#include <stdio.h>

//구조체 정의
struct sample {	
	int id;		//id에 데이터를 저장할 꺼고 그럴려면 메모리를 만들어줘야하고 그러면 선언문이 필요함.main에
	char ch;
};

int main() {
	struct sample per;// 구조체 변수를 선언, 메모리 할당(아직 값을 넣지 않음)
	per.id = 1004;
	per.ch = 'A';		//쩜을 이용해 값을 넣는다.


	//int 형의 배열일경우엔 for문을 돌릴 수 있으나, 구조체는 그럴 순없지만 변수 하나하나를 이뻐해줄수있음. 
	printf("%d, %c\n", per.id, per.ch);


	//구조체 포인터변수 선언 + 초기화(관련된 변수의 주소값을 가져와야함, 그래야 구조체 포인터 변수 선언을 하여 사용 가능) *==아스테릭스
	struct sample *p = &per;
	printf("%d\n", p->id);
	printf("%d\n", p->ch);

	printf("구조체의 크기 =%d\n", sizeof(struct sample));
	printf("구조체의 크기 =%d\n", sizeof(per));
}
