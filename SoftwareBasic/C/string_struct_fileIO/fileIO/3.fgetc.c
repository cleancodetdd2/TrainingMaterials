#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* fp;
	char str[256];

	fp = fopen("jobs.txt", "r");		//"jobs.txt" ������ �б���� ����
	if (fp == NULL)
	{
		printf("���� ���� ������\n");
		exit(-1);		// ���α׷� ������ ���� 
	}

	// ���� ������ �� �پ� �о�ͼ� str[]�� �迭�����ϰ� ���
	while (fgets(str, sizeof(str), fp) != NULL)
	{
		printf("%s", str);		// �о�� �� ���� ���
	}

	if (fp != NULL)
		fclose(fp);

	return 0;
}