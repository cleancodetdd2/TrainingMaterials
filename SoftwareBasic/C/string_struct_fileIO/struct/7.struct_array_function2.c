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
void modifyMenu(BOOK* pBk, int index);

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
		printf("\n\t\t");
		system("pause");	//switch문 벗어난 후 일시 정지
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
	int i;
	system("cls");
	printf("\n\n\t\t\t ==== 도서 정보 출력 === \n\n");
	printf("%4s %-25s %-20s %5s %4s %7s\n", "번호", "도서명", "작가", "가격", "수량", "매출액");

	for (i = 0; i < bookCnt; i++)
		printf("%03d %-25s %-20s %5d %4d %7d\n",
			i + 1, pBk[i].title, pBk[i].author, pBk[i].price, pBk[i].cnt, pBk[i].sale);

}

void searchBook(BOOK* pBk, int bookCnt)
{
	char searchTitle[TITLE_LEN];
	int i;
	int flag = 0;		// 검색 여부 판별

	system("cls");
	printf("\n\n 검색할 도서명을 입력하세요 : ");
	gets_s(searchTitle, TITLE_LEN);

	printf("\n\n\t\t\t ==== 검색된 도서 정보 출력 === \n\n");
	printf("%4s %-25s %-20s %5s %4s %7s\n", "번호", "도서명", "작가", "가격", "수량", "매출액");
	for (i = 0; i < bookCnt; i++)
	{
		//검색도서명 == 저장도서명 (str1 == str2 두문자열 같음)
		if (strcmp(searchTitle, pBk[i].title) == 0)
		{
			printf("%03d %-25s %-20s %5d %4d %7d\n",
				i + 1, pBk[i].title, pBk[i].author, pBk[i].price, pBk[i].cnt, pBk[i].sale);
			flag = 1; // 검색이 되었다면 1로 변환
		}
	}
	if (flag == 0)
		printf("\n\n\t\t 검색 도서는 존재하지 않습니다.\n");
}

void modifyBook(BOOK* pBk, int bookCnt)
{
	char modifyTitle[TITLE_LEN];
	int i;
	int flag = 0;		// 검색 여부 판별
	
	system("cls");
	printf("\n\n 수정할 도서명을 입력하세요 : ");
	gets_s(modifyTitle, TITLE_LEN);

	for (i = 0; i < bookCnt; i++)
	{
		if (strcmp(modifyTitle, pBk[i].title) == 0)
		{
			//배열에서 몇번째 것을 수정할 건지 index 활용
			modifyMenu(pBk, i);	// 도서정보 수정 함수
			flag = 1;
		}

		if (flag == 0)
			printf("\n\n\t\t검색 도서명이 존재하지 않으므로 수정할 수 없습니다.");

	}

}

void preRegistMsg()
{
	printf("\n\n\t\t도서 정보 등록 전입니다.\n");
	printf("\t\t도서 정보 등록 후 다시 이용해 주세요.");
}

void modifyMenu(BOOK* pBk, int index)
{
	int select;
	printf("\n\n\t===수정할 메뉴 선택===\n\n");
	printf("1.도서명  2.작가  3. 가격 4. 수량  5. 전체  0. 이전 메뉴\n ");
	printf("메뉴 선택 : [ ]\b\b");
	if (scanf("%d", &select) != 1) {
		printf("입력 오류입니다.\n");
		return 1;
	}
	while (getchar() != '\n');

	if (select == 0)
	{
		return;		// 호출한 곳으로 제어권 넘김
	}

	if (select == 5 || select == 1)
	{
		printf("\n변경할 도서명을 입력하세요 : ");
		gets_s(pBk[index].title, TITLE_LEN);
	}

	if (select == 5 || select == 2)
	{
		printf("\n변경할 작가명을 입력하세요 : ");
		gets_s(pBk[index].author, AUTHOR_LEN);
	}

	if (select == 5 || select == 3)
	{
		printf("\n변경할 가격을 입력하세요 : ");
		if (scanf("%d", &pBk[index].price) != 1) {
			printf("입력 오류입니다.\n");
			return 1;
		}
		while (getchar() != '\n');

		pBk[index].sale = pBk[index].price * pBk[index].cnt; //가격변경시 매출액 재계산
	}

	if (select == 5 || select == 4)
	{
		printf("\n변경할 수량을 입력하세요 : ");
		if (scanf("%d", &pBk[index].cnt) != 1) {
			printf("입력 오류입니다.\n");
			return 1;
		}
		while (getchar() != '\n');

		pBk[index].sale = pBk[index].price * pBk[index].cnt; //수량변경시 매출액 재계산
	}
		
}