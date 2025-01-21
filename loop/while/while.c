#include <stdio.h>

int main_t1()
{
	int i = 1;		//초기식
	// 반복에 사용할 변수 i를 선언하고 0으로 초기화 
	while (i <= 100)	// 한번 반복할때 마다 i를 1씩 증가시킴 
	{				// i가 100보다 작을 때까지만 반복 
		printf("Hello World! %d\n", i);
		i++;		//증감식
	}
	return 0;
}