// 5�� ������ �Է¹޾Ƽ� ���� �ִ밪�� �ּҰ��� ���Ͻÿ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t3()
{
	int i;
	int arr[5];
	int max, min;

	printf("�ִ밪�� �ּҰ��� ���Ͻÿ�\n");
	for (i = 0; i < 5; i++)
	{
		printf("�Է� %d : ", i + 1);
		if (scanf("%d", &arr[i]) != 1) {
			printf("�Է� �����Դϴ�.\n");
			return 1;
		}
	}

	max = min = arr[0];		//ù��° ���� �ִ밪�� �ּҰ����� �ʱ�ȭ �� 
	for (i = 1; i < 5; i++)
	{
		if (max < arr[i])	//arr[i]�� ���� max���� ũ�ٸ�
		{
			max = arr[i];	//arr[i]�� ���� max�� �� 
		}
		if (min > arr[i])   //arr[i]�� ���� min���� �۴ٸ�
		{
			min = arr[i];	//arr[i]�� ���� min�� �� 
		}
	}

	printf("\n===============\n");
	printf("�ִ밪 : %d\n", max);
	printf("�ּҰ� : %d\n", min);

	return 0;
}