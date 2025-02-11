#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>		// rand(), srand(), malloc(), free()
#include <time.h>		// time()

int main()
{
	int alphCnt, i;
	char* lettes;

	//사용자 입력
	printf("대문자 개수 입력 : ");
	if (scanf("%d", &alphCnt) != 1 || alphCnt <= 0) {
		printf("입력 오류 : 올바른 양수를 입력하세요.\n");
		return 1;
	}

	//동적 메모리 할당
	lettes = (char*)malloc(sizeof(char) * alphCnt);
	if (lettes == NULL) {
		printf("메모리 할당 실패\n");
		return 1;
	}

	//랜덤 시드 설정
	srand(time(NULL));

	//랜덤한 대문자 저장 
	for (i = 0; i < alphCnt; i++)
		lettes[i] = (rand() % 26) + 'A';	// 'A' ~ 'Z' 할당

	//출력
	printf("\n생성된 랜덤 대문자 : ");
	for (i = 0; i < alphCnt; i++)
		printf("%c ", lettes[i]);
	printf("\n");

	// 동적 메모리 해제
	free(lettes);
	lettes = NULL;
	printf("메모리 해제 완료\n");

	return 0;
}
