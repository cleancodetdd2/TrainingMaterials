#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH	 10	//�̸� �ִ� ���� ���
#define PHONE_LENGTH 20	//��ȭ��ȣ �ִ� ���� ��� 
#define TELEPHONE_LENGTH 100	//��ȭ��ȣ �ִ� ���� ����

// ��ȭ����ó ����ü ����
typedef struct telephone
{
	char name[NAME_LENGTH];
	char phone[PHONE_LENGTH];
} telephone;

void regist(telephone* pTel, int* pIdx);	//��ȭ��ȣ ���
void display(telephone* pTel, int index);	//����Ʈ ���
void fileOpen(telephone* pTel, int* pIdx);	//��ȭ��ȣ�� �ҷ�����
void sort(telephone* pTel, int index);		//��ȭ��ȣ ����
void fileSave(telephone* pTel, int index);	//��ȭ��ȣ�� ����
//...

int main()
{
	telephone tel[TELEPHONE_LENGTH];	// ��ȭ��ȣ�� ����ü �迭
	int choice;		// �޴� ����
	int index = 0;	// ���� ����� ��ȭ��ȣ ����
	int searchIndex;	// �˻��� �ε����� ������ ����

	// ���Ͽ��� �����͸� �о�� ������ŭ �ε��� ������
	fileOpen(tel, &index);

	while (1)
	{
		system("cls");
		printf("\n\n ��ȭ��ȣ ���� ���α׷� \n\n");
		printf("1. ��ȭ��ȣ ���\n");
		printf("2. ��ȭ��ȣ ����Ʈ ���\n");
		printf("3. ��ȭ��ȣ ����\n");
		printf("4. ��ȭ��ȣ ����\n");
		printf("5. ��ȭ��ȣ ���� ����\n");
		printf("6. ���α׷� ����\n");

		printf("\n �޴� ���� : [ ]\b\b");
		if (scanf("%d", &choice) != 1)
		{
			printf("�Է� �����Դϴ�.\n");
			return 1;
		}

		while (getchar() != '\n');		// �Է� ���� ����
		switch (choice)
		{
		case 1:
			regist(tel, &index);
			break;
		case 2:
			display(tel, index);
			break;
		case 5:
			fileSave(tel, index);
			break;
		case 0:
			fileSave(tel, index);
			exit(0);
		}

		printf("\n\n");
		system("pause");

	}

	return 0;
}

void fileOpen(telephone* pTel, int* pIdx)
{
	char isExit;
	int count;
	FILE* fp;
	fp = fopen("telephoneBook.txt", "r");
	if (fp == NULL)
	{
		printf("\n\n\t\t ����� �����Ͱ� �������� �ʽ��ϴ�.\n");
		system("pause");
		return;		//ȣ���� ������ ��� ���ư�
	}

	*pIdx = 0;	// �о���̱� �� ���� ������ ����ó�� ��

	while (1)
	{
		// �о���� ���� ������ ������ ���� 
		count = fscanf(fp, "%s %s", pTel[*pIdx].name, pTel[*pIdx].phone);
		if (count != 2)
			break;	// �ݺ��� Ż��
		(*pIdx)++;
	}

	fclose(fp);
}

void regist(telephone* pTel, int* pIdx)
{
	system("cls");
	if (TELEPHONE_LENGTH == *pIdx)		// �޸� ������ �� ��
	{
		printf("\n\n\t\t �޸𸮰� �����մϴ�. ���̻� ��� �Ұ��մϴ�.");
		printf("\n\n���� �� �ٽ� ��� �ϼ���.");
		return;
	}

	printf("** ��ȭ��ȣ�� ����ϱ� **");
	printf("�̸� : ");
	gets_s(pTel[*pIdx].name, NAME_LENGTH);		//�̸� �Է�

	printf("��ȭ��ȣ : ");
	gets_s(pTel[*pIdx].phone, TELEPHONE_LENGTH); //��ȭ��ȣ �Է�

	(*pIdx)++;		//index�� 1 ����. ��ȭ��ȣ�� �ε��� ���� 

	printf("\n\n\t\t%d���� ��� �Ϸ���\n", *pIdx);
	printf("\t\t���� �޸� ���� : %d\n", TELEPHONE_LENGTH - *pIdx);

	sort(pTel, (*pIdx));		// ��� �� �̸��� ����
}

void display(telephone* pTel, int index)
{
	int i;
	system("cls");
	printf("\n\n\t\t ��ȭ��ȣ ����Ʈ ��� \n\n");

	printf("%5s %-20s %-20s\n", "��ȣ", "�̸�", "����ó");
	for (i = 0; i < index; i++)
	{
		printf("%5s %-20s %-20s\n", i + 1, pTel[i].name, pTel[i].phone);
	}

	printf("�� ��� �Ǽ� : %d\n", index);
}

void sort(telephone* pTel, int index)
{
	int i, j;
	telephone temp;

	for (i = 0; i < index - 1; i++)
	{
		for (j = i + 1; j < index; j++)
		{
			if (strcmp(pTel[i].name, pTel[j].name) > 0)
			{
				temp = pTel[i];
				pTel[i] = pTel[j];
				pTel[j] = temp;
			}
		}
	}
}

void fileSave(telephone* pTel, int index)
{
	int i;
	FILE* fp;
	fp = fopen("telephoneBook.txt", "w");		//���� ���� ����
	if (fp == NULL)
	{
		printf("\n\n\t\t ���� ���� ������\n");
		return;	//ȣ���� ������ ���� �ѱ�
	}

	for (i = 0; i < index; i++)
	{
		fprintf(fp, "%s %s\n", pTel[i].name, pTel[i].phone);
	}

	fclose(fp);
}