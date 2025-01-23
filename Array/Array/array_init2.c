// 5개 정수를 입력받아 배열에 초기화 한 후 평균을 출력하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t2()
{
	int arr[5];
	int i;		//배열의 인덱스(첨자)
	int sum = 0;

	for (i = 0; i < 5; i++)
	{
		printf("%d번째 입력 : ", i + 1);
		if (scanf("%d", &arr[i]) != 1) {
			printf("입력 오류입니다.\n");
			return 1;
		}
		//printf("입력한 값 : arr[%d] = %d\n", i, arr[i]);
		sum += arr[i];	// 누적합
	}

	printf("5개 과목의 평균은 %.2f입니다.\n", sum / 5.0);

	return 0;
}