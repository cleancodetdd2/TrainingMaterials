/*
	������ �Է¹޾Ƽ� ������ ����� ����ϰ�
	������� ����� ��ȯ�ؼ� ����Ͻÿ�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num;
	printf("���� �Է� : ");
	if (scanf("%d", &num) != 1) {
		printf("�Է� ���� �߻��߽��ϴ�.");
		return 1;
	}

	if (num < 0)	// ���࿡ ���� ������� 
	{
		num *= -1;			// num = num * -1
		printf("������ ����� ��ȯ �߽��ϴ�.");
	}

	printf("\n����� %d�Դϴ�.\n", num);
	return 0;
}
