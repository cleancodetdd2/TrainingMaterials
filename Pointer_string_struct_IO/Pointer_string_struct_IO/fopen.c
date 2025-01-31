#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* fp;	// 파일 포인터 변수
	char ch;

	// "megait.txt" 파일을 쓰기 모드로 열기(파일이 없으면 생성) 
	fp = fopen("megait.txt", "w");

	if (fp == NULL)
	{
		printf("파일 열기 실패\n");
		exit(-1);	// 프로그램 비정상 종료
	}

	printf("문장 여러 줄 입력 (Ctrl+Z 또는 Ctrl+D 입력시 종료) : \n");

	// getchar() : 문자단위로 입력을 받고, 개행 문자(\n)가 나올 때까지 반복
	while ((ch = getchar()) != '\n')
		fputc(ch, fp);	// 입력된 문자를 파일에 한 글자씩 저장 

	printf("megait.txt 파일에 입력이 완료되었습니다.\n");

	fclose(fp);		// 파일 닫기 (리소스 해제)

	return 0;
}