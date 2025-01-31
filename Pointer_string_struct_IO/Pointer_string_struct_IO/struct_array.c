/*
	gets_s(s[i].name, STUDENT_LENGTH) : 입력함수
		- 첫번째 매개변수 : 입력받을 버퍼의 주소
		- 두번째 매개변수 : 입력받을 수 있는 최대 길이
		- 입력받은 문자열 끝에 자동으로 'W0'(널 문자)을 추가함
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define NAME_LENGTH	10
#define STUDENT_LENGTH	3

typedef struct score
{
	char name[NAME_LENGTH];
	int kor, eng, math;
	double avg;
} score;

int main()
{
	//구조체 배열
	score s[STUDENT_LENGTH];
	for (int i = 0; i < STUDENT_LENGTH; i++)
	{
		system("cls");		// 화면 지우기 
		printf("\n%d번째 학생 정보 입력\n", i + 1);
		printf("이름 : ");
		gets_s(s[i].name, NAME_LENGTH);

		printf("국어 영어 수학 점수 입력(공백으로 구분해서 연속 입력): ");
		if (scanf("%d %d %d", &s[i].kor, &s[i].eng, &s[i].math) != 3)
		{
			printf("입력 오류입니다.\n");
			return 1;
		}
		while (getchar() != '\n');
		s[i].avg = (s[i].kor + s[i].eng + s[i].math) / 3.0;
	}
	system("cls");

	printf("\n\t\t 학생 점수 리스트 \n\n");
	printf("%-20s %8s %8s %8s %8s\n", "이름", "국어", "영어", "수학", "평균");
	for (int i = 0; i < STUDENT_LENGTH; i++)
	{
		printf("%-20s %8d %8d %8d %8.2f\n",
			s[i].name, s[i].kor, s[i].eng, s[i].math, s[i].avg);
	}

	return 0;
}