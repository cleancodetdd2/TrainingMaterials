/*
	정수를 입력받아서
	양수이면 양의 정수 출력
	음수이면 양의 정수로 변환해서 출력

	예) 아ㅣㄴ렁니 (입력)
	    입력 오류 발생했습니다.

		5 (입력)
		결과는 5입니다.

		-10 (입력)
		음의 정수를 양의 정수로 변환했습니다.
		결과는 10입니다.

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t11()
{
	int n;
	if (scanf("%d", &n) != 1)
	{
		printf("입력 오류 발생했습니다.\n");
		return 1;
	}

	if (n < 0)
	{
		//n = n * -1;
		n *= -1;
		printf("음의 정수를 양의 정수로 변환했습니다.\n");
	}

	printf("\n결과는 %d입니다.\n", n);
	return 0;

}
