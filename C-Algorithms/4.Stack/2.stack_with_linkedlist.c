#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF	99999999	//���Ѵ� ������ ����� ū �� ����
#define HISTORY_SIZE 100  // ���� �̷� ������ �ִ� ũ�� 

// ��� ����ü ����(���� ����Ʈ ���)
typedef struct Node {
	int data;		// ������ ������
	struct Node* next;	// ���� ��带 ����Ű�� ������
} Node;

// ���� ����ü ����
typedef struct Stack {
	Node* top;			// ������ �ֻ�� ��� 
	char history[HISTORY_SIZE][50];		// ���� �̷� ���� �迭 
	int history_index;					// ���� �̷� �ε��� 
} Stack;

// ���� �ʱ�ȭ �Լ�
void initStack(Stack* stack) {
	stack->top = NULL;		// ������ ����ִ� ���·� �ʱ�ȭ 
	stack->history_index = 0;	// ���� �̷� �ε��� �ʱ�ȭ 
}

// �����͸� ���ÿ� ����
void push(Stack* stack, int data) {
	Node* node = (Node*)malloc(sizeof(Node));	// �� ��� ���� �Ҵ�
	if (!node) {	// �޸� �Ҵ� ���� �� ���� �޽��� ���
		printf("�޸� �Ҵ� ����\n");
		return;
	}

	node->data = data;			// ��忡 ������ ����
	node->next = stack->top;	// ���� top�� ���ο� ����� next�� ����
	stack->top = node;			// ���ο� ��带 top���� ����

	//���� �̷� ����
	if (stack->history_index < HISTORY_SIZE) {
		snprintf(stack->history[stack->history_index], 50, "push(%d)", data);
		stack->history_index++;
	}

}

// �ֻ�� �����͸� ������ ����
int pop(Stack* stack) {
	if (!stack->top) {
		printf("���� ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;
	}

	int data = stack->top->data;		// �ֻ�� ����� ������ ����
	Node* temp = stack->top;			// �ֻ�� ��� �ּ� ����
	stack->top = stack->top->next;		// top�� ���� ���� ����
	free(temp);		// ���� �ֻ�� ��� �޸� ���� 

	// ���� �̷� ����
	if (stack->history_index < HISTORY_SIZE) {
		snprintf(stack->history[stack->history_index], 50, "pop() -> %d", data);
		stack->history_index++;
	}

	return data;	// ������ ������ ��ȯ
}

// ���� �޸� ���� �Լ� (��� ��� ����)
void freeStack(Stack* stack) {
	while (stack->top) {
		Node* temp = stack->top;		// ���� top ��� ����
		stack->top = stack->top->next;	// top�� ���� ���� �̵�
		free(temp);		// ���� top ��� �޸� ����
	}
}

// ���� ���� ��� �Լ�
void show(Stack* stack) {
	printf("----����(LIFO����)----\n");
	Node* cur = stack->top;		//������ �ֻ�ܺ��� Ž��
	while (cur) {
		printf("%d\n", cur->data); // ���� ��� ������ ���
		cur = cur->next;		   // ���� ���� �̵� 
	}
	printf("-----------------------\n");
}

//���� �̷� ��� �Լ�
void showHistory(Stack* stack) {
	printf("----���� ���� ���� ----\n");
	for (int i = 0; i < stack->history_index; i++)
		printf("%s\n", stack->history[i]);	// ���� ���� ���
	printf("-----------------------\n");
}

int main() {
	Stack stack;		    // ���� ����ü ���� ����
	initStack(&stack);		// ���� �ʱ�ȭ

	push(&stack, 7);		// 7�� ���ÿ� ����
	push(&stack, 5);		// 5�� ���ÿ� ����
	push(&stack, 4);		// 4�� ���ÿ� ����
	pop(&stack);			// �ֻ�� ���(4) ���� 
	push(&stack, 6);		// 6�� ���ÿ� ����
	pop(&stack);			// �ֻ�� ���(6) ���� 

	showHistory(&stack);	// ���� �̷� ���
	show(&stack);			// ���� ���� ���� ���

	freeStack(&stack);		// ���� �޸� ���� 

	return 0;
}