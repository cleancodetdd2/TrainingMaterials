#include <stdio.h>
#include <stdlib.h>		// rand(), srand()
#include <time.h>		// time()

int main_t4()
{
	srand(time(NULL));

	int i = 0;
	while (i != 3)		// 3이 아닐 때 계속 반복 
	{
		// rand()함수 사용하여 무작위 정수 생성한뒤 1~10까지의 숫자로 만듦
		i = rand() % 10 + 1;	
		printf("%d\n", i);
	}

	return 0;
}