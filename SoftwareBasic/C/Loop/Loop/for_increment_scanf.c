#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t5()
{
	int count;

	if (scanf("%d", &count) != 1)
	{
		printf("�Է� ����\n");
		return 1;
	}

	for (int i = 0; i < count; i++)		//0���� �Է¹��� ������ ���� ������ �ݺ�
		printf("Hello, AI Agent! %d\n", i);

	return 0;
}