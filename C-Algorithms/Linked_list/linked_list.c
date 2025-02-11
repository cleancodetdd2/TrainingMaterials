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
