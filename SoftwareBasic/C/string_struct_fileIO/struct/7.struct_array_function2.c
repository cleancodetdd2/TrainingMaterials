/***********************************
       도서 관리 프로그램

	1. 도서 정보 입력
	2. 도서 리스트 출력
	3. 도서 정보 검색
	4. 도서 정보 수정 
	5. 프로그램 종료

	메뉴 선택 : [ ]
***********************************/
#include <stdio.h>
#include <stdlib.h>		//system()
#include <string.h>		//strcmp()

#define	TITLE_LEN 30	//도서명 길이
#define AUTHOR_LEN 20	//작가명 길이
#define BOOK_CNT 5		//도서 권수	
#pragma warning(disable : 4996)

typedef struct book
{
	char title[TITLE_LEN];		//도서명
	char author[AUTHOR_LEN];	//작가
	int price, cnt, sale;		//가격, 수량, 매출액 
} BOOK;

void registBook(BOOK* pBk, int bookCnt);
void displayBook(BOOK* pBk, int bookCnt);
void searchBook(BOOK* pBk, int bookCnt);
void modifyBook(BOOK* pBk, int bookCnt);
void preRegistMsg();

int main()
{
	BOOK book[BOOK_CNT];	//구조체 배열
	int choice;
	int flag = 0;		// 입력 여부 판별 

	while (1)		// 무한 루프 
	{
		system("cls");		// 화면 지우기
		printf("\n\t\t====도서 관리 프로그램====\n");
		printf("1. 도서 정보 입력\n");
		printf("2. 도서 리스트 출력\n");
		printf("3. 도서 정보 검색\n");
		printf("4. 도서 정보 수정\n");
		printf("5. 프로그램 종료\n");

		printf("\n메뉴 선택 : [ ]\b\b");

		if (scanf("%d", &choice) != 1) {
			printf("입력 오류가 발생했습니다.\n");
			exit(1);
		}
		while (getchar() != '\n');	// '\n'은 줄바꿈으로, 사용자가 엔터키를 누르면 입력됨
									// 버퍼에 남아있는 데이터 비움(입력오류 방지위함)

		switch (choice)
		{
		case 1:
			registBook(book, BOOK_CNT);
			flag = 1;	//입력 됐다면 flag 값 1로 변경함 
			break;
		case 2:
			if (flag == 1)
				displayBook(book, BOOK_CNT);
			else
				preRegistMsg();
			break;
		case 3:
			if (flag == 1)
				searchBook(book, BOOK_CNT);		//검색
			else
				preRegistMsg();
			break;
		case 4:
			if (flag == 1)
				modifyBook(book, BOOK_CNT);		//수정
			else
				preRegistMsg();
			break;
		case 5:
			exit(0);		// 프로그램 강제 종료 
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

		printf("[%d번째 입력]\n\n]", i + 1);
		printf("도서명 : ");
		gets_s(pBk[i].title, TITLE_LEN);

		printf("작가 : ");
		gets_s(pBk[i].author, AUTHOR_LEN);

		printf("가격 : ");
		if (scanf("%d", &pBk[i].price) != 1) {
			printf("입력 오류 입니다.");
			return 1;
		}
		while (getchar() != '\n');

		printf("수량 : ");
		if (scanf("%d", &pBk[i].cnt) != 1) {
			printf("입력 오류 입니다.");
			return 1;
		}
		while (getchar() != '\n');

		pBk[i].sale = pBk[i].price * pBk[i].cnt;		//매출액 = 가격 * 수량


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