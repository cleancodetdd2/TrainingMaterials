/*
	���ڸ� �Է� �޾� �Ʒ�ó�� �޽����� ����Ͻÿ�.

	F �Ǵ� f �Է� �� : File Menu
	E �Ǵ� e �Է� �� : Edit Menu
	H �Ǵ� h �Է� �� : Help Menu
	�� ���� �Է� �� : Error Menu
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t7()
{
	char menu;
	printf("�޴� �ڵ� �Է� : ");
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