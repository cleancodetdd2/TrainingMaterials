#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* fp;
	char str[256];

	fp = fopen("jobs.txt", "r");		//"jobs.txt" 파일을 읽기모드로 열기
	if (fp == NULL)
	{
		printf("파일 열기 실패함\n");
		exit(-1);		// 프로그램 비정상 종료 
	}

	// 파일 내용을 한 줄씩 읽어와서 str[]에 배열저장하고 출력
	while (fgets(str, sizeof(str), fp) != NULL)
	{
		printf("%s", str);		// 읽어온 한 줄을 출력
	}

	if (fp != NULL)
		fclose(fp);

	return 0;
}