#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void getGrade(int score, char* pGrade)
{
	if (score <= 100 && score >= 90)
		*pGrade = 'A';
	else if (score >= 80)
		*pGrade = 'B';
	else if (score >= 70)
		*pGrade = 'C';
	else if (score >= 60)
		*pGrade = 'D';
	else 
		*pGrade = 'F';
}

int main()
{
	int score;
	char grade;
	printf("���� �Է� :");
	if (scanf("%d", &score) != 1)
	{
		printf("�Է� �����Դϴ�.\n");
		return 1;
	}

	getGrade(score, &grade);

	printf("�Է� ���� ������ ����� %c�Դϴ�.\n", grade);

	return 0;
}