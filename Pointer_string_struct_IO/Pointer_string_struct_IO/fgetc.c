#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
	FILE* fp;		// ���� ������ ����
	int totalcnt = 0, ucnt = 0, lcnt = 0, vcnt = 0;	// �ѹ��ڼ�,�빮�ڼ�, �ҹ��ڼ�,������
	int ch;			// ���Ͽ��� ���� ���ڸ� �����ϴ� ���� 

	fp = fopen("jobs.txt", "r");	// jobs.txt ������ �б� ���� ����

	if (fp == NULL)
	{
		printf("���� ���� ����\n");
		exit(-1);	// ���α׷� ������ ����
	}

	// ���� ��(EOF)���� �� ���ھ� ������ ���� �� ����ϱ�
	while ((ch = fgetc(fp)) != EOF)
	{
		if (isupper(ch))		// �빮���� ���
			ucnt++;				// �빮�� ���� ���� 
		else if (islower(ch))	// �ҹ����� ���
			lcnt++;				// �ҹ��� ���� ���� 

		if (strchr("AEIOUaeiou", ch) != NULL)		// �������� Ȯ��
			vcnt++;

		totalcnt++;		// �� ���� ���� ���� 
	}

	fclose(fp);		// ���� �ݱ� 

	printf("�� ���ڼ� = %d\n", totalcnt);
	printf("�빮�� �� = %d\n", ucnt);
	printf("�ҹ��� �� = %d\n", lcnt);
	printf("���� �� = %d\n", vcnt);

	return 0;
}