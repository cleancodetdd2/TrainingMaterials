#include <stdio.h>

int main()
{
	char str[] = "apple";	//배열을 이용하여 문자열 처리
	char* sp = "straberry";	//포인터를 이용하여 문자열 처리 
	int i;

	printf("%s\n", str);
	printf("%s\n", sp);

	for (i = 0; str[i] != '\0'; i++)		//널문자 이전까지
		str[i] -= 32;		//대문자로 변환 => 배열은 수정 가능 

	printf("\n%s\n", str);

	for (i = 0; sp[i] != '\0'; i++)
		sp[i] -= 32;		//대문자로 변환안됨 => 포인터는 수정 불가능

	printf("%s\n", sp);

	return 0;
}
