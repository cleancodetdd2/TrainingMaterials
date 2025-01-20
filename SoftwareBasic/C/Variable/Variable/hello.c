/* 첫 번째 프로그램*/
#include <stdio.h>		// 전처리기 (컴파일러에 명시한 파일을 먼저 참조하라고 지시)

int main_t1()				// main 함수 (프로그램의 시작이므로 반드시 정의) 
{
	printf("Hello, world!\n");	//문장을 완료하는 세미콜론 (함수 호출)
								// \n : 줄바꿈을 하는 역할 
	printf("%s\n", "Hello, C!");
	return 0;
}