/*
	- 문자열 상수
		- 문자열 상수가 저장된 시작주소 값을 가지고 있음 
*/

#include <stdio.h>

int main()
{
	printf("%s\n", "apple");
	printf("%s\n", "apple" + 2);  //주소+2부터 널문자 이전까지 출력
	printf("%s\n", "apple" + 4);
	return 0;
}