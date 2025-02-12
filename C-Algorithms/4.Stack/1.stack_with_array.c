#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10000			// 스택의 최대 크기
#define HISTORY_SIZE 10000	// 내역 저장 크기 

// 스택 구조체 정의
typedef struct {
	int stack[SIZE];		// 배열을 이용한 스택
	int top;	// 스택의 최상단 인덱스
	char history[HISTORY_SIZE][50];
	int history_count;	// 연산 내역 개수 
}Stack;

// 스택 초기화
void initStack(Stack* s) {
	s->top = -1;	// 스택이 비어있음을 나타내는 초기값 
	s->history_count = 0;		// 연산 내역 초기화 
}

// 원소 삽입 (push)
void push(Stack* s, int data) {
	if (s->top == SIZE - 1) {	// 스택 오버플로우 방지 
		printf("스택 오버플로우가 발생했습니다.\n");
		return;
	}
	s->stack[++s->top] = data;		// 스택 최상단에 데이터 추가 
	snprintf(s->history[s->history_count++], 50,
		"push(%d) - top: %d", data, s->top); // 연산 내역 저장 
}

int main()
{
	Stack s;		// 스택 선언 
	initStack(&s);	// 스택 초기화 


	return 0;
}