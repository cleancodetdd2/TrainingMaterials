#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t5()
{
	int count;

	if (scanf("%d", &count) != 1)
	{
		printf("입력 오류\n");
		return 1;
	}

	for (int i = 0; i < count; i++)		//0부터 입력받은 값보다 작을 때까지 반복
		printf("Hello, AI Agent! %d\n", i);

	return 0;
}