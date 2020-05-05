#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode{
	struct TreeNode *left;
	element data;
	struct TreeNode *right;
}TreeNode;

TreeNode* new_node(element item) {

	//키값을 받아서 여기서 동적할당을 받는다.
	//동적 할당 후 키를 저장
	TreeNode *temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->data = item;
	temp->left = temp->right = NULL;		//초기에는 양쪽 다 아무것도 없다.
	return temp;	//주소를 반환하여...insert_node함수에서 newnode(key)로 주소가 들어감.
}

TreeNode * insert_node(TreeNode *node, element key) {
	
	//새책 코드
	if (node == NULL) return new_node(key);	//temp의 주소가 여기에 들어옴..트리의 첫번째 노드.일때는 여기에 있는 키값을 그냥 리턴하라.
	if (key < node->data) {//현재 노드가 가리키고 있는 데이터는 17이고 새로 복사된 키값은 6이다. 그런데 키값이 노드->데이터보다 작으므로 아래 수행
		node->left = insert_node(node->left, key);// 여기에 new_node값이 들어감. 왜냐하면 17의 왼쪽 노드에는 null값이 들어가 있기 때문이다.
	}
	else if (key > node->data) {// 새로들어온 키값 10이 현재 노드의 데이터(6) 보다 크므로.. 오른쪽 노드로 들어감
		node->right = insert_node(node->right, key);
	}
	//여기서 크거나 작은 값은 왼쪽이나 오른쪽에 가져다 붙이지만 같은 값이라면 리턴.
	return node;
}

TreeNode *search(TreeNode *node, element key) {
	if (node == NULL) return NULL;
	if (key == node->data) return node;	//주소반환
	else if (key < node->data) {
		return search(node->left, key);		//키값이 데이터보다 더 작을때 또 그아래 서브 노드들이 비교될 수 있으니 serach함수 부른것
	}
	else
		return search(node->right, key);
}

TreeNode *search_while(TreeNode *node, element key) {
	while (node !=NULL) {	//node가 null이면 비교를 못할테니까 입구에서 걸러줌.
		if (key == node->data) return node;
		else if (key < node->data)
			node = node->left;
		else
			node = node->right;
	}
	return NULL;	//return node; 같은 표현. 그러나 상수로 전달하는 것이 깔끔하므로, null..
}

element min_value_node(TreeNode *node) {
	TreeNode *current = node->right;
	while (current->left != NULL)
		current = current->left;		//현재 노드의 왼쪽 서브트리에 값이 없다면 그게 마지막 이므로 리턴.
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
	
	//삭제할 때 노드값 선택 = 오른쪽 서브트리에서 가장 작은 값을 찾음. 왜냐하면 중간에 값을 지울때 트리가 흔들리면 안되니까.
	element data = min_value_node(root);
	printf("오른쪽 서브트리의 최솟값 = %d\n", data);//25


	//TreeNode *tmp = search(root, 13);			// element 값을 바꿔보면 아래 두 문장 나옴
	TreeNode *tmp = search_while(root, 5);			

	if (tmp == NULL)
		printf("노드값이 트리에 없습니다.\n");
	else
		printf("노드값이 트리에 있습니다.\n");
}