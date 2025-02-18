#include <stdio.h>
#include <stdlib.h>

// 이진 트리의 노드
typedef struct {
	int data;					// 노드에 저장될 데이터 
	struct Node* leftChild;		// 왼쪽 자식 노드를 가리키는 포인터
	struct Node* rightChild;	// 오른쪽 자식 노드를 가리키는 포인터
} Node;

// 새로운 노드를 생성하고 초기화하는 함수
Node* initNode(int data, Node* leftChild, Node* rightChild) {
	Node* node = (Node*)malloc(sizeof(Node));	// (Node 크기만큼)동적 메모리 할당
	node->data = data;		// 노드의 데이터 설정
	node->leftChild = leftChild;		// 왼쪽 자식 노드 설정
	node->rightChild = rightChild;		// 오른쪽 자식 노드 설정
	return node;		// 생성된 노드 반환
}

// 전위 순회 : 루트 -> 왼쪽 서브트리 -> 오른쪽 서브트리
void preorder(Node* root) {
	if (root) {		// 현재 노드가 NULL이 아닐 경우
		printf("%d ", root->data);		// 현재 노드의 데이터 출력 
		preorder(root->leftChild);		// 왼쪽 자식 노드 방문 (재귀 호출)
		preorder(root->rightChild);		// 오른쪽 자식 노드 방문 (재귀 호출)
	}
}

// 중위 순회 : 왼쪽 서브트리 -> 루트 -> 오른쪽 서브트리
void inorder(Node* root) {
	if (root) {		// 현재 노드가 NULL이 아닐 경우
		inorder(root->leftChild);		// 왼쪽 자식 노드 방문 (재귀 호출)
		printf("%d ", root->data);		// 현재 노드의 데이터 출력 
		inorder(root->rightChild);		// 오른쪽 자식 노드 방문 (재귀 호출)
	}
}

int main()
{
	// 트리 노드 생성 (데이터값과 자식 노드 연결)
	Node* n7 = initNode(50, NULL, NULL);		// 리프 노드 (자식 없음)
	Node* n6 = initNode(37, NULL, NULL);		// 리프 노드 (자식 없음)
	Node* n5 = initNode(23, NULL, NULL);		// 리프 노드 (자식 없음)
	Node* n4 = initNode(5, NULL, NULL);		// 리프 노드 (자식 없음)

	Node* n3 = initNode(48, n6, n7);		// 왼쪽 : 노드 6,  오른쪽: 노드 7
	Node* n2 = initNode(17, n4, n5);		// 왼쪽 : 노드 4,  오른쪽: 노드 5

	Node* n1 = initNode(30, n2, n3);		// 루트 노드 (왼쪽 : 노드 2,  오른쪽: 노드 3)

	// 트리의 순회 결과 출력
	printf("전위 순회 : ");
	preorder(n1);		// 전위 순회 실행
	printf("\n");

	printf("중위 순회 : ");
	inorder(n1);		// 중위 순회 실행
	printf("\n");

	return 0;
}