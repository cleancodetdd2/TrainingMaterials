#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ��ũ�� �Լ� : �� ������ ���� ��ȯ
#define swap(type, x, y) do { type temp = x; x = y; y = temp; } while(0)

// �迭�� ���� ������ �ʱ�ȭ
void randomize(int* arr, int size, int start, int end) {
	for (int i = 0; i < size; i++)
		arr[i] = rand() % (end - start + 1) + start;  //������ ���� �� ���� �� ����
}

// �迭 ��� �Լ� (������ ����)
void print_array_spaced(int* arr, int size) {
	for (int i = 0; i < size; i++)	// �迭�� ��� ��� ���
		printf("%3d ", arr[i]);
	printf("\n");
	printf("\n");
}

//���� ���� �Լ�
//�迭���� �ּڰ��� ã�� �� �պ��� �����ϴ� ���
void selection_sort(int* arr, int size) {
	int i, j, min;		// �ּڰ� �ε��� ����
	printf(" �ܰ� |   i    | �ʱ� min �� | ���� min �� | ��ȯ ���� |    ���� �� �迭\n");
	printf("-----------------------------------------------------------------------------\n");

	for (i = 0; i < size - 1; i++) {	// �迭 ũ�� -1��ŭ �ݺ�(������ ��Ҵ� �ڵ� ���ĵ�)
		min = i;	// ���� ���� ��ġ�� �ּڰ����� ����
		int initial_min_value = arr[min];	// �ʱ� �ּҰ� ���� (���� i ��ġ�� ��)

		for (j = i + 1; j < size; j++) {	// ���� i ������ ����� ���Ͽ� �ּڰ� ã��
			if (arr[min] > arr[j])			// ���� �ּڰ����� ���� �� �߽߰� �ּڰ� �ε��� ����
				min = j;
		}
		int final_min_value = arr[min];		// ���������� ã�� �ּڰ� ���� 
		int swap_happend = (i != min);	// ���� i ��ġ�� ���� �ּڰ��� ��ġ�� �ٸ� => ��ȯ�ʿ�
		
		if (swap_happend)	// �ּҰ��� ���� ��ġ�� ���� �ٸ� ���
			swap(int, arr[i], arr[min]);	// i��ġ�� ���� �ּڰ� ��ȯ 

		//���� ���� ���
		printf("  %3d  |  %3d  |    %10d  |    %10d  |  %7s  | ",
			i + 1, i, initial_min_value, final_min_value, swap_happend ? "Yes" : "No");
		print_array_spaced(arr, size);		//���� ���ĵ� ���� ���
		printf("\n");
	}

}


int main()
{
	int size, start, end;	// �迭ũ��, ���� ���� ���� ����
	int* arr;				// ���� �Ҵ��� �迭 ������ ����

	srand((unsigned int)time(NULL));		// ���� �ʱ�ȭ (���α׷� ����� 1ȸ ����)

	//�迭 ũ�� �Է�
	printf("�迭 ũ�� �Է� : ");
	if (scanf("%d", &size) != 1 || size <= 0) {
		printf("��ȿ�� �迭 ũ�⸦ �Է��ϼ���.\n");
		return 1;	// ���� �߻� �� ���α׷� ����
	}

	//�޸� ���� �Ҵ�
	arr = calloc(size, sizeof(int));	// �迭�� 0���� �ʱ�ȭ�Ͽ� ���� �Ҵ�
	if (!arr) {	// �޸� �Ҵ� ����
		printf("�޸� �Ҵ� ����\n");
		return 1;
	}

	//���� ���� �Է�
	printf("���� ���� �� / �� �� �Է� (���� ����) : ");
	if (scanf("%d %d", &start, &end) != 2 || start > end) {
		printf("��ȿ�� ���� ������ �Է��ϼ���.\n");
		free(arr);		// �޸� ����
		return 1;
	}

	randomize(arr, size, start, end);

	//���� �� �迭 ���
	printf("\n\n--- ���� �� �ڷ� ��� ---\n");
	print_array_spaced(arr, size);
	printf("\n\n");

	//���� ���� ����
	selection_sort(arr, size);

	//���� �� �迭 ���
	printf("\n\n--- ���� �� �ڷ� ��� ---\n");
	print_array_spaced(arr, size);
	printf("\n\n");

	// ���� �޸� ����
	free(arr);		// �Ҵ�� �޸� ��ȯ
	return 0;
}