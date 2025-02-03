/*****************************
* 요구사항
 : 3권의 도서 정보를 저장하는 도서관리 프로그램을 구조체를 활용하여 작성하시오.
	1) 구조체 정의 (도서명, 저자, 가격, 수량, 매출액)
	2) 도서명, 저자, 가격, 수량은 입력 받음
	3) 매출액은 가격*수량 출력하기
******************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BOOK_CNT	3 

//도서 정보 구조체 정의
typedef struct {
	char title[100];	//도서명
	char author[100];	//저자
	int price;			//가격
	int quantity;		//수량
	int revenue;		//매출액(가격*수량)
} Book;

//도서 정보 입력 함수
void addBookInfo(Book* book) 
{
	
}

//도서 정보 출력 함수
void printBookInfo(Book book)
{

}

int main()
{
	Book books[BOOK_CNT];	//도서 정보 저장할 배열 

	return 0;
}