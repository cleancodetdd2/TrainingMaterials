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
	
}

//���� ���� ��� �Լ�
void printBookInfo(Book book)
{

}

int main()
{
	Book books[BOOK_CNT];	//���� ���� ������ �迭 

	return 0;
}