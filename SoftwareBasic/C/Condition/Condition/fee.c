/*
*  ���̸� �Է� �޾� 60�� �̻��� ��� 
*  ����Ḧ 0������ �ٲٴ� �ڵ带 �ۼ��Ͻÿ�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int fee = 2000;
	int age;

	printf("���� �Է�: ");
	if (scanf("%d", &age) != 1) {
		printf("�Է��� �߸��Ǿ����ϴ�. ���α׷��� �����մϴ�.\n");
		return 1;
	}

	if (age >= 60)
		fee = 0;

	printf("������ %d�� �Դϴ�.\n", fee);
	return 0;
}