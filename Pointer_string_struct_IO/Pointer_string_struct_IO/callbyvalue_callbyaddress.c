/*
	Call by Value - 복사본이 생성되기 때문에 전달 변수에는 영향을 미치지 않음
*/

#include <stdio.h>

void changeVal(int x, int y);
void changeRef(int* p1, int* p2);

int main()
{
	int a = 3, b = 5;

	changeVal(a, b);	// Call by Value
	printf("changeVal함수 호출 후 %d %d\n", a, b);		//값이 안바뀜

	changeRef(&a, &b);	// Call by Address
	printf("changeVal함수 호출 후 %d %d\n", a, b);		//값이 바뀜 

	return 0;
}

void changeVal(int x, int y) {		// a,b 의 복사본 x, y 
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void changeRef(int* p1, int* p2)	// a, b를 가리키고 있는 포인터 p1, p2
{
	int temp;
	temp = *p1;			// p1이 가리키는 값을 temp에 저장
	*p1 = *p2;			// p2가 가리키는 값을 p1이 가리키는 값에 저장 
	*p2 = temp;			// temp를 p2가 가리키고 있는 값에 저장 

}