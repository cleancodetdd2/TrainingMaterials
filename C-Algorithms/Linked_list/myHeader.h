#pragma once

#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
	int value;			// 노드의 값
	struct Node* next;	// 다음 노드를 가리키는 포인터 
} Node;

// 전역 변수 선언
extern Node* head;		// 리스트의 첫번째 노드를 가리키는 포인터 

// 연결 리스트 함수 선언
void insertFront(int data);			// 앞에 노드 삽임 
void insertRear(int data);			// 뒤에 노드 삽임
void insertAt(int data, int pos);	// 특정 위치에 노드 삽임
void traverseList();				// 리스트 출력 

void removeFront();					// 첫번째 노드 삭제 
void removeRear();					// 마지막 노드 삭제 
void removeAt(int pos);				// 특정 위치의 노드 삭제
void removeByValue(int value);		// 특정 값의 노드 삭제 
void getNodeCount();				// 노드 개수 반환 
Node* search(int value);			// 특정 값 검색 
void clearList();					// 모든 노드 삭제 

// 유틸리티 
void clearBuffer();					// 입력 버퍼 비우기
void removeNewLine();				// 줄바꿈 문자 제거 




