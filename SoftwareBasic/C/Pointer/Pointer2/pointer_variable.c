#include <stdio.h>

int main()
{
	int i = 10;
	char c = 'A';
	double d = 2.1;

	//포인터 변수 선언
	int* ip;
	char* cp;
	double* dp;

	//변수의 주소값을 포인터에 대입
	ip = &i;
	cp = &c;
	dp = &d;

	//일반변수의 크기
	printf("i = %zu바이트\n", sizeof(i));
	printf("c = %zu바이트\n", sizeof(c));
	printf("d = %zu바이트\n", sizeof(d));

	//각 포인터의 크기
	printf("\nip = %zu바이트\n", sizeof(ip));
	printf("cp = %zu바이트\n", sizeof(cp));
	printf("dp = %zu바이트\n", sizeof(dp));

	return 0;
}