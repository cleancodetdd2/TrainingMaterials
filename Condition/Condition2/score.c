/*
	������ �� ������ �Է� �޾� ����� ���� ��
	����� 90�� �̻� => A���
	����� 80�� �̻� => B���
	����� 70�� �̻� => C���
	����� 60�� �̻� => D���
	�� �ܿ��� => F���
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t2()
{
	int kor, eng, math;
	double avg;
	char grade;

	printf("���� ���� ���� ���� �Է�(���� ���� �Է�) : ");

	if (scanf("%d %d %d", &kor, &eng, &math) != 3) {
		printf("�Է� ����\n");
		return 1;
	}

	avg = (double)(kor + eng + math) / 3;

	//���� if�� 
	if (avg >= 90)
		grade = 'A';
	else if (avg < 90 && avg >= 80)
		grade = 'B';
	else if (avg >= 70)
		grade = 'C';
	else if (avg >= 60)
		grade = 'D';
	else
		grade = 'F';

	printf("��� : %.2f, %c ����\n", avg, grade);

	return 0;
}