// 5�� ������ �Է¹޾� �迭�� �ʱ�ȭ �� �� ����� ����Ͻÿ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t2()
{
	int arr[5];
	int i;		//�迭�� �ε���(÷��)
	int sum = 0;

	for (i = 0; i < 5; i++)
	{
		printf("%d��° �Է� : ", i + 1);
		if (scanf("%d", &arr[i]) != 1) {
			printf("�Է� �����Դϴ�.\n");
			return 1;
		}
		//printf("�Է��� �� : arr[%d] = %d\n", i, arr[i]);
		sum += arr[i];	// ������
	}

	printf("5�� ������ ����� %.2f�Դϴ�.\n", sum / 5.0);

	return 0;
}