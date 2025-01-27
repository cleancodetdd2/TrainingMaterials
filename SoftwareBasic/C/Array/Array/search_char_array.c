/*
	rand() % 26 = 0 ==> 0 + 65 = 65 ==> 'A'
	rand() % 26 = 1 ==> 1 + 65 = 66 ==> 'B'
	....
	rand() % 26 = 25 ==> 25 + 65 = 90 ==> 'Z'
*/

#define _CRT_SECURE_NO_WARNINGS
#define ALPHABET_SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	char alphabet[ALPHABET_SIZE];
	int i;
	char searchChar;
	int count;

	srand((unsigned int)time(NULL)); //현재 시간을 시드로 사용하여 난수 생성기 초기화
	printf("\n\n 대문자를 랜덤하게 100개 저장 \n\n");
	for (i = 0; i < ALPHABET_SIZE; i++)
	{
		alphabet[i] = rand() % 26 + 65;   // A ~ Z 랜덤 대문자 초기화 
		printf("%4c", alphabet[i]);

		if (i % 10 == 9)
			printf("\n");
	}

	do
	{
		printf("\n\n검색 문자 입력 : ");
		if (scanf("%c", &searchChar) != 1) {
			printf("입력 오류입니다.");
			return 1;
		}
		while (getchar() != '\n');
	} while (searchChar < 'A' || searchChar > 'Z');

	count = 0;
	for (i = 0; i < ALPHABET_SIZE; i++)
	{
		if (alphabet[i] == searchChar)		//배열에 입력한 문자와 같은게 존재한다면
			++count;		// 갯수를 1씩증가
	}

	printf("\n\n검색 문자 %c의 개수는 %d개 입니다.\n", searchChar, count);

	return 0;
}