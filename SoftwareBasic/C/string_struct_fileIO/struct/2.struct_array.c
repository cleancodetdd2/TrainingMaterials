#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LEN	10
#define STUDENT_NUM	3

typedef struct score
{
	char name[NAME_LEN];
	int kor, eng, math;
	double avg;
} score;

int main()
{
	//구조체 배열 (변수를 여러개 선언)
	score s[STUDENT_NUM];
	for (int i = 0; i < STUDENT_NUM; i++)
	{
		system("cls");		//화면 지우기
		printf("\n%d번째 학생 정보 입력\n", i + 1);
		printf("이름 : ");
		gets_s(s[i].name, NAME_LEN);

		printf("국어 영어 수학 점수 입력(공백으로 구분해 연속입력) : ");
		if (scanf("%d %d %d", &s[i].kor, &s[i].eng, &s[i].math) != 3) {
			printf("입력 오류가 발생했습니다.\n");
			return 1;
		}
		while (getchar() != '\n');

		s[i].avg = (s[i].kor + s[i].eng + s[i].math) / 3.0;
	}

	system("cls");	//화면 지우기
	printf("\n\t\t ---학생 점수 리스트--- \n\n");
	printf("%-20s %8s %8s %8s %8s\n", "이름", "국어", "영어", "수학", "평균");
	printf("-----------------------------------------------------------------\n");

	for (int i = 0; i < STUDENT_NUM; i++)
	{
		printf("%-20s %8d %8d %8d %8.2f\n",
			s[i].name, s[i].kor, s[i].eng, s[i].math, s[i].avg);
	}

	return 0;
}