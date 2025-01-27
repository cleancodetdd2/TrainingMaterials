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
	printf("점수 입력 :");
	if (scanf("%d", &score) != 1)
	{
		printf("입력 오류입니다.\n");
		return 1;
	}

	getGrade(score, &grade);

	printf("입력 받은 점수의 등급은 %c입니다.\n", grade);

	return 0;
}