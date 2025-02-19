#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE	9		// �迭 ũ��

// ����ü ���� (���� Ʈ�� ���)
typedef struct treeNode {
	int value;	//����� ��
	struct treeNode* left;		// ���� �ڽ� ���
	struct treeNode* right;		// ������ �ڽ� ���
} treeNode;

// �Լ� ���� ����
treeNode* setBinTree(int* arr, int parentIdx, int maxSize);
void displayTreeInorder(treeNode* t);
void displayTreePreorder(treeNode* t);
void displayTreePostorder(treeNode* t);
void memoryFree(treeNode* t);


int main()
{
	//�ʱ� ������ �迭 (���� ���� Ʈ���� ��ȯ�� �迭)
	int arr[ARR_SIZE] = { 6, 4, 8, 2, 5, 7, 9, 1, 3 };
	treeNode* root = NULL;		//��Ʈ ��� �ʱ�ȭ

	//�迭�� ������� ���� ���� Ʈ�� ����
	root = setBinTree(arr, 0, ARR_SIZE);

	// Ʈ�� ��ȸ ���
	printf("���� ��ȸ (Inorder) : ");
	displayTreeInorder(root);

	// Ʈ�� ���� ���
	printf("\n���� ��ȸ (Preorder) : ");
	displayTreePreorder(root);

	// Ʈ�� ��ȸ ���
	printf("\n���� ��ȸ (Postorder) : ");
	displayTreePostorder(root);

	// �޸� ����
	printf("\n\n�������� �Ҵ�� �޸� ����\n");
	memoryFree(root);

	return 0;
}

treeNode* setBinTree(int* arr, int parentIdx, int maxSize) {
	if (parentIdx >= maxSize)		// �迭 ������ ����� NULL ��ȯ
		return NULL;

	// ���ο� ��� ���� �Ҵ�
	treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
	if (!newNode) {
		fprintf(stderr, "�޸� �Ҵ� ����\n");
		exit(EXIT_FAILURE);		// ���α׷� ���� ����
	}

	// ��� �ʱ�ȭ 
	newNode->value = arr[parentIdx];
	newNode->left = NULL;
	newNode->right = NULL;

	// ���� �ڽ� ���� (���� �ڽ� ����� �ε��� ���)
	int leftIdx = 2 * parentIdx + 1;
	if (leftIdx < maxSize)		// ��ȿ�� �ε������� Ȯ��
		newNode->left = setBinTree(arr, leftIdx, maxSize);	// ���� �ڽ� ��������� ����

	// ������ �ڽ� ���� (������ �ڽ� ����� �ε��� ���)
	int rightIdx = 2 * parentIdx + 2;
	if (rightIdx < maxSize)
		newNode->right = setBinTree(arr, rightIdx, maxSize); // ������ �ڽ� ��������� ����

	return newNode;
}

//��������
void displayTreeInorder(treeNode* t) {
	if (t == NULL) return;		// NULL�̸� ��� ����

	displayTreeInorder(t->left);		// ���� ����Ʈ�� �湮
	printf("%d ", t->value);			// ���� ��� ���
	displayTreeInorder(t->right);		// ������ ����Ʈ�� �湮 
}

//���� ��ȸ
void displayTreePreorder(treeNode* t) {
	if (t == NULL) return;		// NULL�̸� ��� ����

	printf("%d ", t->value);			// ���� ��� ���
	displayTreePreorder(t->left);		// ���� ����Ʈ�� �湮
	displayTreePreorder(t->right);		// ������ ����Ʈ�� �湮 
}

//���� ��ȸ
void displayTreePostorder(treeNode* t) {
	if (t == NULL) return;		// NULL�̸� ��� ����

	displayTreePostorder(t->left);		// ���� ����Ʈ�� �湮
	displayTreePostorder(t->right);		// ������ ����Ʈ�� �湮 
	printf("%d ", t->value);			// ���� ��� ���
}


// Ʈ�� �޸� ���� 
void memoryFree(treeNode* t) {
	if (t == NULL) return;

	// ���� �� ������ ����Ʈ�� �޸� ����
	memoryFree(t->left);
	memoryFree(t->right);

	// ���� ��� �޸� ����
	printf("%d ����\n", t->value);
	free(t);
}