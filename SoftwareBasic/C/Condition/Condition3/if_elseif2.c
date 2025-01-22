#include <stdio.h>

int main_t2()
{
	int num = 30;

	if (num == 10)
		printf("10입니다. \n");
	else if (num == 20)			// else인 상태에서 조건식 지정 
		printf("20입니다. \n");
	else 
		printf("10도 20도 아닙니다. \n");

	return 0;
}