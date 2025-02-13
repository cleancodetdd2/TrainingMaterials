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
	// snprintf(버퍼, 버퍼크기, 포맷 문자열,...)
	snprintf(s->history[s->history_count++], 50,
		"push(%d) - top: %d", data, s->top); // 연산 내역 저장 
}

// 원소 제거 (pop)
int pop(Stack* s) {
	if (s->top == -1) {
		printf("스택 언더플로우가 발생했습니다.\n");
		return -1;		// 에러 코드 반환
	}
	int removed = s->stack[s->top--];		//최상단 원소 제거 및 반환
	snprintf(s->history[s->history_count++], 50,
		"pop() -> %d - top: %d", removed, s->top); // 연산 내역 저장 

	return removed;
}

// 스택의 상태 출력
void show(const Stack* s) {
	printf("----스택 연산 내역 ----\n");
	for (int i = 0; i < s->history_count; i++)
		printf("%s\n", s->history[i]);	// 연산 내역 출력
	printf("-----------------------\n");

	printf("----스택(LIFO 순서)----\n");
	for (int i = 0; i <= s->top; i++)
		printf("%d\n", s->stack[i]);	// 스택 원소 출력
	printf("-----------------------\n");
}

int main()
{
	Stack s;		// 스택 선언 
	initStack(&s);	// 스택 초기화 

	push(&s, 7);		// 7 삽입 <-- top : 0
	push(&s, 5);		// 5 삽입 <-- top : 1
	push(&s, 4);		// 4 삽입 <-- top : 2
	pop(&s);			// 최상단 원소(4) 제거 - top : 1
	push(&s, 6);		// 6 삽입 <-- top : 2
	pop(&s);			// 최상단 원소(6) 제거 - top : 1
	show(&s);

	return 0;
}