#include <stdio.h>

//함수 선언
void changeVal(int x, int y);
void changeRef(int* p1, int* p2);

int main()
{
	int a = 3, b = 5;
	changeVal(a, b);
	printf("changeVal() 함수 호출 후 %d %d\n", a, b);

	changeRef(&a, &b);
	printf("changeRef() 함수 호출 후 %d %d\n", a, b);
	return 0;
}

// 매개변수 x, y는 복사본을 받음 (원본 무관)
void changeVal(int x, int y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
} // 함수가 종료되면 x와 y는 소멸됨

// 매개변수가 포인터를 통해 원본 변수를 직접 변경
void changeRef(int* p1, int* p2)
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}