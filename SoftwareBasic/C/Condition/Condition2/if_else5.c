/*
	������ �Է� �޾� ¦������ Ȧ������ �Ǻ��Ͻÿ�.
	��) ���� �Է� : 86(�Է�)
		86��(��) ¦�� �Դϴ�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t5()
{
	int num;
	printf("���� �Է� : ");
	if (scanf("%d", &num) != 1)
	{
		printf("�Է� ����\n");
		return 1;
	}

	if (num % 2 == 0)
		printf("%d��(��) ¦�� �Դϴ�.\n", num);
	else 
		printf("%d��(��) Ȧ�� �Դϴ�.\n", num);
	return 0;
}