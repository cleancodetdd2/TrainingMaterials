#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a[100] = { 0 };  // �迭�� �� �� �̻� �ʱ�ȭ ��, ������ ������ 0���� ä����
	//printf("%d %d %d %d\n", a[0], a[1], a[2], a[99]);

	int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int i, searchMonth;
	for (i = 1; i <= 12; i++)
		printf("%2d���� �ϼ��� %2d�� �Դϴ�.\n", i, month[i]);

	printf("\n\n�˻� �� �Է� : ");
	if (scanf("%d", &searchMonth) != 1) {
		printf("�Է� ���� �Դϴ�.\n");
		return 1;
	}

	printf("�˻��� ���� �ϼ��� %2d�� �Դϴ�.\n", month[searchMonth]);

	return 0;
}