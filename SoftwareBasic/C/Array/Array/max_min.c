#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i;
	int arr[5];
	int max, min;

	printf("최대값과 최소값 구하기\n\n");

	for (i = 0; i < 5; i++)
	{
		printf("입력 %d : ", i + 1);
		if(scanf("%d", &arr[i]) != 1) {
			printf("입력 오류입니다\n");
			return 1;
		}
	}

	max = min = arr[0];	// 첫번째 값을 최댓값과 최소값으로 초기화 함 

	for (i = 1; i < 5; i++)
	{
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
	}

	printf("\n최댓값 : %d\n", max);
	printf("최솟값 : %d\n", min);

	return 0;
}