#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t5()
{
	int num;
	if (scanf("%d", &num) != 1) {
		printf("�Է� ����\n");
		return 1;
	}

	switch (num)
	{
	case 1:
	case 2:
		printf("1 �Ǵ� 2�Դϴ�.\n");
		break;
	case 3:
	case 4:
		printf("3 �Ǵ� 4�Դϴ�.\n");
		break;
	default:
		printf("default�Դϴ�.\n");
	}
}