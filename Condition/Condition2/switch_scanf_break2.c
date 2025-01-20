#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t5()
{
	int num;
	if (scanf("%d", &num) != 1) {
		printf("입력 오류\n");
		return 1;
	}

	switch (num)
	{
	case 1:
	case 2:
		printf("1 또는 2입니다.\n");
		break;
	case 3:
	case 4:
		printf("3 또는 4입니다.\n");
		break;
	default:
		printf("default입니다.\n");
	}
}