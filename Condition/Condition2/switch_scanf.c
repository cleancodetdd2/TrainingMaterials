#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t3()
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
		break;
	case 2:
		printf("2�Դϴ�.\n");
		break;
	default:			// �ƹ� case���� �ش���� ���� �� 
		printf("default�Դϴ�.\n");
		break;
	}

	return 0;
}