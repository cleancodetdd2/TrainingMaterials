/*
	void*
		- 범용 포인터
		- 포인터 타입(char*, int*, double*)이 다양하게 존재하는데
		  ISO C에서 포인터 출력할 때 %p는 void* 타입의 포인터를 권장함.
			- 경고 또는 동작이 정의되지 않을 수 도 있음.
	
*/
#include <stdio.h>

int main()
{
	char c = 'a';
	int i = 3;
	double d = 3.14;

	char* cp = &c;
	int* ip = &i;
	double* dp = &d;

	printf("%p %p %p\n", (void*)cp, (void*)ip, (void*)dp);
	cp++; ip++; dp++;
	printf("%p %p %p\n", (void*)cp, (void*)ip, (void*)dp);

	return 0;
}