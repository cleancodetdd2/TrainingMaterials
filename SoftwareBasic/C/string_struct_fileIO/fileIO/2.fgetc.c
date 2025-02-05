#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
	FILE* fp;		// ���� ������ ����
	int tot = 0, ucnt = 0, lcnt = 0, vcnt = 0; // �ѹ��� ��, �빮�� ��, �ҹ��� ��, ���� ��
	int ch;			// ���Ͽ��� ���� ���ڸ� �����ϴ� ����

	fp =fopen("jobs.txt", "r");		//"jobs.txt" ������ �б���� ����

	if (fp == NULL)
	{
		printf("���� ���� ������\n");
		exit(-1);		// ���α׷� ������ ���� 
	}

	while ((ch = fgetc(fp)) != EOF)
	{
		if (isupper(ch))		// �빮���� ���
			ucnt++;				// �빮�� �� ����
		else if (islower(ch))	// �ҹ����� ���
			lcnt++;				// �ҹ��� �� ���� 

		if (strchr("AEIOUaeiou", ch) != NULL)	// �������� Ȯ��
			vcnt++;				// ���� �� ���� 

		tot++;					// �� ���� ���� ���� 
	}

	fclose(fp);		// ���� �ݱ� 

	//��� ���
	printf("�� ���ڼ� : %d\n", tot);
	printf("�빮�� �� : %d\n", ucnt);
	printf("�ҹ��� �� : %d\n", lcnt);
	printf("���� �� : %d\n", vcnt);

	return 0;
}