//수식트리계산

#include <stdio.h>

typedef struct TreeNode {
	struct TreeNode *left;
	int data;
	struct TreeNode *right;
}TreeNode;

/* 종합장에 필기 참고
			15
	n2= 4		20
 n1= 1		  16  25
*/

TreeNode n1 = { NULL, 1, NULL };		// 왼쪽과 오른쪽노드가 모두 null일때 1을 꺼냄
TreeNode n2 = { NULL, 4, NULL };		//두개가 널일때 4를 오퍼레이트함
TreeNode n3 = { &n1, '*', &n2 };
TreeNode n4 = { NULL, 16, NULL };
TreeNode n5 = { NULL, 25, NULL };
TreeNode n6 = { &n4, '+', &n5 };
TreeNode n7 = { &n3, '+', &n6 };

TreeNode *exp = &n7;		//7번 노드가 루트임

int evaluate(TreeNode *root) {
	if (root == NULL) return 0;		// 달려있는 식구가 없을 때.
	if (root->left == NULL && root->right == NULL)	// 왼족과 오른쪽 노드가 null 일때 우리가 사용할 데이터
		return root->data;
	else {	//+가 위의 조건에 맞지 않음. 왼쪽과 오른쪽이 널이 아님.
		int op1 = evaluate(root->left);
		int op2 = evaluate(root->right);
		printf("%d %c %d 을 계산합니다..\n", op1, root->data, op2);
		switch (root->data)
		{
		case '+': return op1 + op2;
		case '-': return op1 - op2;
		case '*': return op1 * op2;
		case '/': return op1 / op2;
		}
	}
	return 0;
}

//전체 노드의 개수
int get_node_count(TreeNode* node){ 
	int count = 0; 
	if (node != NULL) 
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	return count;
}

//트리의 높이
int get_height(TreeNode* node) { int height = 0; 
if (node != NULL) 
	height = 1 + max(get_height(node->left), get_height(node->right)); 
return height; 
}

//단말노드개수
int get_leaf_count(TreeNode* node) {
	int count = 0;
	if (node != NULL){
		if (node->left == NULL && node->right == NULL)
			return 1;
		else count = get_leaf_count(node->left) + get_leaf_count(node->right);
	}
	return count;
}
int main() {
	printf("수식의 결과 = %d\n",evaluate(exp));
	return 0;
	get_node_count(&count);
	printf("전체 노드의 개수: %d", node);
}
//과제
//위의트리를 활용
//노드의 개수 구하기
//노드의 단말계수 구하기
//높이 구하기