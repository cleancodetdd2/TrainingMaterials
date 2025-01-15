#include <stdio.h>

int main_t1(void) 
{
	char ch = 'a';
	int n = 1;
	double d = 1.0;

	printf("ch 변수의 주소 = %p\n", &ch);
	printf("n 변수의 주소 = %p\n", &n);
	printf("d 변수의 주소 = %p\n", &d);
	return 0;
}