#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t2()
{
	int num;
	printf("���� �Է�: ");
	if (scanf("%d", &num) != 1)
	{
		printf("�Է� ������ �߻��߽��ϴ�.");
		return 1;
	}
	

	/*if (num == 1)
	{
		printf("1�� �����Դϴ�.");
	}
	else if (num == 2)
	{
		printf("2�� �����Դϴ�.");
	}
	else if (num == 3)
	{
		printf("3�� ���Դϴ�.");
	}
	else {
		printf("����");
	}
	*/

	switch (num)		//����
	{
	case 1:				//��
		printf("1�� �����Դϴ�.");
		//break;
	case 2:
		printf("2�� �����Դϴ�.");
		//break;
	case 3:
		printf("3�� ���Դϴ�.");
		//break;
	default:
		printf("����");
	}
	return 0;
}