/*
	���ڸ� �Է��ϼ���:  a (�Է�)
	��ȯ�� ���ڴ� A

	���ڸ� �Է��ϼ���:  A (�Է�)
	��ȯ�� ���ڴ� c

	���ڸ� �Է��ϼ���:  ! (�Է�)
	�Է��� ���ڴ� ���ĺ��� �ƴմϴ�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t3()
{
	char input;

	printf("�ҹ��ڸ� �Է��ϼ���: ");
	if (scanf("%c", &input) != 1) {
		printf("�Է� ������ �߻��߽��ϴ�.\n");
		return 1;	// ���� �߻��� ���α׷� ����
	}

	if (input >= 'a' && input <= 'z')	//�Է��� �ҹ������� Ȯ��
	{
		char uppercase = input - ('a' - 'A');	// �ҹ��ڸ� �빮�ڷ� ��ȯ
		printf("�빮�� : %c\n", uppercase);
	}
	else if (input >= 'A' && input <= 'Z')  
	{
		char lowercase = input + ('a' - 'A');   // �빮�ڸ� �ҹ��ڷ� ��ȯ
		printf("�ҹ��� : %c\n", lowercase);
	}
	else
	{
		printf("�Է��� ���ڴ� ���ĺ��� �ƴմϴ�\n");
	}
	return 0;
}