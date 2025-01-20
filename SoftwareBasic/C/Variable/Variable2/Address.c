#include <stdio.h>

int main_t1()
{
	char ch = 'a';
	int n = 1;
	double d = 1.0;

	printf("ch의 주소 : %p\n", &ch);   // &(주소 연산자)로 변수의 메모리 주소 출력
	printf("n의 주소 : %p\n", &n);
	printf("d의 주소 : %p\n", &d);

	return 0;
}