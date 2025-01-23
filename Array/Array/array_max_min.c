// 5개 정수를 입력받아서 그중 최대값과 최소값을 구하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t3()
{
	int i;
	int arr[5];
	int max, min;

	printf("최대값과 최소값을 구하시오\n");
	for (i = 0; i < 5; i++)
	{
		printf("입력 %d : ", i + 1);
		if (scanf("%d", &arr[i]) != 1) {
			printf("입력 오류입니다.\n");
			return 1;
		}
	}

	max = min = arr[0];		//첫번째 값을 최대값과 최소값으로 초기화 함 
	for (i = 1; i < 5; i++)
	{
		if (max < arr[i])	//arr[i]의 값이 max보다 크다면
		{
			max = arr[i];	//arr[i]의 값이 max가 됨 
		}
		if (min > arr[i])   //arr[i]의 값이 min보다 작다면
		{
			min = arr[i];	//arr[i]의 값이 min이 됨 
		}
	}

	printf("\n===============\n");
	printf("최대값 : %d\n", max);
	printf("최소값 : %d\n", min);

	return 0;
}