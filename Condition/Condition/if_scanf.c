#define _CRT_SECURE_NO_WARNINGS			// scanf() ���� ���� ���� ������ ���� ����
#include <stdio.h>

int main_t4()
{
	int num1;
	int result;

	result = scanf("%d", &num1);	// �Է¹��� ���� num1������ ����
	if (result != 1)				// �Է��� ����� �Ǿ����� Ȯ��
	{
		printf("�Է� ����\n");
		return 1;
	}

	if (num1 == 10)
		printf("10�Դϴ�.\n");
	
	if (num1 == 20)
		printf("20�Դϴ�.\n");

	return 0;
}