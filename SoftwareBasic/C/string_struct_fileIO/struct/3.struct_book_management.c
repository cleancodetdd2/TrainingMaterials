/*****************************
* �䱸����
 : 3���� ���� ������ �����ϴ� �������� ���α׷��� ����ü�� Ȱ���Ͽ� �ۼ��Ͻÿ�.
	1) ����ü ���� (������, ����, ����, ����, �����)
	2) ������, ����, ����, ������ �Է� ����
	3) ������� ����*���� ����ϱ�
******************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BOOK_CNT	3 

//���� ���� ����ü ����
typedef struct {
	char title[100];	//������
	char author[100];	//����
	int price;			//����
	int quantity;		//����
	int revenue;		//�����(����*����)
} Book;

//���� ���� �Է� �Լ�
void addBookInfo(Book* book) 
{
	printf("������: ");
	fgets(book->title, sizeof(book->title), stdin); //ǥ���Է¿��� ������ ����

	printf("���ڸ�: ");
	fgets(book->author, sizeof(book->author), stdin);  //ǥ���Է¿��� ���ڸ� ����

	printf("����: ");
	if (scanf("%d", &book->price) != 1) {	//������ �Է� ����
		printf("���� �Է� ����\n");
		return ;
	}

	printf("����: ");
	if (scanf("%d", &book->quantity) != 1) {	//������ �Է� ����
		printf("���� �Է� ����\n");
		return;
	}
	getchar();  // �Է� ���� ���� 

	//����� ��� (����*����)
	book->revenue = book->price * book->quantity;
}

//���� ���� ��� �Լ�
void printBookInfo(Book book)
{
	printf("\n������: %s\n", book.title);
	printf("����: %s\n", book.author);
	printf("����: %d\n", book.price);
	printf("����: %d\n", book.quantity);
	printf("�����: %d\n", book.revenue);
}

int main()
{
	Book books[BOOK_CNT];	//���� ���� ������ �迭 

	printf("===���� ���� �Է�===");
	for (int i = 0; i < BOOK_CNT; i++) {
		printf("\n[%d��° ����]\n", i + 1);
		addBookInfo(&books[i]);
	}

	printf("===���� ���� ��·�===");
	for (int i = 0; i < BOOK_CNT; i++) {
		printBookInfo(books[i]);
	}

	return 0;
}