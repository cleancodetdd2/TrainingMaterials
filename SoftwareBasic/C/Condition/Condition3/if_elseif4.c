/*
	F �Ǵ� f �Է½� : File Menu
	E �Ǵ� e �Է½� : Edit Menu
	H �Ǵ� h �Է½� : Help Menu
	�� ���� �Է½� : Error Menu

	����)
	�޴� �ڵ� �Է� : H (�Է�)
	Help Menu
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t4()
{
	char menu;
	printf("�޴� �ڵ� �Է� :");
	if (scanf("%c", &menu) != 1)
	{
		printf("�Է� �����Դϴ�.\n");
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