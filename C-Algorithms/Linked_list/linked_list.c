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
	if (!head) return 0;		// ����Ʈ�� ��� ������ ���� �Ұ�

	Node* temp = head;
	head = head->next;		// head�� ���� ���� �̵�
	free(temp);		// ���� ù ��° ��� ����
	return 1;
}

/*
	����Ʈ�� ������ ��带 ã�� ����
	���� ���� �� 1, ���� �� 0 ��ȯ
*/
int removeRear() {
	if (!head) return 0;		// ����Ʈ�� ��� ������ ���� �Ұ�

	if (!head->next) {		// ����Ʈ�� ��尡 �ϳ��� �ִ� ���
		free(head);
		head = NULL;
		return 1;
	}

	Node* cur = head;
	// ���� ���(cur)�� ���� ���(cur->next)�� ������ ��尡 �ƴ� ������ �̵�
	while (cur->next->next) {	// ������ ��� �������� �̵� 
		cur = cur->next;
	}

	free(cur->next);		// ������ ��� ����
	cur->next = NULL;		// ���ο� ������ ��� ����
	return 1;
}

/*
	1���� �����ϴ� ��ġ(pos)�� �Է¹޾� �ش� ��ġ�� ��带 ������
	���� ���� �� 1, ���� �� 0 ��ȯ
*/
int removeAt(int pos) {
	if (!head || pos < 0) return 0;		// ����Ʈ�� ��� �ְų� �߸��� ��ġ�� ���

	if (pos == 1) return removeFront();		// ù ��° ��� ���� ó�� 

	Node* cur = head;
	for (int i = 1; cur != NULL && i < pos - 1; i++)  // ������ ��ġ �������� �̵�
		cur = cur->next;

	if (!cur || !cur->next) return 0;	// ������ ��尡 ���� ���

	Node* temp = cur->next;		// ������ ��� ����
	cur->next = temp->next;		// ���� ��尡 ���� ��带 ����Ű�� ���� ����
	free(temp);		// ������ ����� �޸� ����
	return 1;
}