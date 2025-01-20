#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t4()
{
	int num, result;

	result = scanf("%d", &num);
	if (result != 1) {
		printf("입력 오류\n");
		return 1;
	}

	switch (num)
	{
	case 1:
		printf("1입니다.\n");
	case 2:
		printf("2입니다.\n");
	default:			// 아무 case에도 해당되지 않을 때 
		printf("default입니다.\n");
	}

	return 0;
}