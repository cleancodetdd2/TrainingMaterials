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
	printf("%s\n", "apple" + 2); // �ּ�+2���� �ι��� �������� ���	
	printf("%s\n", "apple" + 4); // �ּ�+4���� �ι��� �������� ���	

	return 0;
}