#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num, i;
	double total = 0.0;

	//학생 수 입력
	printf("학생 수 입력 : ");
	while (scanf("%d", &num) != 1 || num <= 0) {
		printf("잘못된 입력입니다. 1 이상의 숫자를 입력하세요.\n");
		while (getchar() != '\n');	// 입력 버퍼 비우기 
		printf("학생 수 입력 : ");
	}

	//동적 메모리 할당
	double* height = (double*)malloc(sizeof(double) * num);
	if (height == NULL) {
		printf("동적 메모리 할당 실패\n");
		return 1;
	}
	printf("메모리 할당 성공! (heap area)\n");

	// 학생 키 입력 (범위 검사)
	for (i = 0; i < num; i++) {
		do {
			printf("%d번째 학생 키 입력 (50~250cm) : ", i + 1);
			if (scanf("%lf", &height[i]) != 1) {
				printf("잘못된 입력입니다. 숫자를 입력하세요.\n");
				while (getchar() != '\n');		//입력 버퍼 비우기
				continue;
			}

			if (height[i] < 50.0 || height[i] > 250.0)
				printf("키는 50cm에서 250cm 사이여야 합니다. 다시 입력하세요\n");

		} while (height[i] < 50.0 || height[i] > 250.0);

		total += height[i];	//키 합계
	}

	// 키 평균 계산 및 출력
	printf("\n%d명 학생의 키 평균은 %.2f cm 입니다.\n", num, total / num);

	//메모리 해제
	free(height);
	height = NULL;
	printf("메모리 해제 완료! (heap area)\n");

	return 0;
}