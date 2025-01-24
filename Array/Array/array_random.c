// 크기가 100인 MegaIT배열에 랜덤하게 대문자로 초기화하여 저장하시오.

#define _CRT_SECURE_NO_WARNINGS
#define MEGA_IT 100
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	char alphabet[MEGA_IT];
	int i;
	char searchChar;
	int count;

	srand((unsigned int)time(NULL));	// 현재 시간을 시드로 사용, 난수 생성기 초기함
	printf("\n\n 대문자를 랜덤하게 100개 저장하고 출력하시오\n\n");
	for (i = 0; i < MEGA_IT; i++)
	{
		alphabet[i] = rand() % 26 + 65;		// 65 ~ 90 사이를 래덤하게 저장 (A ~ Z 랜덤한 대문자)
		printf("%4c", alphabet[i]);

		if (i % 10 == 9)		// 10번째 숫자마다 줄바꿈 
			puts("");
	}

	do
	{
		printf("\n\n 검색 문자 입력하기 : ");
		if (scanf("%c", &searchChar) != 1) {
			printf("입력 오류입니다.\n");
			return 1;
		}
		while (getchar() != '\n');
	} while (searchChar < 'A' || searchChar > 'Z');

	count = 0;
	for (i = 0; i < MEGA_IT; i++)
	{
		if (alphabet[i] == searchChar)
			count++;
	}

	printf("\n\n검색한 문자 %c의 개수는 %d개 입니다.\n", searchChar, count);

	return 0;
}




