#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i;
	int arr[5];
	int max, min;

	printf("�ִ밪�� �ּҰ� ���ϱ�\n\n");

	for (i = 0; i < 5; i++)
	{
		printf("�Է� %d : ", i + 1);
		if(scanf("%d", &arr[i]) != 1) {
			printf("�Է� �����Դϴ�\n");
			return 1;
		}
	}

	max = min = arr[0];	// ù��° ���� �ִ񰪰� �ּҰ����� �ʱ�ȭ �� 

	for (i = 1; i < 5; i++)
	{
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
	}

	printf("\n�ִ� : %d\n", max);
	printf("�ּڰ� : %d\n", min);

	return 0;
}