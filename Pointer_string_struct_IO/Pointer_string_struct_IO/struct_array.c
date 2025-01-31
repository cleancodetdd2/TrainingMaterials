/*
	gets_s(s[i].name, STUDENT_LENGTH) : �Է��Լ�
		- ù��° �Ű����� : �Է¹��� ������ �ּ�
		- �ι�° �Ű����� : �Է¹��� �� �ִ� �ִ� ����
		- �Է¹��� ���ڿ� ���� �ڵ����� 'W0'(�� ����)�� �߰���
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define NAME_LENGTH	10
#define STUDENT_LENGTH	3

typedef struct score
{
	char name[NAME_LENGTH];
	int kor, eng, math;
	double avg;
} score;

int main()
{
	//����ü �迭
	score s[STUDENT_LENGTH];
	for (int i = 0; i < STUDENT_LENGTH; i++)
	{
		system("cls");		// ȭ�� ����� 
		printf("\n%d��° �л� ���� �Է�\n", i + 1);
		printf("�̸� : ");
		gets_s(s[i].name, NAME_LENGTH);

		printf("���� ���� ���� ���� �Է�(�������� �����ؼ� ���� �Է�): ");
		if (scanf("%d %d %d", &s[i].kor, &s[i].eng, &s[i].math) != 3)
		{
			printf("�Է� �����Դϴ�.\n");
			return 1;
		}
		while (getchar() != '\n');
		s[i].avg = (s[i].kor + s[i].eng + s[i].math) / 3.0;
	}
	system("cls");

	printf("\n\t\t �л� ���� ����Ʈ \n\n");
	printf("%-20s %8s %8s %8s %8s\n", "�̸�", "����", "����", "����", "���");
	for (int i = 0; i < STUDENT_LENGTH; i++)
	{
		printf("%-20s %8d %8d %8d %8.2f\n",
			s[i].name, s[i].kor, s[i].eng, s[i].math, s[i].avg);
	}

	return 0;
}