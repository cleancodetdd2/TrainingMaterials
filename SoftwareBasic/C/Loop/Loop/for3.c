/* 1~100 에서의 2의 배수 합을 출력하시오 
   1~100 에서의 2의 배수 개수를 출력하시오	
*/
#include <stdio.h>

int main_t3()
{
	int i, sum = 0, count = 0;

	for (i = 2; i <= 100; i += 2)		//초기값 2부터 100까지 2씩 증가
	{
		printf("%d ", i);
		sum += i;	// 2의 배수 합계
		count++;	// 2의 배수 개수
	}

	printf("\n\n1부터 100까지의 2의 배수 합계: %d\n", sum);
	printf("1부터 100까지의 2의 배수 개수: %d\n", count);
	return 0;
}