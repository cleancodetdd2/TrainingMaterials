#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE	9		// 배열 크기

// 구조체 정의 (이진 트리 노드)
typedef struct treeNode {
	int value;	//노드의 값
	struct treeNode* left;		// 왼쪽 자식 노드
	struct treeNode* right;		// 오른쪽 자식 노드
} treeNode;

// 함수 원형 선언
treeNode* setBinTree(int* arr, int parentIdx, int maxSize);
void displayTreeInorder(treeNode* t);
void displayTreePreorder(treeNode* t);
void displayTreePostorder(treeNode* t);
void memoryFree(treeNode* t);


int main()
{
	//초기 데이터 배열 (완전 이진 트리로 변환할 배열)
	int arr[ARR_SIZE] = { 6, 4, 8, 2, 5, 7, 9, 1, 3 };
	treeNode* root = NULL;		//루트 노드 초기화

	//배열을 기반으로 완전 이진 트리 생성
	root = setBinTree(arr, 0, ARR_SIZE);

	// 트리 순회 출력
	printf("중위 순회 (Inorder) : ");
	displayTreeInorder(root);

	// 트리 전위 출력
	printf("\n전위 순회 (Preorder) : ");
	displayTreePreorder(root);

	// 트리 순회 출력
	printf("\n후위 순회 (Postorder) : ");
	displayTreePostorder(root);

	// 메모리 해제
	printf("\n\n동적으로 할당된 메모리 제거\n");
	memoryFree(root);

	return 0;
}

treeNode* setBinTree(int* arr, int parentIdx, int maxSize) {
	if (parentIdx >= maxSize)		// 배열 범위를 벗어나면 NULL 반환
		return NULL;

	// 새로운 노드 동적 할당
	treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
	if (!newNode) {
		fprintf(stderr, "메모리 할당 실패\n");
		exit(EXIT_FAILURE);		// 프로그램 강제 종료
	}

	// 노드 초기화 
	newNode->value = arr[parentIdx];
	newNode->left = NULL;
	newNode->right = NULL;

	// 왼쪽 자식 설정 (왼쪽 자식 노드의 인덱스 계산)
	int leftIdx = 2 * parentIdx + 1;
	if (leftIdx < maxSize)		// 유효한 인덱스인지 확인
		newNode->left = setBinTree(arr, leftIdx, maxSize);	// 왼쪽 자식 재귀적으로 설정

	// 오른쪽 자식 설정 (오른쪽 자식 노드의 인덱스 계산)
	int rightIdx = 2 * parentIdx + 2;
	if (rightIdx < maxSize)
		newNode->right = setBinTree(arr, rightIdx, maxSize); // 오른쪽 자식 재귀적으로 설정

	return newNode;
}

//중위순위
void displayTreeInorder(treeNode* t) {
	if (t == NULL) return;		// NULL이면 재귀 종료

	displayTreeInorder(t->left);		// 왼쪽 서브트리 방문
	printf("%d ", t->value);			// 현재 노드 출력
	displayTreeInorder(t->right);		// 오른쪽 서브트리 방문 
}

//전위 순회
void displayTreePreorder(treeNode* t) {
	if (t == NULL) return;		// NULL이면 재귀 종료

	printf("%d ", t->value);			// 현재 노드 출력
	displayTreePreorder(t->left);		// 왼쪽 서브트리 방문
	displayTreePreorder(t->right);		// 오른쪽 서브트리 방문 
}

//후위 순회
void displayTreePostorder(treeNode* t) {
	if (t == NULL) return;		// NULL이면 재귀 종료

	displayTreePostorder(t->left);		// 왼쪽 서브트리 방문
	displayTreePostorder(t->right);		// 오른쪽 서브트리 방문 
	printf("%d ", t->value);			// 현재 노드 출력
}


// 트리 메모리 해제 
void memoryFree(treeNode* t) {
	if (t == NULL) return;

	// 왼쪽 및 오른쪽 서브트리 메모리 해제
	memoryFree(t->left);
	memoryFree(t->right);

	// 현재 노드 메모리 해제
	printf("%d 제거\n", t->value);
	free(t);
}