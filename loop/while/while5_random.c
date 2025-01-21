#include <stdio.h>
#include <stdlib.h>		// srand, rand() 함수가 선언된 헤더
#include <time.h>		// time 함수가 선언된 헤더 

int main_t5()
{
	srand(time(NULL));  // 현재 시간을 기준으로 난수 시드 값을 다르게 설정됨

	int i = 0;
	while (i != 3) {		// i가 3이 아닐 동안 계속 반복
		i = rand() % 10;	// 무작위로 정수를 생성된 뒤 10 미만의 숫자로 만듦
		printf("%d\n", i);
	}

	return 0;
}
