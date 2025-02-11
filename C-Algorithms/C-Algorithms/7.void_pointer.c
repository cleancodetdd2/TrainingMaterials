#include <stdio.h>

int main()
{
	void* p;		//어떤 타입의 주소라도 가리킬수 있는 포인터

	int i = 10;
	double d = 3.14;

	p = &i;			// int형 주소를 저장
	//printf("%d\n", *p);	//(컴파일오류-역참조 연산자 사용 불가)
	printf("%d\n", *(int*)p);  //형변환 후 간접접근 가능 

	p = &d;			// double형 주소를 저장
	printf("%.2f\n", *(double*)p);	//형변환 후 간접접근 가능

	return 0;
}