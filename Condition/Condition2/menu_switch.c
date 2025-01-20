#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char menu;
	printf("메뉴 코드 입력 : ");
	if (scanf("%c", &menu) != 1)
	{
		printf("Erorr\n");
		return 1;
	}

	if (menu >= 'a' && menu <= 'z')
		menu -= 32;

	switch (menu)
	{
	case 'F':
		printf("File Menu\n");
		break;
	case 'H':
		printf("Help Menu\n");
		break;
	case 'E':
		printf("Edit Menu\n");
		break;
	default:
		printf("Error Menu\n");
		break;
	}

	return 0;
}