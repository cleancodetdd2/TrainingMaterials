#include <stdio.h>
#include <stdlib.h>

// ���� Ʈ���� ���
typedef struct {
	int data;					// ��忡 ����� ������ 
	struct Node* leftChild;		// ���� �ڽ� ��带 ����Ű�� ������
	struct Node* rightChild;	// ������ �ڽ� ��带 ����Ű�� ������
} Node;

// ���ο� ��带 �����ϰ� �ʱ�ȭ�ϴ� �Լ�
Node* initNode(int data, Node* leftChild, Node* rightChild) {
	Node* node = (Node*)malloc(sizeof(Node));	// (Node ũ�⸸ŭ)���� �޸� �Ҵ�
	node->data = data;		// ����� ������ ����
	node->leftChild = leftChild;		// ���� �ڽ� ��� ����
	node->rightChild = rightChild;		// ������ �ڽ� ��� ����
	return node;		// ������ ��� ��ȯ
}

// ���� ��ȸ : ��Ʈ -> ���� ����Ʈ�� -> ������ ����Ʈ��
void preorder(Node* root) {
	if (root) {		// ���� ��尡 NULL�� �ƴ� ���
		printf("%d ", root->data);		// ���� ����� ������ ��� 
		preorder(root->leftChild);		// ���� �ڽ� ��� �湮 (��� ȣ��)
		preorder(root->rightChild);		// ������ �ڽ� ��� �湮 (��� ȣ��)
	}
}

// ���� ��ȸ : ���� ����Ʈ�� -> ��Ʈ -> ������ ����Ʈ��
void inorder(Node* root) {
	if (root) {		// ���� ��尡 NULL�� �ƴ� ���
		inorder(root->leftChild);		// ���� �ڽ� ��� �湮 (��� ȣ��)
		printf("%d ", root->data);		// ���� ����� ������ ��� 
		inorder(root->rightChild);		// ������ �ڽ� ��� �湮 (��� ȣ��)
	}
}

int main()
{
	// Ʈ�� ��� ���� (�����Ͱ��� �ڽ� ��� ����)
	Node* n7 = initNode(50, NULL, NULL);		// ���� ��� (�ڽ� ����)
	Node* n6 = initNode(37, NULL, NULL);		// ���� ��� (�ڽ� ����)
	Node* n5 = initNode(23, NULL, NULL);		// ���� ��� (�ڽ� ����)
	Node* n4 = initNode(5, NULL, NULL);		// ���� ��� (�ڽ� ����)

	Node* n3 = initNode(48, n6, n7);		// ���� : ��� 6,  ������: ��� 7
	Node* n2 = initNode(17, n4, n5);		// ���� : ��� 4,  ������: ��� 5

	Node* n1 = initNode(30, n2, n3);		// ��Ʈ ��� (���� : ��� 2,  ������: ��� 3)

	// Ʈ���� ��ȸ ��� ���
	printf("���� ��ȸ : ");
	preorder(n1);		// ���� ��ȸ ����
	printf("\n");

	printf("���� ��ȸ : ");
	inorder(n1);		// ���� ��ȸ ����
	printf("\n");

	return 0;
}