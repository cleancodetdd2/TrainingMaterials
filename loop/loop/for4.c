#define _CRT_SECURE_NO_WARNINGS		// scanf ���� ���� ���� ������ ���� ���� 
#include <stdio.h>

int main_t4()
{
	int count;

	if (scanf("%d", &count) != 1) {
		printf("�Է� ����\n");
		return 1;
	}

	for (int i = 0; i < count; i++)
		printf("Hello C! %d\n", i);

	return 0;
}