#include <stdio.h>

int main_t3()
{
	int i = 10;
	char c = 'A';
	double d = 2.1;

	//포인터 변수 선언과 초기화 
	int* ip = &i;
	char* cp = &c;
	double* dp = &d;

	//각 포인터에 저장된 값 
	printf("ip = %p\n", ip);
	printf("cp = %p\n", cp);
	printf("dp = %p\n", dp);

	//각 포인터가 가리키는 값 
	printf("ip = %d\n", *ip);
	printf("cp = %d\n", *cp);
	printf("dp = %.2f\n", *dp);

	return 0;
}