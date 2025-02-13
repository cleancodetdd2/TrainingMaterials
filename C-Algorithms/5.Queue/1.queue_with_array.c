#include <stdio.h>
#define SIZE 10000		// ť�� �ִ� ũ�� ����
#define INF	99999999	// ����÷ο� �߻� �� ��ȯ�� ū ���� ��

// ť �迭, front, rear ����
int queue[SIZE];
int front = 0;	// ť�� ���� �ε���
int rear = 0;	// ť�� ���� �ε��� 

// ť�� �����͸� �����ϴ� �Լ� (Enqueue)
void push(int data) {
	if (rear >= SIZE) {		//ť�� ���� �� ���
		printf("ť �������ο찡 �߻��߽��ϴ�\n");
		return;
	}
	queue[rear++] = data;		//������ ���� �� rear ���� 
	printf("push(%d) ����� (rear: %d)\n", data, rear);
}

//ť���� ������ �����ϴ� �Լ� (Dequeue)
void pop() {
	if (front == rear) {	// ť�� ����ִ� ���
		printf("ť ����÷ο찡 �߻��߽��ϴ�.\n");
		return;
	}
	int data = queue[front++];	// front�� �����͸� ��ȯ�ϰ� front ����
	printf("pop() ����� -> ��ȯ��: %d (front: %d)\n", data, front);
	return data;
}

// ť ���� ��� �Լ�
void show() {
	printf("----���� ť ����----\n");
	if (front == rear)
		printf("ť�� ��� �ֽ��ϴ�.\n");
	else {
		for (int i = front; i < rear; i++)
			printf("%d ", queue[i]);
		printf("\n");
	}
	printf("-----------------------\n");
}

int main()
{
	printf("ť �ʱ�ȭ �Ϸ�\n\n");

	push(7);	//7 ����
	push(5);	//5 ����
	push(4);	//4 ����
	pop();		//�� ��(7) ����
	push(6);	//6 ����
	pop();		//�� ��(5) ����

	show();

	return 0;
}