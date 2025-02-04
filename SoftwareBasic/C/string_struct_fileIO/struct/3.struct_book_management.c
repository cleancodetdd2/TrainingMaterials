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
	printf("도서명: ");
	fgets(book->title, sizeof(book->title), stdin); //표준입력에서 도서명 읽음

	printf("저자명: ");
	fgets(book->author, sizeof(book->author), stdin);  //표준입력에서 저자명 읽음

	printf("가격: ");
	if (scanf("%d", &book->price) != 1) {	//가격을 입력 받음
		printf("가격 입력 오류\n");
		return ;
	}

	printf("수량: ");
	if (scanf("%d", &book->quantity) != 1) {	//수량을 입력 받음
		printf("수량 입력 오류\n");
		return;
	}
	getchar();  // 입력 버퍼 비우기 

	//매출액 계산 (가격*수량)
	book->revenue = book->price * book->quantity;
}

//도서 정보 출력 함수
void printBookInfo(Book book)
{
	printf("\n도서명: %s\n", book.title);
	printf("저자: %s\n", book.author);
	printf("가격: %d\n", book.price);
	printf("수량: %d\n", book.quantity);
	printf("매출액: %d\n", book.revenue);
}

int main()
{
	Book books[BOOK_CNT];	//도서 정보 저장할 배열 

	printf("===도서 정보 입력===");
	for (int i = 0; i < BOOK_CNT; i++) {
		printf("\n[%d번째 도서]\n", i + 1);
		addBookInfo(&books[i]);
	}

	printf("===도서 정보 출력력===");
	for (int i = 0; i < BOOK_CNT; i++) {
		printBookInfo(books[i]);
	}

	return 0;
}