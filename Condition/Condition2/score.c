/*
	국영수 각 점수를 입력 받아 평균을 구한 후
	평균이 90점 이상 => A등급
	평균이 80점 이상 => B등급
	평균이 70점 이상 => C등급
	평균이 60점 이상 => D등급
	그 외에는 => F등급
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t2()
{
	int kor, eng, math;
	double avg;
	char grade;

	printf("국어 영수 수학 점수 입력(공백 구분 입력) : ");

	if (scanf("%d %d %d", &kor, &eng, &math) != 3) {
		printf("입력 오류\n");
		return 1;
	}

	avg = (double)(kor + eng + math) / 3;

	//다중 if문 
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

	printf("평균 : %.2f, %c 학점\n", avg, grade);

	return 0;
}