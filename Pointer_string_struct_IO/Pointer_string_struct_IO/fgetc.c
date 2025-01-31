#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
	FILE* fp;		// 파일 포인터 선언
	int totalcnt = 0, ucnt = 0, lcnt = 0, vcnt = 0;	// 총문자수,대문자수, 소문자수,모음수
	int ch;			// 파일에서 읽은 문자를 저장하는 변수 

	fp = fopen("jobs.txt", "r");	// jobs.txt 파일을 읽기 모드로 열기

	if (fp == NULL)
	{
		printf("파일 열기 실패\n");
		exit(-1);	// 프로그램 비정상 종료
	}

	// 파일 끝(EOF)까지 한 문자씩 읽으며 문자 수 계산하기
	while ((ch = fgetc(fp)) != EOF)
	{
		if (isupper(ch))		// 대문자인 경우
			ucnt++;				// 대문자 개수 증가 
		else if (islower(ch))	// 소문자인 경우
			lcnt++;				// 소문자 개수 증가 

		if (strchr("AEIOUaeiou", ch) != NULL)		// 모음인지 확인
			vcnt++;

		totalcnt++;		// 총 문자 개수 증가 
	}

	fclose(fp);		// 파일 닫기 

	printf("총 글자수 = %d\n", totalcnt);
	printf("대문자 수 = %d\n", ucnt);
	printf("소문자 수 = %d\n", lcnt);
	printf("모음 수 = %d\n", vcnt);

	return 0;
}