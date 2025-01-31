#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH	 10	//이름 최대 길이 상수
#define PHONE_LENGTH 20	//전화번호 최대 길이 상수 
#define TELEPHONE_LENGTH 100	//전화번호 최대 저장 공간

// 전화연락처 구조체 정의
typedef struct telephone
{
	char name[NAME_LENGTH];
	char phone[PHONE_LENGTH];
} telephone;

void regist(telephone* pTel, int* pIdx);	//전화번호 등록
void display(telephone* pTel, int index);	//리스트 출력
void fileOpen(telephone* pTel, int* pIdx);	//전화번호부 불러오기
void sort(telephone* pTel, int index);		//전화번호 정렬
void fileSave(telephone* pTel, int index);	//전화번호부 저장
//...

int main()
{
	telephone tel[TELEPHONE_LENGTH];	// 전화번호부 구조체 배열
	int choice;		// 메뉴 선택
	int index = 0;	// 현재 저장된 전화번호 개수
	int searchIndex;	// 검색된 인덱스를 저장할 변수

	// 파일에서 데이터를 읽어온 개수만큼 인덱스 증가됨
	fileOpen(tel, &index);

	while (1)
	{
		system("cls");
		printf("\n\n 전화번호 관리 프로그램 \n\n");
		printf("1. 전화번호 등록\n");
		printf("2. 전화번호 리스트 출력\n");
		printf("3. 전화번호 수정\n");
		printf("4. 전화번호 삭제\n");
		printf("5. 전화번호 파일 저장\n");
		printf("6. 프로그램 종료\n");

		printf("\n 메뉴 선택 : [ ]\b\b");
		if (scanf("%d", &choice) != 1)
		{
			printf("입력 오류입니다.\n");
			return 1;
		}

		while (getchar() != '\n');		// 입력 버퍼 비우기
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
		printf("\n\n\t\t 저장된 데이터가 존재하지 않습니다.\n");
		system("pause");
		return;		//호출한 곳으로 제어가 돌아감
	}

	*pIdx = 0;	// 읽어들이기 전 기존 데이터 삭제처리 됨

	while (1)
	{
		// 읽어들인 서식 문자의 개수를 리턴 
		count = fscanf(fp, "%s %s", pTel[*pIdx].name, pTel[*pIdx].phone);
		if (count != 2)
			break;	// 반복문 탈출
		(*pIdx)++;
	}

	fclose(fp);
}

void regist(telephone* pTel, int* pIdx)
{
	system("cls");
	if (TELEPHONE_LENGTH == *pIdx)		// 메모리 공간이 다 참
	{
		printf("\n\n\t\t 메모리가 부족합니다. 더이상 등록 불가합니다.");
		printf("\n\n삭제 후 다시 등록 하세요.");
		return;
	}

	printf("** 전화번호부 등록하기 **");
	printf("이름 : ");
	gets_s(pTel[*pIdx].name, NAME_LENGTH);		//이름 입력

	printf("전화번호 : ");
	gets_s(pTel[*pIdx].phone, TELEPHONE_LENGTH); //전화번호 입력

	(*pIdx)++;		//index값 1 증가. 전화번호부 인덱스 증가 

	printf("\n\n\t\t%d번지 등록 완료함\n", *pIdx);
	printf("\t\t남은 메모리 공간 : %d\n", TELEPHONE_LENGTH - *pIdx);

	sort(pTel, (*pIdx));		// 등록 후 이름순 정렬
}

void display(telephone* pTel, int index)
{
	int i;
	system("cls");
	printf("\n\n\t\t 전화번호 리스트 출력 \n\n");

	printf("%5s %-20s %-20s\n", "번호", "이름", "연락처");
	for (i = 0; i < index; i++)
	{
		printf("%5s %-20s %-20s\n", i + 1, pTel[i].name, pTel[i].phone);
	}

	printf("총 등록 건수 : %d\n", index);
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
	fp = fopen("telephoneBook.txt", "w");		//쓰기 모드로 열기
	if (fp == NULL)
	{
		printf("\n\n\t\t 파일 열기 실패함\n");
		return;	//호출한 곳으로 제어 넘김
	}

	for (i = 0; i < index; i++)
	{
		fprintf(fp, "%s %s\n", pTel[i].name, pTel[i].phone);
	}

	fclose(fp);
}