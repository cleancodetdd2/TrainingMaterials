#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10000			// ������ �ִ� ũ��
#define HISTORY_SIZE 10000	// ���� ���� ũ�� 

// ���� ����ü ����
typedef struct {
	int stack[SIZE];		// �迭�� �̿��� ����
	int top;	// ������ �ֻ�� �ε���
	char history[HISTORY_SIZE][50];
	int history_count;	// ���� ���� ���� 
}Stack;

// ���� �ʱ�ȭ
void initStack(Stack* s) {
	s->top = -1;	// ������ ��������� ��Ÿ���� �ʱⰪ 
	s->history_count = 0;		// ���� ���� �ʱ�ȭ 
}

// ���� ���� (push)
void push(Stack* s, int data) {
	if (s->top == SIZE - 1) {	// ���� �����÷ο� ���� 
		printf("���� �����÷ο찡 �߻��߽��ϴ�.\n");
		return;
	}
	s->stack[++s->top] = data;		// ���� �ֻ�ܿ� ������ �߰� 
	snprintf(s->history[s->history_count++], 50,
		"push(%d) - top: %d", data, s->top); // ���� ���� ���� 
}

int main()
{
	Stack s;		// ���� ���� 
	initStack(&s);	// ���� �ʱ�ȭ 


	return 0;
}