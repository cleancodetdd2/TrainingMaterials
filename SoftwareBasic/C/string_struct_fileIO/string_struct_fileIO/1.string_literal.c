#include <stdio.h>

int main()
{
	char* str = "Hello World";
	printf("%s\n", str);
	printf("%c\n", str[1]);
	printf("%c\n", str[4]);
	printf("%c\n", str[8]);
	printf("\n");

	printf("%s\n", "apple");
	printf("%s\n", "apple" + 2); // 주소+2부터 널문자 이전까지 출력	
	printf("%s\n", "apple" + 4); // 주소+4부터 널문자 이전까지 출력	

	return 0;
}