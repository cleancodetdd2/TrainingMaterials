/*
*	�� �Է�: 90 (�Է�)
*   90���� 1�ð� 30���Դϴ�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	const int MINUTE_PER_HOUR = 60;
	int minute;
	printf("�� �Է�: ");

	if (scanf("%d", &minute) != 1) {
		printf("�Է� �����Դϴ�.\n");
		return 1;
	}

	// 90���� 1�ð�(60��)���� ������ ���� 1�ð�, �������� 30��
	printf("%d���� %d�ð� %d�� �Դϴ�.\n", 
		minute, minute / MINUTE_PER_HOUR, minute % MINUTE_PER_HOUR);
	return 0;
}