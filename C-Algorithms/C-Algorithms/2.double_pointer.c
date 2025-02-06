#include <stdio.h>

void updateValue(int** ptr)
{
	static int temp = 42;		//정적 변수
	*ptr = &temp;				//이중포인터를 이용하여 값 변경 
}

int main()
{
	int i = 3;
	int* p, ** pp;

	p = &i;
	pp = &p;

	printf("주소 값 확인 : \n");
	printf("i = %d, *p = %d, **pp = %d\n", i, *p, **pp);
	printf("&i = %p, p = %p, *pp = %p\n", (void*)&i, (void*)p, (void*)*pp);
	printf("&p = %p, pp =%p\n", (void*)&p, (void*)pp);

	//이중 포인터를 이용해서 값 변경
	updateValue(&p);
	printf("\n\nupdateValue()호출 후 주소 값 확인 :\n");
	printf("*p = %d, **pp = %d\n", *p, **pp);
	printf("p = %p, *pp = %p\n", (void*)p, (void*)*pp);

	return 0;
}