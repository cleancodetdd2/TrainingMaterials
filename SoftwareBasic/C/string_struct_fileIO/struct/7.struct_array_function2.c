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
				displayBook(book, BOOK_CNT);
			else
				preRegistMsg();
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

}

void searchBook(BOOK* pBk, int bookCnt)
{

}

void modifyBook(BOOK* pBk, int bookCnt)
{

}

void preRegistMsg()
{

}