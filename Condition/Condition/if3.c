#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
*	���� �Է� : 
*   ���࿡ 65�� �̻��� ��� 0���Դϴ�.
	���̾Ƶ�� ������ 2500�� �Դϴ�.

	��)
		�����Է� : 30 (�Է�)
		���̾Ƶ�� ������ 2500�� �Դϴ�.

		�����Է� : 65 (�Է�)
		���̾Ƶ�� ������ 0�� �Դϴ�.
*/

int main()
{
	int entrance_fee = 2500;
	int age;

	printf("�����Է� : ");
	if (scanf("%d", &age) != 1)
	{
		printf("�Է��� �߸��Ǿ����ϴ�. ���α׷��� �����ϰڽ��ϴ�.\n");
		return 1;
	}

	if (age >= 65)
		entrance_fee = 0;

	printf("���̾Ƶ�� ������ %d�� �Դϴ�.\n", entrance_fee);

	return 0;
}