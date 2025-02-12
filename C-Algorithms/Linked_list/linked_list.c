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

/*
	새로운 노드를 리스트의 맨 뒤에 추가
*/
void insertRear(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));	// 새 노드 동적 할당
	if (!newNode) return;		// 메모리 할당 실패 시 종료

	newNode->value = data;	// 노드에 데이터 저장
	newNode->next = NULL;	// 새 노드는 마지막으므로 다음 노드는 없음

	if (!head) {	// 리스트가 비어있는 경우
		head = newNode;		// 새 노드를 head로 설정
		return;
	}

	Node* cur = head;
	while (cur->next) {	// 마지막 노드로 이동
		cur = cur->next;
	}
	cur->next = newNode;	// 마지막 노드의 next를 새 노드로 연결
}

/*
	1부터 시작하는 위치(pos)를 입력받아 해당 위치에 새 노드를 삽입
*/
void insertAt(int data, int pos) {
	if (pos < 1) return;	// 위치가 1보다 작으면 삽입 불가

	Node* newNode = (Node*)malloc(sizeof(Node));	// 새 노드 동적 할당
	if (!newNode) return;		// 메모리 할당 실패 시 종료

	newNode->value = data;	// 노드에 데이터 저장
	newNode->next = NULL;	// 새 노드는 마지막으므로 다음 노드는 없음

	if (pos == 1) {	// 첫 번째 위치에 삽입하는 경우
		newNode->next = head;	// 새 노드의 다음을 기존 head로 설정
		head = newNode;			// head를 새 노드로 변경
		return;
	}

	Node* cur = head;
	for (int i = 1; cur != NULL && i < pos - 1; i++)	// 삽입 위치 이전까지 이동 
		cur = cur->next;

	if (!cur) {		// 잘못된 위치인 경우(리스트 크기 초과)
		free(newNode);	// 메모리 누수 방지
		return;
	}

	newNode->next = cur->next;	// 새 노드의 다음을 기존 노드로 연결
	cur->next = newNode;	// 이전 노드의 다음을 새 노드로 연결
}

/*
	리스트 첫 번째 노드를 삭제하고, 다음 노드를 새로운 head로 설정
	삭제 성공 시 1, 실패 시 0 반환 
*/
int removeFront() {
	if (!head) return 0;		// 리스트가 비어 있으면 삭제 불가

	Node* temp = head;
	head = head->next;		// head를 다음 노드로 이동
	free(temp);		// 기존 첫 번째 노드 삭제
	return 1;
}

/*
	리스트의 마지막 노드를 찾아 삭제
	삭제 성공 시 1, 실패 시 0 반환
*/
int removeRear() {
	if (!head) return 0;		// 리스트가 비어 있으면 삭제 불가

	if (!head->next) {		// 리스트에 노드가 하나만 있는 경우
		free(head);
		head = NULL;
		return 1;
	}

	Node* cur = head;
	// 현재 노드(cur)의 다음 노드(cur->next)가 마지막 노드가 아닐 때까지 이동
	while (cur->next->next) {	// 마지막 노드 이전까지 이동 
		cur = cur->next;
	}

	free(cur->next);		// 마지막 노드 삭제
	cur->next = NULL;		// 새로운 마지막 노드 설정
	return 1;
}

/*
	1부터 시작하는 위치(pos)를 입력받아 해당 위치의 노드를 삭제함
	삭제 성공 시 1, 실패 시 0 반환
*/
int removeAt(int pos) {
	if (!head || pos < 0) return 0;		// 리스트가 비어 있거나 잘못된 위치인 경우

	if (pos == 1) return removeFront();		// 첫 번째 노드 삭제 처리 

	Node* cur = head;
	for (int i = 1; cur != NULL && i < pos - 1; i++)  // 삭제할 위치 이전까지 이동
		cur = cur->next;

	if (!cur || !cur->next) return 0;	// 삭제할 노드가 없는 경우

	Node* temp = cur->next;		// 삭제할 노드 저장
	cur->next = temp->next;		// 이전 노드가 다음 노드를 가리키게 연결 변경
	free(temp);		// 삭제된 노드의 메모리 해제
	return 1;
}