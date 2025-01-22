#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num;
	int result;

	result = scanf("%d", &num);
	if (result != 1) {
		printf("입력 오류\n");
		return 1;
	}

	switch (num)
	{
	case 1:
		printf("1입니다.\n");
		break;
	case 2:
		printf("2입니다.\n");
		break;
	default:
		printf("default입니다.\n");
		break;
	}
	return 0;
}