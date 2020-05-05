//7.10 ����Ž�� ����/Ž�� ����
//7.11 ����Ž�� ���� ����
#include<stdio.h>
#include<stdlib.h>

typedef int element; //�� ��ȯ 

typedef struct TreeNode { //����ü ���� 
	struct TreeNode *left;
	element data;
	struct TreeNode *right;
}TreeNode;
TreeNode* min_value_node(TreeNode *node);
TreeNode *new_node(element item) { //��� ������ ���� �޸� ���� �Ҵ�
	TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode *insert_node(TreeNode *node, element key) {
	if (node == NULL) return new_node(key); //Ʈ���� ù��° ���
	if (key < node->data) {//Ű���� �����Ͱ� ũ�ٸ� ��������
		node->left = insert_node(node->left, key); //�Լ��� ��ȯȣ���Ͽ� ���� �� �����Ͽ� ������ ����
	}
	else if (key > node->data) { //���� �����ͺ��� �Է¹��� �����Ͱ� ũ�ٸ� ���������� ����
		node->right = insert_node(node->right, key); //�Լ��� ��ȯȣ���Ͽ� ���� �� �����Ͽ� ������ ����

	}
	return node;

}
void inorder(TreeNode *root) { //������ȸ 
	if (root != NULL) {
		inorder(root->left);
		printf("[%d]-", root->data);
		inorder(root->right);
	}
}
TreeNode *search(TreeNode *node, element key) { //Ž��(�˻�) �κ� 
	if (node == NULL) return NULL;
	if (key == node->data)return node;
	else if (key < node->data)
		return search(node->left, key);
	else
		return search(node->right, key);
}
TreeNode *search_while(TreeNode *node, element key) {
	while (node != NULL) { //��尡 null�� �ƴҰ�� �ݺ� 
		if (key == node->data)return node; //���� ã���� �ϴ� �����Ͱ� ��ġ�� ��� �ٷ� ��� ���� 
		else if (key < node->data) //�����ͺ��� ��尡 Ŭ ��� ����� ���� Ž�� 
			node = node->left;
		else //�����ͺ��� ��尡 ������� ����� ���� Ž�� 
			node = node->right;
	}
	return NULL;
}

TreeNode* delete_node(TreeNode *root, element key) {//->�� �κ� ���ؾȰ��� ��������.
	//���࿡ ��Ʈ�� ���ų� ��Ʈ���� ���� �Ǹ� ����.
	if (root == NULL) return root;
	if (key < root->data)		//��Ʈ>Ű-->��Ʈ�� �������� ��Ʈ�� �̵�.
		root->left = delete_node(root->left, key);
	else if (key > root->data)	//��Ʈ<Ű-->��Ʈ�� ���������� ��Ʈ�� �̵�.
		root->right = delete_node(root->right, key);
	else{
		//�����ڵ尡 ���ư��� �κ�.. Ű==��Ʈ
		//key ==root->data, ������ ��带 ã��
		//case1, case2�� ���
		if (root->left == NULL) {		//8�� Ű������ ũ���� ������ ����.==������ Ű�� ã�Ҵ�!-->�̳��� �ڽ��� �Ѱ����� �ΰ����� ã�ƾ���.�׷��� ���� ������ ������ ���� Ȯ��
			TreeNode *temp = root->right;
			free(root);	//������ 8�̶�� ��Ʈ�� ��������. �ֳ��ϸ� 9�� ���� ��忡 �ּҰ� �ֱ� ������.
			return temp;		//�� ���ϰ��� else�� �����ϱ� ���� 62��°�� ȣ��� delete_node(left)�� ȣ���ߴ� �̰��� ������.
			/*�ٽø��ؼ� 8���� 9���� �ּҸ� ��������ϴµ� ����� �����ϱ⿣ �����ָ� ��������, ��ǻ�Ϳ����� 9�� ���������� ȣ���ߴ� ������ ���� ���ϵ�.
			8���忡���� �ڱⰡ ���ʿ� �ִ��� �����ʿ� �ִ��� �𸣴ϱ� �θ��忡�� ���� ���. �׷��� �ڱⰡ ���� �ڽ��� ���� �˰Ե�. �׷��� �ڽ��� 
			��ġ�� ã�� ������ �θ� �ڽ��� ��� ���Ҵ��� �ڽ��� �������ϴ� ����.
			�θ�� �ڽİ��� ���踦 �������� �ڽ��� ����� �ּҸ� �θ� �ٽ� �������� �Ǵ� ����. �̰��� ���⼱ ������ ��Ÿ��.*/
		}
		else if (root->right == NULL) {
			TreeNode *temp = root->left;	//���� ������ ����� �ּҸ� �θ��忡 ������ �ϰ�
			free(root);		//������ ��带 ����
			return temp;	//temp�� ������ ������ ����� �ڽĳ����� �ҸӴ� ��忡 ����.
		}
	//case3�� ���, ����Ʈ���Ǽ��� 2���ΰ��
	
		else {
			TreeNode *temp = min_value_node(root->right);
			root->data = temp->data;
			root->right = delete_node(root->right, temp->data);
		}
	}
	return root;
}

//���� Ÿ�� �ٲ�.
TreeNode* min_value_node(TreeNode *node) { //������ ����Ʈ���� �ּҰ� ã�� 
	TreeNode *current = node; //���������� Ž���Ҽ��ְԲ� ������ �������ִ� ���� ����
								// node: ��������� right �ּҰ�
	
	while (current->left != NULL) { //current�� ����Ű�� left���� null�� �ƴҰ�� Ž��
		current = current->left;
	}
	return current;
}
int main(void) {
	TreeNode *root = NULL;
	//�� ���� �κ� 
	root = insert_node(root, 17);
	root = insert_node(root, 6);
	root = insert_node(root, 10);
	root = insert_node(root, 31);
	root = insert_node(root, 3);
	root = insert_node(root, 9);
	root = insert_node(root, 8);
	root = insert_node(root, 35);
	root = insert_node(root, 42);
	root = insert_node(root, 27);
	

	//Ž�� �κ� 
	printf("\n");
	TreeNode *temp = search(root, 8);
	if (temp == NULL)
		printf("��尪�� Ʈ���� ����");
	else
		printf("��尪�� Ʈ���� ���� ");

	//����
	printf("����Ž��Ʈ����� ��: "); 
	inorder(root);
	printf("\n");
	root = delete_node(root, 8);//����Ʈ����0��		//���������͸� ������� �ʱ����ؼ� ���ϰ��� �ٽ� ������ �־���.
	printf("��尪 8 ���� ��: ");
	inorder(root);
	printf("\n");

	root = delete_node(root, 35);//����Ʈ����0��		
	printf("��尪 35 ���� ��: ");
	inorder(root);
	printf("\n");
	
	root = delete_node(root, 10);//����Ʈ����1��		
	printf("��尪 10 ���� ��: ");
	inorder(root);	
	printf("\n");

	root = delete_node(root, 31);//����Ʈ����2��		
	printf("��尪 31 ���� ��: ");
	inorder(root);
	printf("\n");

	inorder(root);	
	root = delete_node(root, 17);//��Ʈ�� ������.
	printf("��尪 17 ���� ��: ");
	inorder(root);
	printf("\n");

}

