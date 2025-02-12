#include "myHeader.h"
#include <string.h>

Node* head = NULL;		//����Ʈ�� ù��° ��带 ����Ű�� ������ 

void clearBuffer() {
	int ch;
	while ((ch = getchar()) != "\n" && ch != EOF);  //���๮�ڸ� ���������� ��������
}

/*
	��� ��� ����
	- ��� ��带 ���� �޸𸮿��� �����Ͽ� ����Ʈ�� �ʱ�ȭ 
*/
void clearList() {
	while (head) {
		Node* temp = head;		// ������ ��� ���� 
		head = head->next;		// head�� ���� ���� �̵�
		free(temp);				// �޸� ����
	}
}

/*
	����Ʈ �տ� ��� �տ�
	- ���ο� ��带 ����Ʈ�� �� ��(head)�� �߰� 
*/
void insertFront(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node)); // �� ��� ���� �Ҵ�
	if (!newNode) return;	// �޸� �Ҵ� ���н� ���� 

	newNode->value = data;		// ��忡 ������ ����
	newNode->next = head;		// �� ����� ������ ������ head�� ����

	head = newNode;				// �� ��带 ����Ʈ�� ���ο� head�� ����
}

/*
	����Ʈ ���
	 - head���� �����Ͽ� ����Ʈ�� ���������� ���	
*/
void traverseList() {
	Node* cur = head;
	if (!cur) {
		printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
		return;
	}

	printf("����Ʈ : ");
	while (cur) {
		printf("%d -> ", cur->value);
		cur = cur->next;
	}
	printf("NULL\n");
}

/*
	���ο� ��带 ����Ʈ�� �� �ڿ� �߰�
*/
void insertRear(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));	// �� ��� ���� �Ҵ�
	if (!newNode) return;		// �޸� �Ҵ� ���� �� ����

	newNode->value = data;	// ��忡 ������ ����
	newNode->next = NULL;	// �� ���� ���������Ƿ� ���� ���� ����

	if (!head) {	// ����Ʈ�� ����ִ� ���
		head = newNode;		// �� ��带 head�� ����
		return;
	}

	Node* cur = head;
	while (cur->next) {	// ������ ���� �̵�
		cur = cur->next;
	}
	cur->next = newNode;	// ������ ����� next�� �� ���� ����
}

/*
	1���� �����ϴ� ��ġ(pos)�� �Է¹޾� �ش� ��ġ�� �� ��带 ����
*/
void insertAt(int data, int pos) {
	if (pos < 1) return;	// ��ġ�� 1���� ������ ���� �Ұ�

	Node* newNode = (Node*)malloc(sizeof(Node));	// �� ��� ���� �Ҵ�
	if (!newNode) return;		// �޸� �Ҵ� ���� �� ����

	newNode->value = data;	// ��忡 ������ ����
	newNode->next = NULL;	// �� ���� ���������Ƿ� ���� ���� ����

	if (pos == 1) {	// ù ��° ��ġ�� �����ϴ� ���
		newNode->next = head;	// �� ����� ������ ���� head�� ����
		head = newNode;			// head�� �� ���� ����
		return;
	}

	Node* cur = head;
	for (int i = 1; cur != NULL && i < pos - 1; i++)	// ���� ��ġ �������� �̵� 
		cur = cur->next;

	if (!cur) {		// �߸��� ��ġ�� ���(����Ʈ ũ�� �ʰ�)
		free(newNode);	// �޸� ���� ����
		return;
	}

	newNode->next = cur->next;	// �� ����� ������ ���� ���� ����
	cur->next = newNode;	// ���� ����� ������ �� ���� ����
}

/*
	����Ʈ ù ��° ��带 �����ϰ�, ���� ��带 ���ο� head�� ����
	���� ���� �� 1, ���� �� 0 ��ȯ 
*/
int removeFront() {

}