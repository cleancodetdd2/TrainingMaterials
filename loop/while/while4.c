#define _CRT_SECURE_NO_WARNINGS		// scanf ���� ���� ���� ������ ���� ���� 
#include <stdio.h>

int main_t4()
{
	int count;

	if (scanf("%d", &count) != 1) {
		printf("�Է� ����\n");
		return 1;
	}

	while (count > 0)		//�ʱⰪ ����
	{
		printf("Hello C! %d\n", count);
		count--;
	}
		

	return 0;
}