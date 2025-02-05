#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
	FILE* fp;		// 파일 포인터 선언
	int tot = 0, ucnt = 0, lcnt = 0, vcnt = 0; // 총문자 수, 대문자 수, 소문자 수, 모음 수
	int ch;			// 파일에서 읽을 문자를 저장하는 변수

	fp =fopen("jobs.txt", "r");		//"jobs.txt" 파일을 읽기모드로 열기

	if (fp == NULL)
	{
		printf("파일 열기 실패함\n");
		exit(-1);		// 프로그램 비정상 종료 
	}

	while ((ch = fgetc(fp)) != EOF)
	{
		if (isupper(ch))		// 대문자인 경우
			ucnt++;				// 대문자 수 증가
		else if (islower(ch))	// 소문자인 경우
			lcnt++;				// 소문자 수 증가 

		if (strchr("AEIOUaeiou", ch) != NULL)	// 모음인지 확인
			vcnt++;				// 모음 수 증가 

		tot++;					// 총 문자 개수 증가 
	}

	fclose(fp);		// 파일 닫기 

	//결과 출력
	printf("총 글자수 : %d\n", tot);
	printf("대문자 수 : %d\n", ucnt);
	printf("소문자 수 : %d\n", lcnt);
	printf("모음 수 : %d\n", vcnt);

	return 0;
}