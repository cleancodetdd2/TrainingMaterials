#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main_t1()
{
	char input;
	printf("���ĺ� ���ڸ� �Է��ϼ���: ");
	if (scanf("%c", &input) != 1) {
		printf("�Է� ������ �߻��߽��ϴ�.\n");
		return 1;		//���� �߻��� ���α׷� ����
	}

	if (input >= 'a' && input <= 'z') {  //�Է��� �ҹ������� Ȯ��
		char uppercase = input - ('a' - 'A');
		printf("��ȯ�� ����: %c\n", uppercase);
	}
	else if (input >= 'A' && input <= 'Z') {  //�Է��� �빮������ Ȯ��
		char lowercase = input + ('a' - 'A');
		printf("��ȯ�� ����: %c\n", lowercase);
	}
	else {
		printf("�Է��� ���ڴ� ���ĺ��� �ƴմϴ�.\n");
	}

	return 0;
}