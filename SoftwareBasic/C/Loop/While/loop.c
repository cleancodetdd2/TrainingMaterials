/*
	while 문 : 조건이 만족하면 실행문 수행 
	do~while문 : 일단 실행문 수행한 후, 조건 비교하여 조건이 만족하면
	              실행문 다시 실행.
*/

#include <stdio.h>

int main_t7()
{
	int i;

	printf("while문 실행\n");
	i = 1;
	while (i <= 100)			//조건이 참이면 반복
	{
		printf("%4d", i++);
		//i++;
	}
	printf("\n");

	printf("do while문 실행\n");
	i = 1;
	do
	{
		printf("%4d", i++);
	} while (i <= 100);
	printf("\n");

	printf("for문 실행\n");
	for(i = 1; i <= 100; i++)
		printf("%4d", i);

	return 0;
}