#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t1()
{
	//�迭�� �� �� �̻� �ʱ�ȭ ��, ������ ������ 0���� ä���� 
	int a[100] = { 0 };
	printf("%d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[99]);
	printf("\n");

	int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int i, inputMonth;
	for (i = 1; i <= 12; i++)
		printf("%2d���� ��¥�� %2d�� �Դϴ�.\n", i, month[i]);

	printf("\n\n�� �Է� : ");
	if (scanf("%d", &inputMonth) != 1) {
		printf("�Է� �����Դϴ�.\n");
		return 1;
	}
	printf("�Է��� ���� ��¥�� %d�� �Դϴ�\n", month[inputMonth]);

	return 0;
}