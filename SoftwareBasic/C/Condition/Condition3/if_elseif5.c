#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t5()
{
	int kor, eng, math;
	double avg;
	char grade;

	printf("국어 영어 수학 점수 입력(공백구분) : ");
	if (scanf("%d %d %d", &kor, &eng, &math) != 3) {
		printf("입력 오류\n");
		return 1;
	}

	avg = (double)(kor + eng + math) / 3;

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

	printf("평균 : %.2f(%c등급)\n", avg, grade);

	return 0;
}