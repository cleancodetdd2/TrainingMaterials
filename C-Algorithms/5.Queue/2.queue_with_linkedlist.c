#include <stdio.h>
#include <stdlib.h>

#define INF 99999999	//���� �߻� �� ��ȯ�� ū �� (�ſ� ū ����)

//��� ����ü (�� ��Ҹ� �����ϴ� ����ü)
typedef struct Node {
	int data;			// ������ ����
	struct Node* next;	// ���� ��带 ����Ű�� ������ 
} Node;

//ť ����ü (ť ��ü�� ����)
typedef struct {
	Node* front;	// ť�� ù��° ��� (�ⱸ, �����͸� ������ ��)
	Node* rear;		// ť�� ������ ��� (�Ա�, �����͸� �ִ� ��)
	int count;		// ť�� ��� �ִ� ���� 
} Queue;

//ť �ʱ�ȭ �Լ� (ó�� ����� �� ����)
void initQueue(Queue* queue) {
	queue->front = queue->rear = NULL;	// front�� rear�� NULL�� �ʱ�ȭ
	queue->count = 0;					// ť�� ũ�⸦ 0���� ����
}

//ť�� ����ִ��� Ȯ���ϴ� �Լ�
int isEmpty(Queue* queue) {
	return queue->count == 0;	// ���� ������ 0�̸� ��� ����
}

//ť�� ������ �߰� (Enqueue)
void push(Queue* queue, int data)
{
	// �� ��� ���� �Ҵ�(�޸� ���� Ȯ��)
	Node* node = (Node*)malloc(sizeof(Node));

	// �޸� �Ҵ� ���� üũ
	if (node == NULL) {
		printf("�޸� �Ҵ� ����!\n");	// ���� �޽��� ���
		return;		// �Լ� ����
	}

	node->data = data;		// ��忡 ������ ����
	node->next = NULL;		// �� ��忡 ������ ����̹Ƿ� next�� NULL

	if (isEmpty(queue)) {	// ť�� ��� �ִٸ�	
		queue->front = node;	// front�� �� ��带 ����Ű���� ���� 
	}
	else
		queue->rear->next = node;	// ���� rear�� next�� ����带 ����

	queue->rear = node;	// rear�� �� ���� ������Ʈ 
	queue->count++;		// ť ���� ���� ���� 
}

//ť���� ������ ����(Dequeue)
int pop(Queue* queue) {
	if (isEmpty(queue)) {	// ť�� ��� �ִ� ���
		printf("ť ����÷ο찡 �߻��մϴ�\n");		// ���� �޽��� ���
		return -INF;		// ť�� ��������� ��Ÿ���� �� ��ȯ
	}

	Node* node = queue->front;		// ������ ���(�� �� ���)
	int data = node->data;			// ����� ������ ����

	queue->front = node->next;		// front�� ���� ���� �̵�

	free(node);			// ������ ����� �޸� ����
	queue->count--;		// ť ���� ���� ���� 

	//ť�� ������ ������� rear�� NULL�� �ʱ�ȭ
	if (isEmpty(queue))
		queue->rear = NULL;

	return data;		// ���ŵ� ������ ��ȯ
}

// ť �޸� ���� �Լ� (���α׷� ���� �� ���)
void clearQueue(Queue* queue) {
	while (!isEmpty(queue)) {	// ť�� ������� ������
		pop(queue);				// �ϳ��� ���� 
	}
}

// ť ��� �Լ� (���� ť�� ���� Ȯ��)
void show(Queue* queue) {
	Node* cur = queue->front;	// ù��° ������ Ž��

	printf("----ť�� ����----\n");
	while (cur != NULL) {	// ť�� ������ �ݺ�
		printf("%d\n", cur->data);		// ���� ����� ������ ���
		cur = cur->next;				// ���� ���� �̵�
	}
	printf("-----------------\n");
}

int main()
{
	Queue queue;		// ť����
	initQueue(&queue);	// ť �ʱ�ȭ 

	push(&queue, 7);	// 7 �߰�
	push(&queue, 5);	// 5 �߰�
	push(&queue, 4);	// 4 �߰�

	pop(&queue);		// ù��° ���� ���� (7����)
	push(&queue, 6);	// 6 �߰�
	pop(&queue);		// ù��° ���� ���� (5����)

	show(&queue);	// ���� ť�� ���� ���

	clearQueue(&queue);	// ���α׷� ���� �� �޸� ����
	return 0;	// ���α׷� ���� ����
}