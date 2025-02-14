#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 구구단 3단을 재귀함수로 구현
void printMultiplicatineTable(int num) {
	if (num == 0) {
		printf("재귀 함수 종료\n\n");
		return;
	}

	printMultiplicatineTable(num - 1);	// 재귀호출(num을 감소시키면서 실행)
	printf("3 * %d = %d\n", num, 3 * num);	// 현재 숫자와 3을 곱한 결과 출력
		
}

int main()
{
	int num;

	printf("출력할 최대 곱셈 값을 입력하세요 (예: 7): ");
	if (scanf("%d", &num) != 1) {
		printf("유효한 숫자를 입력하세요.\n");
		return 1;
	}

	if (num < 1) {
		printf("1 이상의 숫자를 입력하세요.\n");
		return 1;
	}

	printf("3단 구구단 출력\n");
	printMultiplicatineTable(num);	//재귀 함수 호출 

	return 0;
}