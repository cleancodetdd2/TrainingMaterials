#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t4()
{
	int num, result;

	result = scanf("%d", &num);
	if (result != 1) {
		printf("�Է� ����\n");
		return 1;
	}

	switch (num)
	{
	case 1:
		printf("1�Դϴ�.\n");
	case 2:
		printf("2�Դϴ�.\n");
	default:			// �ƹ� case���� �ش���� ���� �� 
		printf("default�Դϴ�.\n");
	}

	return 0;
}