//이중연결리스트
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
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

void dinsert(DlistNode *before, element value) {		//before나 phead나...
	DlistNode *newnode = (DlistNode*)malloc(sizeof(DlistNode));
	//데이터를 넣을 함수
	newnode->data = value;	//10
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;

}

void print_dlist(DlistNode *phead) {
	DlistNode *p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("←| |%d| |→ ", p->data);
	}
	printf("\n");
}

int main() {
	DlistNode *head = (DlistNode*)malloc(sizeof(DlistNode));		
	//head의 시작과 끝만 가리킬수있도록 left와 right를 사용
	init(head);
	dinsert(head, 10);
	dinsert(head, 20);
	dinsert(head, 30);
	dinsert(head, 40);

	print_dlist(head);
}