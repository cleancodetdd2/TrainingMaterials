#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* fp;	// 파일 포인터 fp 선언
	char ch;

	fp = fopen("megait.txt", "w");	//"megait.txt"파일을 쓰기 모드로 열기

	if (fp == NULL)
	{
		printf("파일 열기 실패함\n");
		exit(-1);		// 프로그램 비정상 종료 
	}

	printf("문장 여러줄 입력하세요 (Ctrl+Z 또는 Ctrl+D 입력 시 종료) : \n");
	while ((ch = getchar()) != EOF)		// EOF(End OF File) 입력 전까지 반복
		fputc(ch, fp);			// 입력된 문자를 파일에 한 글자씩 저장

	printf("megait.txt파일에 입력이 완료되었습니다...\n");
	fclose(fp);		// 파일 닫기 (리소스 해제)

	return 0;
}