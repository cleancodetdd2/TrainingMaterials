/***********************************
       ���� ���� ���α׷�

	1. ���� ���� �Է�
	2. ���� ����Ʈ ���
	3. ���� ���� �˻�
	4. ���� ���� ���� 
	5. ���α׷� ����

	�޴� ���� : [ ]
***********************************/
#include <stdio.h>
#include <stdlib.h>		//system()
#include <string.h>		//strcmp()

#define	TITLE_LEN 30	//������ ����
#define AUTHOR_LEN 20	//�۰��� ����
#define BOOK_CNT 5		//���� �Ǽ�	
#pragma warning(disable : 4996)

typedef struct book
{
	char title[TITLE_LEN];		//������
	char author[AUTHOR_LEN];	//�۰�
	int price, cnt, sale;		//����, ����, ����� 
} BOOK;

void registBook(BOOK* pBk, int bookCnt);
void displayBook(BOOK* pBk, int bookCnt);
void searchBook(BOOK* pBk, int bookCnt);
void modifyBook(BOOK* pBk, int bookCnt);
void preRegistMsg();
void modifyMenu(BOOK* pBk, int index);

int main()
{
	BOOK book[BOOK_CNT];	//����ü �迭
	int choice;
	int flag = 0;		// �Է� ���� �Ǻ� 

	while (1)		// ���� ���� 
	{
		system("cls");		// ȭ�� �����
		printf("\n\t\t====���� ���� ���α׷�====\n");
		printf("1. ���� ���� �Է�\n");
		printf("2. ���� ����Ʈ ���\n");
		printf("3. ���� ���� �˻�\n");
		printf("4. ���� ���� ����\n");
		printf("5. ���α׷� ����\n");

		printf("\n�޴� ���� : [ ]\b\b");

		if (scanf("%d", &choice) != 1) {
			printf("�Է� ������ �߻��߽��ϴ�.\n");
			exit(1);
		}
		while (getchar() != '\n');	// '\n'�� �ٹٲ�����, ����ڰ� ����Ű�� ������ �Էµ�
									// ���ۿ� �����ִ� ������ ���(�Է¿��� ��������)

		switch (choice)
		{
		case 1:
			registBook(book, BOOK_CNT);
			flag = 1;	//�Է� �ƴٸ� flag �� 1�� ������ 
			break;
		case 2:
			if (flag == 1)
			{
				displayBook(book, BOOK_CNT);
			}
			else
			{
				preRegistMsg();
			}	
			break;
		case 3:
			if (flag == 1)
				searchBook(book, BOOK_CNT);		//�˻�
			else
				preRegistMsg();
			break;
		case 4:
			if (flag == 1)
				modifyBook(book, BOOK_CNT);		//����
			else
				preRegistMsg();
			break;
		case 5:
			exit(0);		// ���α׷� ���� ���� 
		}
		printf("\n\t\t");
		system("pause");	//switch�� ��� �� �Ͻ� ����
	}

	return 0;
}


void registBook(BOOK* pBk, int bookCnt)
{
	int i;
	for (i = 0; i < bookCnt; i++)
	{
		system("cls");

		printf("[%d��° �Է�]\n\n]", i + 1);
		printf("������ : ");
		gets_s(pBk[i].title, TITLE_LEN);

		printf("�۰� : ");
		gets_s(pBk[i].author, AUTHOR_LEN);

		printf("���� : ");
		if (scanf("%d", &pBk[i].price) != 1) {
			printf("�Է� ���� �Դϴ�.");
			return 1;
		}
		while (getchar() != '\n');

		printf("���� : ");
		if (scanf("%d", &pBk[i].cnt) != 1) {
			printf("�Է� ���� �Դϴ�.");
			return 1;
		}
		while (getchar() != '\n');

		pBk[i].sale = pBk[i].price * pBk[i].cnt;		//����� = ���� * ����


	}

}

void displayBook(BOOK* pBk, int bookCnt)
{
	int i;
	system("cls");
	printf("\n\n\t\t\t ==== ���� ���� ��� === \n\n");
	printf("%4s %-25s %-20s %5s %4s %7s\n", "��ȣ", "������", "�۰�", "����", "����", "�����");

	for (i = 0; i < bookCnt; i++)
		printf("%03d %-25s %-20s %5d %4d %7d\n",
			i + 1, pBk[i].title, pBk[i].author, pBk[i].price, pBk[i].cnt, pBk[i].sale);

}

void searchBook(BOOK* pBk, int bookCnt)
{
	char searchTitle[TITLE_LEN];
	int i;
	int flag = 0;		// �˻� ���� �Ǻ�

	system("cls");
	printf("\n\n �˻��� �������� �Է��ϼ��� : ");
	gets_s(searchTitle, TITLE_LEN);

	printf("\n\n\t\t\t ==== �˻��� ���� ���� ��� === \n\n");
	printf("%4s %-25s %-20s %5s %4s %7s\n", "��ȣ", "������", "�۰�", "����", "����", "�����");
	for (i = 0; i < bookCnt; i++)
	{
		//�˻������� == ���嵵���� (str1 == str2 �ι��ڿ� ����)
		if (strcmp(searchTitle, pBk[i].title) == 0)
		{
			printf("%03d %-25s %-20s %5d %4d %7d\n",
				i + 1, pBk[i].title, pBk[i].author, pBk[i].price, pBk[i].cnt, pBk[i].sale);
			flag = 1; // �˻��� �Ǿ��ٸ� 1�� ��ȯ
		}
	}
	if (flag == 0)
		printf("\n\n\t\t �˻� ������ �������� �ʽ��ϴ�.\n");
}

void modifyBook(BOOK* pBk, int bookCnt)
{
	char modifyTitle[TITLE_LEN];
	int i;
	int flag = 0;		// �˻� ���� �Ǻ�
	
	system("cls");
	printf("\n\n ������ �������� �Է��ϼ��� : ");
	gets_s(modifyTitle, TITLE_LEN);

	for (i = 0; i < bookCnt; i++)
	{
		if (strcmp(modifyTitle, pBk[i].title) == 0)
		{
			//�迭���� ���° ���� ������ ���� index Ȱ��
			modifyMenu(pBk, i);	// �������� ���� �Լ�
			flag = 1;
		}

		if (flag == 0)
			printf("\n\n\t\t�˻� �������� �������� �����Ƿ� ������ �� �����ϴ�.");

	}

}

void preRegistMsg()
{
	printf("\n\n\t\t���� ���� ��� ���Դϴ�.\n");
	printf("\t\t���� ���� ��� �� �ٽ� �̿��� �ּ���.");
}

void modifyMenu(BOOK* pBk, int index)
{
	int select;
	printf("\n\n\t===������ �޴� ����===\n\n");
	printf("1.������  2.�۰�  3. ���� 4. ����  5. ��ü  0. ���� �޴�\n ");
	printf("�޴� ���� : [ ]\b\b");
	if (scanf("%d", &select) != 1) {
		printf("�Է� �����Դϴ�.\n");
		return 1;
	}
	while (getchar() != '\n');

	if (select == 0)
	{
		return;		// ȣ���� ������ ����� �ѱ�
	}

	if (select == 5 || select == 1)
	{
		printf("\n������ �������� �Է��ϼ��� : ");
		gets_s(pBk[index].title, TITLE_LEN);
	}

	if (select == 5 || select == 2)
	{
		printf("\n������ �۰����� �Է��ϼ��� : ");
		gets_s(pBk[index].author, AUTHOR_LEN);
	}

	if (select == 5 || select == 3)
	{
		printf("\n������ ������ �Է��ϼ��� : ");
		if (scanf("%d", &pBk[index].price) != 1) {
			printf("�Է� �����Դϴ�.\n");
			return 1;
		}
		while (getchar() != '\n');

		pBk[index].sale = pBk[index].price * pBk[index].cnt; //���ݺ���� ����� ����
	}

	if (select == 5 || select == 4)
	{
		printf("\n������ ������ �Է��ϼ��� : ");
		if (scanf("%d", &pBk[index].cnt) != 1) {
			printf("�Է� �����Դϴ�.\n");
			return 1;
		}
		while (getchar() != '\n');

		pBk[index].sale = pBk[index].price * pBk[index].cnt; //��������� ����� ����
	}
		
}