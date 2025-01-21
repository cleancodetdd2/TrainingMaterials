#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>		// srand, rand() 함수가 선언된 헤더
#include <time.h>		// time 함수가 선언된 헤더 

int main()
{
	int answer, in;
	int i;
	char conti;

	srand((unsigned int)time(NULL));

	do
	{	
		system("cls");		//화면 지우기 
		answer = rand() % 100 + 1;	//1~100사이 숫자 생성
		printf("\n숫자 맞추기 게임을 해보실래요?\n\n");

		for (i = 1; i <= 5; i++)	//5번의 입력 기회
		{
			printf("\n[%d번째 도전]\n", i);
			printf("1~100 입력 : [   ]\b\b\b\b");
			if (scanf("%d", &in) != 1)
			{
				printf("유효하지 않은 입력입니다. 숫자를 입력하세요.\n");
				while (getchar() != '\n');	//버퍼에서 엔터까지 읽어옴 (버퍼를 비움)
				i--;	// 숫자 맞추기 도전 기회 복구
				continue;
			}
			while (getchar() != '\n');  //버퍼에서 엔터까지 읽어옴 (버퍼를 비움)

			if (answer > in)  // 80 > 50
				printf("정답은 %d보다 큰수입니다.\n", in);
			else if (answer < in)	// 80 <  90
				printf("정답은 %d보다 작은수입니다.\n", in);
			else
			{
				printf("정답입니다. 추카합니다.\n");
				break;
			}
		}

		if (i == 6)
		{
			printf("\n\n5번의 도전기회를 모두 소진했습니다.\n");
			printf("정답은 [%d]입니다.\n", answer);
		}

		printf("\n\n도전 한번 더(아무키) / 종료(Q/q)");
		conti = getchar();
		
	} while (conti != 'Q' && conti != 'q');

	return 0;
}