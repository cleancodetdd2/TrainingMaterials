#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF	99999999	//무한대 값으로 사용할 큰 수 정의
#define HISTORY_SIZE 100  // 연산 이력 저장할 최대 크기 

// 노드 구조체 정의(연결 리스트 요소)
typedef struct Node {
	int data;		// 저장할 데이터
	struct Node* next;	// 다음 노드를 가리키는 포인터
} Node;

// 스택 구조체 정의
typedef struct Stack {
	Node* top;			// 스택의 최상단 요소 
	char history[HISTORY_SIZE][50];		// 연산 이력 저장 배열 
	int history_index;					// 연산 이력 인덱스 
} Stack;

// 스택 초기화 함수
void initStack(Stack* stack) {
	stack->top = NULL;		// 스택이 비어있는 상태로 초기화 
	stack->history_index = 0;	// 연산 이력 인덱스 초기화 
}

// 데이터를 스택에 삽입
void push(Stack* stack, int data) {
	Node* node = (Node*)malloc(sizeof(Node));	// 새 노드 동적 할당
	if (!node) {	// 메모리 할당 실패 시 오류 메시지 출력
		printf("메모리 할당 실패\n");
		return;
	}

	node->data = data;			// 노드에 데이터 저장
	node->next = stack->top;	// 현재 top을 새로운 노드의 next로 설정
	stack->top = node;			// 새로운 노드를 top으로 변경

	//연산 이력 저장
	if (stack->history_index < HISTORY_SIZE) {
		snprintf(stack->history[stack->history_index], 50, "push(%d)", data);
		stack->history_index++;
	}

}

// 최상단 데이터를 꺼내고 삭제
int pop(Stack* stack) {
	if (!stack->top) {
		printf("스택 언더플로우가 발생했습니다.\n");
		return -INF;
	}

	int data = stack->top->data;		// 최상단 노드의 데이터 저장
	Node* temp = stack->top;			// 최상단 노드 주소 저장
	stack->top = stack->top->next;		// top을 다음 노드로 변경
	free(temp);		// 기존 최상단 노드 메모리 해제 

	// 연산 이력 저장
	if (stack->history_index < HISTORY_SIZE) {
		snprintf(stack->history[stack->history_index], 50, "pop() -> %d", data);
		stack->history_index++;
	}

	return data;	// 삭제된 데이터 반환
}

// 스택 메모리 해제 함수 (모든 노드 삭제)
void freeStack(Stack* stack) {
	while (stack->top) {
		Node* temp = stack->top;		// 현재 top 노드 저장
		stack->top = stack->top->next;	// top을 다음 노드로 이동
		free(temp);		// 기존 top 노드 메모리 해제
	}
}

// 스택 내용 출력 함수
void show(Stack* stack) {
	printf("----스택(LIFO순서)----\n");
	Node* cur = stack->top;		//스택의 최상단부터 탐색
	while (cur) {
		printf("%d\n", cur->data); // 현재 노드 데이터 출력
		cur = cur->next;		   // 다음 노드로 이동 
	}
	printf("-----------------------\n");
}

//연산 이력 출력 함수
void showHistory(Stack* stack) {
	printf("----스택 연산 내역 ----\n");
	for (int i = 0; i < stack->history_index; i++)
		printf("%s\n", stack->history[i]);	// 연산 내역 출력
	printf("-----------------------\n");
}

int main() {
	Stack stack;		    // 스택 구조체 변수 선언
	initStack(&stack);		// 스택 초기화

	push(&stack, 7);		// 7을 스택에 삽입
	push(&stack, 5);		// 5을 스택에 삽입
	push(&stack, 4);		// 4을 스택에 삽입
	pop(&stack);			// 최상단 요소(4) 제거 
	push(&stack, 6);		// 6을 스택에 삽입
	pop(&stack);			// 최상단 요소(6) 제거 

	showHistory(&stack);	// 연산 이력 출력
	show(&stack);			// 현재 스택 상태 출력

	freeStack(&stack);		// 동적 메모리 해제 

	return 0;
}