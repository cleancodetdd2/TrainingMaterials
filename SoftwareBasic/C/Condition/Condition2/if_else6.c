#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
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
	else 
	{
		printf("�Է��� ���ڴ� �ҹ��ڰ� �ƴմϴ�\n");
	}
	return 0;
}