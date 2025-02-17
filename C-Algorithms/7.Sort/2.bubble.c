/*
	����
		- �˰����� �����ϴµ� ù �ܰ�� �Ҽ� ����.
		- ����
			- ���� ����, ���� ����, ���� ����
				- ������ ���� ���� ������ ���տ� ����
				- ū �����ʹ� ��ȿ������
			- ���� ����, �� ����, �� ����
				- ū �����͸� �����ϴµ� ����
				- ���� ������ ���Ŀ��� ���� 

	���� ����
		- ���� ������ �� ��Ҹ� ���Ͽ� �����ϴ� �˰��� 
		- ������ 2���� ��Ҹ� ���ؼ� ��ȯ�� 
		- �Ϲ������� �������� ��ȯ�� �̵� �۾����� ������ 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(const int* arr, int size);

static inline void swap(int* x, int* y) {
	int temp = *x;	// �ӽú����� x ����
	*x = *y;		// x�� y ���� ���� 
	*y = temp;		// y�� �ӽ� ���� �� ���� 
}

//������ ���� ����
void optimizedBubbleSort(int* arr, int size) {
	int swapped;
	for (int i = 0; i < size - 1; i++) {
		swapped = 0;		// ���� ���� üũ 
		for (int j = 0; j < size - 1; j++) {	
			if (arr[j] > arr[j + 1]) {			// ������ �� �� �� 
				printf("��ȯ: %d <-> %d\n", arr[j], arr[j + 1]);	//��ȯ�� �� ���
				swap(&arr[j], &arr[j + 1]);		// �� ��ȯ 
				swapped = 1;					// ��ȯ �߻� ǥ�� 
			}
		}
		//��ȯ�� ������ ���� �Ϸ�
		if (!swapped) break;
		// ���� ���� �ܰ迡�� �迭 ���� ���
		printf("�н� %d �� �迭 ���� : ", i + 1);
		printArray(arr, size);
	}
}

//���� �迭 ���� �Լ�
void generateRandomArray(int* arr, int size, int min, int max) {
	for (int i = 0; i < size; i++)
		arr[i] = rand() % (max - min + 1) + min;	// ������ ���� ������ ���� �� ����
}

// �迭 ��� �Լ�
void printArray(const int* arr, int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);	// �� ��� ���
	puts("");					// �� �ٲ� 
}

int main()
{
	int size, min, max;
	int* arr;

	srand((unsigned int)time(NULL));	// ���α׷� ���� �� �� ���� �õ� ����

	printf("�迭 ũ�� �Է�: ");
	if (scanf("%d", &size) != 1 || size <= 0) {		// ��ȿ�� �Է����� üũ
		printf("�߸��� �Է��Դϴ�. ���α׷��� �����մϴ�.\n");
		return 1;
	}

	arr = (int*)calloc(size, sizeof(int));	// ���� �޸� �Ҵ�
	if (!arr) {		// �޸� �Ҵ� ���� ó��
		printf("�޸� �Ҵ� ����!\n");
		return 1;
	}

	printf("���� ���۰��� ���� �Է� (���� ����): ");
	if (scanf("%d %d", &min, &max) != 2 || min > max) {
		printf("�߸��� �Է��Դϴ�. ���α׷��� �����մϴ�.\n");
		free(arr);
		return 1;
	}

	generateRandomArray(arr, size, min, max);		// ���� �迭 ����

	printf("\n���� �� �迭 : \n");
	printArray(arr, size);							// ���� �� �迭 ���

	optimizedBubbleSort(arr, size);					// ������ ���� ���� ����

	printf("\n���� �� �迭 : \n");
	printArray(arr, size);							// ���� �� �迭 ���

	free(arr);		// �޸� ����

	return 0;
}