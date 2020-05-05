//연결리스트
#include <stdio.h>

//구조체 정의
struct node
{	//첫번째멤버 데이터 두번째 멤버 주소.
	char data;
	struct node *link;		//자기참조구조체: 자기가 자기구조체를 참조한다.
};

int main() {
	struct node a1, a2, a3;		//구조체노드를 쓰려면 이름이 있어야함.
	struct node *head;
	
	a1.data = 'A';
	a2.data = 'B';
	a3.data = 'C';

	//앞쪽에 데이터 채웠으니 서로 연결해야함. 구조체 변수는 연결되어 할당하지 않음 변수라서 각각 따른데에 저장되어있음
	
	head = &a1;
	a1.link = &a2;		//a1링크부분에 a2의 주소를 연결
	a2.link = &a3;
	a3.link = NULL; 

	//포인터를 이용하여 출력(포인터는 화살표만 사용함)
	printf("%c\n", head->data);		//a1.data -->'A'
	printf("%c\n", head->link->data);		//a2.data --->B
	printf("%c\n", head->link->link->data);		//a3.data--->C
	//link->link ->link 반복됨. for문사용..
	//과제->종합장에 코드를 적고 그림도 그려오기.
}