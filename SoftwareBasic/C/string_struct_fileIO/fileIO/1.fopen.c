#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* fp;	// ���� ������ fp ����
	char ch;

	fp = fopen("megait.txt", "w");	//"megait.txt"������ ���� ���� ����

	if (fp == NULL)
	{
		printf("���� ���� ������\n");
		exit(-1);		// ���α׷� ������ ���� 
	}

	printf("���� ������ �Է��ϼ��� (Ctrl+Z �Ǵ� Ctrl+D �Է� �� ����) : \n");
	while ((ch = getchar()) != EOF)		// EOF(End OF File) �Է� ������ �ݺ�
		fputc(ch, fp);			// �Էµ� ���ڸ� ���Ͽ� �� ���ھ� ����

	printf("megait.txt���Ͽ� �Է��� �Ϸ�Ǿ����ϴ�...\n");
	fclose(fp);		// ���� �ݱ� (���ҽ� ����)

	return 0;
}