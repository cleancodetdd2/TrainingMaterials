/*
	문자를 입력 받아 아래처럼 메시지를 출력하시오.

	F 또는 f 입력 시 : File Menu
	E 또는 e 입력 시 : Edit Menu
	H 또는 h 입력 시 : Help Menu
	그 밖의 입력 시 : Error Menu
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t7()
{
	char menu;
	printf("메뉴 코드 입력 : ");
	if (scanf("%c", &menu) != 1)
	{
		printf("Erorr\n");
		return 1;
	}

	if (menu == 'F' || menu == 'f')
		printf("File Menu\n");
	else if (menu == 'E' || menu == 'e')
		printf("Edit Menu\n");
	else if (menu == 'H' || menu == 'h')
		printf("Help Menu\n");
	else 
		printf("Error Menu\n");
	return 0;
}