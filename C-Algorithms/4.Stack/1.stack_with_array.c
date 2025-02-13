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
	// snprintf(����, ����ũ��, ���� ���ڿ�,...)
	snprintf(s->history[s->history_count++], 50,
		"push(%d) - top: %d", data, s->top); // ���� ���� ���� 
}

// ���� ���� (pop)
int pop(Stack* s) {
	if (s->top == -1) {
		printf("���� ����÷ο찡 �߻��߽��ϴ�.\n");
		return -1;		// ���� �ڵ� ��ȯ
	}
	int removed = s->stack[s->top--];		//�ֻ�� ���� ���� �� ��ȯ
	snprintf(s->history[s->history_count++], 50,
		"pop() -> %d - top: %d", removed, s->top); // ���� ���� ���� 

	return removed;
}

// ������ ���� ���
void show(const Stack* s) {
	printf("----���� ���� ���� ----\n");
	for (int i = 0; i < s->history_count; i++)
		printf("%s\n", s->history[i]);	// ���� ���� ���
	printf("-----------------------\n");

	printf("----����(LIFO ����)----\n");
	for (int i = 0; i <= s->top; i++)
		printf("%d\n", s->stack[i]);	// ���� ���� ���
	printf("-----------------------\n");
}

int main()
{
	Stack s;		// ���� ���� 
	initStack(&s);	// ���� �ʱ�ȭ 

	push(&s, 7);		// 7 ���� <-- top : 0
	push(&s, 5);		// 5 ���� <-- top : 1
	push(&s, 4);		// 4 ���� <-- top : 2
	pop(&s);			// �ֻ�� ����(4) ���� - top : 1
	push(&s, 6);		// 6 ���� <-- top : 2
	pop(&s);			// �ֻ�� ����(6) ���� - top : 1
	show(&s);

	return 0;
}