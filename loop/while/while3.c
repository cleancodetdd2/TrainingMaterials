#define _CRT_SECURE_NO_WARNINGS		// scanf ���� ���� ���� ������ ���� ���� 
#include <stdio.h>

int main_t3()
{
	int count;

	if (scanf("%d", &count) != 1) {
		printf("�Է� ����\n");
		return 1;
	}

	int i = 0;
	while (i < count)
	{
		printf("Hello C! %d\n", i);
		i++;
	}
		
	return 0;
}