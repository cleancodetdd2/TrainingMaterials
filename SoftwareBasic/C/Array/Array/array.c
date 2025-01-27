#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a[5];
	int i;	//배열의 첨자(인덱스)
	int sum = 0;

	for (i = 0; i < 5; i++)
	{
		printf("%d번째 입력 : ", i + 1);
		if (scanf("%d", &a[i]) != 1) {
			printf("입력 오류 입니다.\n");
			return 1;
		}
		//printf("입력한 값 : a[%d] = %d\n", i, a[i]);
		sum += a[i];		// 누적합 
	}

	printf("5과목의 평균은 %.2f입니다\n", sum / 5.0);

	return 0;
}