#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t6()
{

	int num;
	if (scanf("%d", &num) != 1) {
		printf("입력 오류\n");
		return 1;
	}

	switch (num)
	{
	case 1:
	{
		int num2 = num;
		printf("%d입니다.\n", num2);
		break;
	}

	case 2:
		printf("1 또는 2입니다.\n");
		break;
	default:
		printf("default입니다.\n");
	}

	return 0;
}