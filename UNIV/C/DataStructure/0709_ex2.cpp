//����Ʈ�����

#include <stdio.h>

typedef struct TreeNode {
	struct TreeNode *left;
	int data;
	struct TreeNode *right;
}TreeNode;

/* �����忡 �ʱ� ����
			15
	n2= 4		20
 n1= 1		  16  25
*/

TreeNode n1 = { NULL, 1, NULL };		// ���ʰ� �����ʳ�尡 ��� null�϶� 1�� ����
TreeNode n2 = { NULL, 4, NULL };		//�ΰ��� ���϶� 4�� ���۷���Ʈ��
TreeNode n3 = { &n1, '*', &n2 };
TreeNode n4 = { NULL, 16, NULL };
TreeNode n5 = { NULL, 25, NULL };
TreeNode n6 = { &n4, '+', &n5 };
TreeNode n7 = { &n3, '+', &n6 };

TreeNode *exp = &n7;		//7�� ��尡 ��Ʈ��

int evaluate(TreeNode *root) {
	if (root == NULL) return 0;		// �޷��ִ� �ı��� ���� ��.
	if (root->left == NULL && root->right == NULL)	// ������ ������ ��尡 null �϶� �츮�� ����� ������
		return root->data;
	else {	//+�� ���� ���ǿ� ���� ����. ���ʰ� �������� ���� �ƴ�.
		int op1 = evaluate(root->left);
		int op2 = evaluate(root->right);
		printf("%d %c %d �� ����մϴ�..\n", op1, root->data, op2);
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

//��ü ����� ����
int get_node_count(TreeNode* node){ 
	int count = 0; 
	if (node != NULL) 
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	return count;
}

//Ʈ���� ����
int get_height(TreeNode* node) { int height = 0; 
if (node != NULL) 
	height = 1 + max(get_height(node->left), get_height(node->right)); 
return height; 
}

//�ܸ���尳��
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
	printf("������ ��� = %d\n",evaluate(exp));
	return 0;
	get_node_count(&count);
	printf("��ü ����� ����: %d", node);
}
//����
//����Ʈ���� Ȱ��
//����� ���� ���ϱ�
//����� �ܸ���� ���ϱ�
//���� ���ϱ�