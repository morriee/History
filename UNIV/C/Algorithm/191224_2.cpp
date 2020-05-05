//구조체 - "서로 다른 타입"에 대해서도 저장 가능한 연속적 메모리 공간
//배열의 정의 - "같은 자료형"에 대한 연속적 메모리 공간

#include <stdio.h>

// 두개의 데이터를 연속적으로 저장함.
//구조체 정의- 틀을 만듦
struct person {
	int no;	//number
	double weight;
};

int main() {

	//구조체 변수를 선언 - 할당된 메모리 이름
	struct person a;		

	// int a[2];

	a.no = 100;
	a.weight = 98.5;		//점으로 메모리에 접근.
	printf("a.no = %d\n", a.no);
	printf("a.weight = %f\n", a.weight);
										/*잘못된 표기법
												person.no ------(x)
												person.a --------(x)
										*/

	// 포인터 변수 p를 선언
	struct person *p;		//p에는 주소를 저장.
	p = &a;		//a 메모리의 주소를 포인터변수 p에 넣는다.
	printf("구조체 a의 주소: %d\n", p);
	printf("p->no = %d\n", p->no);
	printf("p->weight = %f\n", p->weight);
}