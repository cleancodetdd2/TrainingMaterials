#include <stdio.h>

int main()
{
	int num1 = 5;
	int num2;

	//if (num1)
	//	num2 = 100;
	//else
	//	num2 = 200;

		// 참거짓 판단할 변수
		// ----	
	num2 = num1 ? 100 : 200;
				//---
				//참일때 사용할 값

	printf("%d\n", num2);

	// 함수안에서 삼항 연산자 사용
	printf("%s\n", num1 == 10 ? "10입니다." : "10이 아닙니다.");

	return 0;
}