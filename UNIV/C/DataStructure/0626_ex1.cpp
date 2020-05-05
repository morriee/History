#include <stdio.h>

struct person
{// 이 구조체의 크기는 20+4
	char name[20];	//배열	
	int id;	//변수
};

struct person input_st() {
	struct person s;		//struct person 타입의 매개변수 s. 메모리 24byte만듬
	printf("이름입력>>");
	gets_s(s.name);	//	== scanf_s("%s", s.name);	문자열로 입력받음
	printf("번호입력>>");
	scanf_s("%d", &s.id);		//c++, cin>> 입력받는 함수
	return s;

	/*
	gets--->string의 약자. 보통 s가 붙으면 여러개의 문자열을 얻는다는 뜻.
	getc/getch/getchar은 캐릭터의 약자임. 
	
	*/


}//-->함수가 끝나면 지역변수는 소멸된다*

void output_st(struct person *d);		//함수의 원형(prototype) : 컴파일러에게 한수의 정보를 제공.
														// 이 부분 없으면 빌드오류남. 왜냐하면 컴파일은 위에서 부터 계산이되기 때문에, 메인 아래쪽에 output()이 있는 것을 모르고 메인에 output()이 정의되지 않았다고 에러가 뜸.

int main() {
	struct person d;		//d: 구조체 변수, 실제 메모리가 24byte할당됨.
	//입력이 있어야 출력도 있음.
	printf("----------------입력하세요----------------\n");
	d = input_st();		//struct person이라는 타입으로 리턴
	//d는 메인의 지역 구조체 변수...output_st()에서 사용불가능.
	printf("------------------출력화면-----------------\n");

	output_st(&d);		//정의: 만드는것.


	printf("구조체의 크기: %d\n", sizeof(struct person));		//데이터타입+ 구조체이름 --->24
}

void output_st(struct person *d) {		//여기서의 d메모리 공간과 main에서의 d메모리 공간은 전혀 다른 공간임.그래서 똑같은 값을 두번 메모리를 할당함-->낭비
														// but, 주소로 받으면 메모리를 공유하기 때문에 효율성증가
	printf("이름 : %s\n", d->name);
	printf("번호 : %d\n", d->id);			//포인터는 화살표.
}