#define _CRT_SECURE_NO_WARNINGS		// scanf ���� ���� ���� ������ ���� ���� 
#include <stdio.h>

int main_t5()
{
	int count;

	if (scanf("%d", &count) != 1) {
		printf("�Է� ����\n");
		return 1;
	}

	//for (int i = count; i > 0; i--)
	//	printf("Hello C! %d\n", i);
	for( ;count > 0; count--)		//�ʱⰪ ����
		printf("Hello C! %d\n", count);

	return 0;
}