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
	do //ó�� �� ���� �Ʒ� �ڵ尡 �����
	{
		printf("Hello C! %d\n", i);
		i++;
	} while (i < count);

	return 0;
}