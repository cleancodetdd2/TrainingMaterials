#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define STU_SIZE 3

typedef struct student
{
	int no;
	char name[20];
	int kor, eng, math;
} STUD;

int main()
{
	STUD sp[STU_SIZE];
	FILE* fp;
	int i = 0, j;
	char file_name[80];

	printf("\n ---���ϸ� �Է� : ");
	gets_s(file_name, 79);

	fp = fopen(file_name, "w");
	if (fp == NULL)
	{
		printf("���� ���� ������\n");
		exit(-1);		// ���α׷� ������ ���� 
	}


	// �л� ���� �Է�
	for (i = 0; i < STU_SIZE; i++)
	{
		sp[i].no = i + 1;
		printf("\n ��ȣ : [%03d]\n", sp[i].no);
		printf("�̸� : ");
		gets_s(sp[i].name, 19);
	}

	while (!feof(fp))
	{
		fscanf(fp, "%d %s %d %d %d\n", 
			&sp[i].no, sp[i].name, &sp[i].kor, &sp[i].eng, &sp[i].math);
		i++;
	}

	printf("\n\n%7s %10s %8s %8s %8s\n", "��ȣ", "�̸�", "����", "����", "����");
	printf("------------------------------------------------------------------\n");
	for (j = 0; j < i; j++)
		printf("\n\n%7d %10s %8d %8d %8d\n", 
			sp[j].no, sp[j].name, sp[j].kor, sp[j].eng, sp[j].math);

	fclose(fp);
	return 0;
}