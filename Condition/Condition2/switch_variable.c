#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t6()
{

	int num;
	if (scanf("%d", &num) != 1) {
		printf("�Է� ����\n");
		return 1;
	}

	switch (num)
	{
	case 1:
	{
		int num2 = num;
		printf("%d�Դϴ�.\n", num2);
		break;
	}

	case 2:
		printf("1 �Ǵ� 2�Դϴ�.\n");
		break;
	default:
		printf("default�Դϴ�.\n");
	}

	return 0;
}