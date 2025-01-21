/*
	정수를 입력받아서 양수라면 양수로 출력하고
	음수라면 양수로 변환해서 출력하시오.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num;
	printf("정수 입력 : ");
	if (scanf("%d", &num) != 1) {
		printf("입력 오류 발생했습니다.");
		return 1;
	}

	if (num < 0)	// 만약에 음의 정수라면 
	{
		num *= -1;			// num = num * -1
		printf("음수를 양수로 변환 했습니다.");
	}

	printf("\n결과는 %d입니다.\n", num);
	return 0;
}
