/*
	F 또는 f 입력시 : File Menu
	E 또는 e 입력시 : Edit Menu
	H 또는 h 입력시 : Help Menu
	그 밖의 입력시 : Error Menu

	예시)
	메뉴 코드 입력 : H (입력)
	Help Menu
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t4()
{
	char menu;
	printf("메뉴 코드 입력 :");
	if (scanf("%c", &menu) != 1)
	{
		printf("입력 오류입니다.\n");
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