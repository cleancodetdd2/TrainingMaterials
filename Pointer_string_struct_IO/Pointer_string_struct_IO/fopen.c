#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* fp;	// ���� ������ ����
	char ch;

	// "megait.txt" ������ ���� ���� ����(������ ������ ����) 
	fp = fopen("megait.txt", "w");

	if (fp == NULL)
	{
		printf("���� ���� ����\n");
		exit(-1);	// ���α׷� ������ ����
	}

	printf("���� ���� �� �Է� (Ctrl+Z �Ǵ� Ctrl+D �Է½� ����) : \n");

	// getchar() : ���ڴ����� �Է��� �ް�, ���� ����(\n)�� ���� ������ �ݺ�
	while ((ch = getchar()) != '\n')
		fputc(ch, fp);	// �Էµ� ���ڸ� ���Ͽ� �� ���ھ� ���� 

	printf("megait.txt ���Ͽ� �Է��� �Ϸ�Ǿ����ϴ�.\n");

	fclose(fp);		// ���� �ݱ� (���ҽ� ����)

	return 0;
}