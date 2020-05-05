//트리
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

TreeNode n1 = { NULL, 1, NULL };
TreeNode n2 = { &n1, 4, NULL };
TreeNode n3 = { NULL, 16, NULL };
TreeNode n4 = { NULL, 25, NULL };
TreeNode n5 = { &n3, 20, &n4 };
TreeNode n6 = { &n2, 15, &n5};

void preorder(TreeNode *root) {//재귀함수의 강점.
	if (root) {
		printf("[%d] ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(TreeNode *root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->data);
	}
}

void inorder(TreeNode *root) {
	if (root) {
		inorder(root->left); 
		printf("[%d] ", root->data);
		inorder(root->right); 
	}
}

int main() {
	TreeNode *root = &n6;
	printf("preorder = ");
	preorder(root);
	printf("\n");

	printf("postorder = ");
	postorder(root);
	printf("\n");

	printf("inorder = ");
	inorder(root);
	printf("\n");
}