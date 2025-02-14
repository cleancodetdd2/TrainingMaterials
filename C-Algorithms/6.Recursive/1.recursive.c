#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//재귀 함수 : 1 부터 n까지 출력
void recursive(int n) {
	if (n == 0)		// 재귀 종료 조건
		return;

	recursive(n - 1);	// 재귀 호출 (n-1을 인자로 전달)
	printf("%d\n", n);	// 현재 n 출력
}

int main()
{
	int num;
	printf("출력할 숫자를 입력하세요: ");
	if (scanf("%d", &num) != 1) {
		printf("유효한 숫자를 입력하세요.\n");
		return 1;
	}

	if (num < 1) {
		printf("1 이상의 숫자를 입력하세요.\n");
		return 1;
	}

	printf("1부터 %d까지 출력 : \n", num);
	recursive(num);		// 재귀 함수

	return 0;
}
