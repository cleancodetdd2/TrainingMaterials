#include "myHeader.h"
#include <string.h>

Node* head = NULL;		//리스트의 첫번째 노드를 가리키는 포인터 

void clearBuffer() {
	int ch;
	while ((ch = getchar()) != "\n" && ch != EOF);  //개행문자를 만날때까지 문자제거
}

/*
	모든 노드 삭제
	- 모든 노드를 동적 메모리에서 해제하여 리스트를 초기화 
*/
void clearList() {
	while (head) {
		Node* temp = head;		// 삭제할 노드 저장 
		head = head->next;		// head를 다음 노드로 이동
		free(temp);				// 메모리 해제
	}
}

/*
	리스트 앞에 노드 앞에
	- 새로운 노드를 리스트의 맨 앞(head)에 추가 
*/
void insertFront(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node)); // 새 노드 동적 할당
	if (!newNode) return;	// 메모리 할당 실패시 종료 

	newNode->value = data;		// 노드에 데이터 저장
	newNode->next = head;		// 새 노드의 다음을 현재의 head로 설정

	head = newNode;				// 새 노드를 리스트의 새로운 head로 설정
}

/*
	리스트 출력
	 - head부터 시작하여 리스트를 순차적으로 출력	
*/
void traverseList() {
	Node* cur = head;
	if (!cur) {
		printf("리스트가 비어 있습니다.\n");
		return;
	}

	printf("리스트 : ");
	while (cur) {
		printf("%d -> ", cur->value);
		cur = cur->next;
	}
	printf("NULL\n");
}
