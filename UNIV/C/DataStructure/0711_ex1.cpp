//7.10 이진탐색 삽입/탐색 연산
//7.11 이진탐색 삭제 연산
#include<stdio.h>
#include<stdlib.h>

typedef int element; //형 변환 

typedef struct TreeNode { //구조체 정의 
	struct TreeNode *left;
	element data;
	struct TreeNode *right;
}TreeNode;
TreeNode* min_value_node(TreeNode *node);
TreeNode *new_node(element item) { //노드 생성을 위한 메모리 동적 할당
	TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode *insert_node(TreeNode *node, element key) {
	if (node == NULL) return new_node(key); //트리의 첫번째 노드
	if (key < node->data) {//키보다 데이터가 크다면 왼쪽으로
		node->left = insert_node(node->left, key); //함수를 순환호출하여 값을 재 전달하여 좌측에 삽입
	}
	else if (key > node->data) { //기존 데이터보다 입력받은 데이터가 크다면 오른쪽으로 삽입
		node->right = insert_node(node->right, key); //함수를 순환호출하여 값을 재 전달하여 우측에 삽입

	}
	return node;

}
void inorder(TreeNode *root) { //중위순회 
	if (root != NULL) {
		inorder(root->left);
		printf("[%d]-", root->data);
		inorder(root->right);
	}
}
TreeNode *search(TreeNode *node, element key) { //탐색(검색) 부분 
	if (node == NULL) return NULL;
	if (key == node->data)return node;
	else if (key < node->data)
		return search(node->left, key);
	else
		return search(node->right, key);
}
TreeNode *search_while(TreeNode *node, element key) {
	while (node != NULL) { //노드가 null이 아닐경우 반복 
		if (key == node->data)return node; //노드와 찾고자 하는 데이터가 일치할 경우 바로 노드 리턴 
		else if (key < node->data) //데이터보다 노드가 클 경우 노드의 좌측 탐색 
			node = node->left;
		else //데이터보다 노드가 작을경우 노드의 우측 탐색 
			node = node->right;
	}
	return NULL;
}

TreeNode* delete_node(TreeNode *root, element key) {//->이 부분 이해안가면 사진참고.
	//만약에 루트가 없거나 루트값이 널이 되면 리턴.
	if (root == NULL) return root;
	if (key < root->data)		//루트>키-->루트의 왼쪽으로 루트가 이동.
		root->left = delete_node(root->left, key);
	else if (key > root->data)	//루트<키-->루트의 오른쪽으로 루트가 이동.
		root->right = delete_node(root->right, key);
	else{
		//삭제코드가 돌아가는 부분.. 키==루트
		//key ==root->data, 삭제할 노드를 찾음
		//case1, case2의 경우
		if (root->left == NULL) {		//8은 키값보다 크지도 작지도 않음.==삭제할 키를 찾았다!-->이놈의 자식이 한개인지 두개인지 찾아야함.그래서 먼저 왼쪽이 널인지 먼저 확인
			TreeNode *temp = root->right;
			free(root);	//마지막 8이라는 루트를 날려버려. 왜냐하면 9의 왼쪽 노드에 주소가 있기 때문에.
			return temp;		//이 리턴값은 else를 수행하기 전에 62번째에 호출된 delete_node(left)를 호출했던 이곳에 갖다줌.
			/*다시말해서 8위의 9노드로 주소를 갖다줘야하는데 사람이 이해하기엔 돌려주면 끝이지만, 컴퓨터에서는 9를 마지막으로 호출했던 곳으로 가야 리턴됨.
			8입장에서는 자기가 왼쪽에 있는지 오른쪽에 있는지 모르니까 부모노드에게 가서 물어봄. 그래서 자기가 왼쪽 자식인 것을 알게됨. 그래서 자식의 
			위치를 찾는 과정을 부모가 자식을 어떻게 낳았는지 자식이 역추적하는 것임.
			부모와 자식간의 관계를 끊으려면 자식의 노드의 주소를 부모가 다시 가져가면 되는 것임. 이것이 여기선 삭제를 나타냄.*/
		}
		else if (root->right == NULL) {
			TreeNode *temp = root->left;	//먼저 삭제할 노드의 주소를 부모노드에 저장을 하고
			free(root);		//삭제할 노드를 제거
			return temp;	//temp에 저장한 삭제한 노드의 자식노드들을 할머니 노드에 연결.
		}
	//case3인 경우, 서브트리의수가 2개인경우
	
		else {
			TreeNode *temp = min_value_node(root->right);
			root->data = temp->data;
			root->right = delete_node(root->right, temp->data);
		}
	}
	return root;
}

//리턴 타입 바꿈.
TreeNode* min_value_node(TreeNode *node) { //오른쪽 서브트리중 최소값 찾기 
	TreeNode *current = node; //오른쪽으로 탐색할수있게끔 방향을 제어해주는 변수 선언
								// node: 삭제노드의 right 주소값
	
	while (current->left != NULL) { //current가 가리키는 left값이 null이 아닐경우 탐색
		current = current->left;
	}
	return current;
}
int main(void) {
	TreeNode *root = NULL;
	//값 삽입 부분 
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
	

	//탐색 부분 
	printf("\n");
	TreeNode *temp = search(root, 8);
	if (temp == NULL)
		printf("노드값이 트리에 없음");
	else
		printf("노드값이 트리에 있음 ");

	//삭제
	printf("이진탐색트리노드 값: "); 
	inorder(root);
	printf("\n");
	root = delete_node(root, 8);//서브트리가0개		//이중포인터를 사용하지 않기위해서 리턴값을 다시 변수에 넣어줌.
	printf("노드값 8 삭제 후: ");
	inorder(root);
	printf("\n");

	root = delete_node(root, 35);//서브트리가0개		
	printf("노드값 35 삭제 후: ");
	inorder(root);
	printf("\n");
	
	root = delete_node(root, 10);//서브트리가1개		
	printf("노드값 10 삭제 후: ");
	inorder(root);	
	printf("\n");

	root = delete_node(root, 31);//서브트리가2개		
	printf("노드값 31 삭제 후: ");
	inorder(root);
	printf("\n");

	inorder(root);	
	root = delete_node(root, 17);//루트를 제거함.
	printf("노드값 17 삭제 후: ");
	inorder(root);
	printf("\n");

}

