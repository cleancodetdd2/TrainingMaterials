#include <stdio.h>

// void* 포인터를 활용한 범용 출력 함수
void print_value(void* p, char type)
{
	switch (type) {
	case 'i':
		printf("정수 : %d\n", *(int*)p);
		break;
	case 'd':
		printf("실수 : %.2f\n", *(double*)p);
		break;
	case 'c':
		printf("문자 : %c\n", *(char*)p);
		break;
	default:
		printf("지원되지 않는 타입입니다.\n");
	}

}

int main()
{
	void* p;		//범용 포인터 선언

	int i = 42;
	double d = 3.14159;
	char c = 'A';

	p = &i;
	print_value(p, 'i');

	p = &d;
	print_value(p, 'd');

	p = &c;
	print_value(p, 'c');

	// void*를 활용하여 배열처리
	int numbers[] = { 10, 20, 30, 40, 50 };
	p = numbers;		//배열의 첫번째 주소 저장 
	for (int j = 0; j < 5; j++)
		printf("numbers[%d]: %d\n", j, *((int*)p + j));

	return 0;
}