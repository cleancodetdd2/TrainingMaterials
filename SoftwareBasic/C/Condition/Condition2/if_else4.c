/*
	국/영/수 점수 입력 => 각각 60점 이상이면 합격입니다.
						  한과목이라도 60점 미만이면 불합격입니다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t4()
{
	int kor, eng, math;
	int result;

	printf("국어 영어 수학 점수 입력(공백구별) : ");
	result = scanf("%d %d %d", &kor, &eng, &math);
	if (result != 3) {
		printf("입력 오류\n");
		return 1;
	}

	if (kor < 60 || eng < 60 || math < 60)
		printf("불합격입니다.\n");
	else 
		printf("합격입니다.\n");

	return 0;
}