#include <stdio.h>

int main_t2(void) {
	int add = 3 + 7;			// 정수 리터럴
	printf("3 + 7 = %d\n", add);	// 문자열 리터럴 
	printf("%d X %d = %d\n", 30, 100, 30 * 100);
	printf("%f\n", 0.1F);		// 실수 리터럴 소수점 표기법 0.100000
	printf("%f\n", 1.0E-5f);	// 실수 리터럴 지수 표기법  0.000010 
	printf("%c\n", 'a');		// 문자 리터럴 
	return 0;
}