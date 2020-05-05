#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode{
	struct TreeNode *left;
	element data;
	struct TreeNode *right;
}TreeNode;

TreeNode* new_node(element item) {

	//Ű���� �޾Ƽ� ���⼭ �����Ҵ��� �޴´�.
	//���� �Ҵ� �� Ű�� ����
	TreeNode *temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->data = item;
	temp->left = temp->right = NULL;		//�ʱ⿡�� ���� �� �ƹ��͵� ����.
	return temp;	//�ּҸ� ��ȯ�Ͽ�...insert_node�Լ����� newnode(key)�� �ּҰ� ��.
}

TreeNode * insert_node(TreeNode *node, element key) {
	
	//��å �ڵ�
	if (node == NULL) return new_node(key);	//temp�� �ּҰ� ���⿡ ����..Ʈ���� ù��° ���.�϶��� ���⿡ �ִ� Ű���� �׳� �����϶�.
	if (key < node->data) {//���� ��尡 ����Ű�� �ִ� �����ʹ� 17�̰� ���� ����� Ű���� 6�̴�. �׷��� Ű���� ���->�����ͺ��� �����Ƿ� �Ʒ� ����
		node->left = insert_node(node->left, key);// ���⿡ new_node���� ��. �ֳ��ϸ� 17�� ���� ��忡�� null���� �� �ֱ� �����̴�.
	}
	else if (key > node->data) {// ���ε��� Ű�� 10�� ���� ����� ������(6) ���� ũ�Ƿ�.. ������ ���� ��
		node->right = insert_node(node->right, key);
	}
	//���⼭ ũ�ų� ���� ���� �����̳� �����ʿ� ������ �������� ���� ���̶�� ����.
	return node;
}

TreeNode *search(TreeNode *node, element key) {
	if (node == NULL) return NULL;
	if (key == node->data) return node;	//�ּҹ�ȯ
	else if (key < node->data) {
		return search(node->left, key);		//Ű���� �����ͺ��� �� ������ �� �׾Ʒ� ���� ������ �񱳵� �� ������ serach�Լ� �θ���
	}
	else
		return search(node->right, key);
}

TreeNode *search_while(TreeNode *node, element key) {
	while (node !=NULL) {	//node�� null�̸� �񱳸� �����״ϱ� �Ա����� �ɷ���.
		if (key == node->data) return node;
		else if (key < node->data)
			node = node->left;
		else
			node = node->right;
	}
	return NULL;	//return node; ���� ǥ��. �׷��� ����� �����ϴ� ���� ����ϹǷ�, null..
}

element min_value_node(TreeNode *node) {
	TreeNode *current = node->right;
	while (current->left != NULL)
		current = current->left;		//���� ����� ���� ����Ʈ���� ���� ���ٸ� �װ� ������ �̹Ƿ� ����.
	return current->data;
}

void inorder(TreeNode *root) {
	if (root !=NULL) {
		inorder(root->left);
		printf("[%d] ", root->data);
		inorder(root->right);
	}
}
int main() {
	TreeNode *root = NULL;

	root = insert_node(root, 17);
	root = insert_node(root, 6);
	root = insert_node(root, 10);
	root = insert_node(root, 3);
	root = insert_node(root, 9);
	root = insert_node(root, 31);
	root = insert_node(root, 8);
	root = insert_node(root, 42);
	root = insert_node(root, 25);
	inorder(root);
	printf("\n");
	//inoder = 6-10-17
	
	//������ �� ��尪 ���� = ������ ����Ʈ������ ���� ���� ���� ã��. �ֳ��ϸ� �߰��� ���� ���ﶧ Ʈ���� ��鸮�� �ȵǴϱ�.
	element data = min_value_node(root);
	printf("������ ����Ʈ���� �ּڰ� = %d\n", data);//25


	//TreeNode *tmp = search(root, 13);			// element ���� �ٲ㺸�� �Ʒ� �� ���� ����
	TreeNode *tmp = search_while(root, 5);			

	if (tmp == NULL)
		printf("��尪�� Ʈ���� �����ϴ�.\n");
	else
		printf("��尪�� Ʈ���� �ֽ��ϴ�.\n");
}