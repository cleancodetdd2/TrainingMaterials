/*
	��/��/�� ���� �Է� => ���� 60�� �̻��̸� �հ��Դϴ�.
						  �Ѱ����̶� 60�� �̸��̸� ���հ��Դϴ�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t4()
{
	int kor, eng, math;
	int result;

	printf("���� ���� ���� ���� �Է�(���鱸��) : ");
	result = scanf("%d %d %d", &kor, &eng, &math);
	if (result != 3) {
		printf("�Է� ����\n");
		return 1;
	}

	if (kor < 60 || eng < 60 || math < 60)
		printf("���հ��Դϴ�.\n");
	else 
		printf("�հ��Դϴ�.\n");

	return 0;
}