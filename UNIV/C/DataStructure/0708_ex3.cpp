//mp3재생프로그램만들기
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[50];
typedef struct DlistNode {	//double list node
	struct DlistNode *llink;		//left link
	element data;
	struct DlistNode *rlink;		//right link
}DlistNode;

//llink,rlink 모두 자기자신의 주소값을 갖도록 초기화
void init(DlistNode *phead) {
	//노드 구성.
	phead->llink = phead;
	phead->rlink = phead;
}
DlistNode *current;		//전역변수

void dinsert(DlistNode *before, const element value) {		//before나 phead나...
	DlistNode *newnode = (DlistNode*)malloc(sizeof(DlistNode));
	//데이터를 넣을 함수
	strcpy(newnode->data, value);		//정수면 값을 받을수 있지만 문자열은 복사해야함 element에는 곡이름
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;

}

void ddelete(DlistNode *head, DlistNode *removed) {
	if (head == removed) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

void print_list(DlistNode *phead) {
	//현재 플레이 되고 있는 곡은 #기호 넣기.
	DlistNode *p;
	for (p = phead->rlink; p != phead; p = p->rlink) {		// 이 코드가 노드를 한바퀴만 돈것. 탐색기가 한바퀴 돌았단 뜻.한번 다 훑었다.
		if (p == current) {
			printf("←|# %s #|→", p->data);
		}
		else { printf("←| %s |→", p->data); }
		printf("\n");
	}

}

int main() {
	DlistNode *head = (DlistNode*)malloc(sizeof(DlistNode));
	//head의 시작과 끝만 가리킬수있도록 left와 right를 사용
	init(head);
	dinsert(head, "스내핑");//const
	dinsert(head, "롤러코스터");
	dinsert(head, "12시");

	current = head->rlink;	//첫번째 곡은 12시
	print_list(head);

	char ch;
	do {
		printf("명령을 입력하시오.(<,>,q):  ");
		ch = getchar();		// getchar는 한글자 입력받음
		if (ch == '<') {
			//이전 곡 선택
			current = current->llink;	//현재 곡의 이전== 현재 곡의 왼쪽
			if (current == head) {		//만약 이전 곡이 없을때..
				current = current->llink;
			}
		}
		else if (ch == '>'){
			//다음 곡 선택
			current = current ->rlink;	
			//맨 마지막 곡에서 다음 곡을 누르면 head를 만남.head에는 곡이 업슴
			if (current == head) {
				current = current->rlink;
			}
		}
		print_list(head);
		getchar();	// 버퍼에 enter키가 남아잇지 않게 하는 코드
	} while (ch != 'q');	//큐가 아닌 경우에 돌게 하자.
}