#include <stdio.h>

int main_t4()
{
	/*
	배열 이름 => (배열의 시작주소만을 가리킬수 있는) 포인터 상수
	포인터 => 포인터 변수
	*/
	int* p, a[5] = { 10, 20,30, 40, 50 };

	p = a;

	printf("%p\n", a);
	printf("%d\n", *p);
	printf("%d\n", *(p+1));
	printf("%d\n", p[2]);
	printf("%d\n\n", *(a + 2));

	p = p + 2;
	//a = a + 2;	// 배열 이름은 상수이기 때문에 변경 불가함 

	p = a + 2;
	//a = p + 2;    // 배열 이름은 상수이기 때문에 변경 불가함 

	printf("%p\n", a);
	printf("%d\n", *p);
	printf("%d\n", *(p + 2));
	printf("%d\n", *(p - 1));
	printf("%d\n", *p + 2);

	return 0;
}