#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char ch;
	printf("���� �Է� :");
	if (scanf("%c", &ch) != 1)
	{
		printf("�Է� ����\n");
		return 1;
	}

	if (ch >= 'a' && ch <= 'z')		// �ҹ����� ���
		ch -= 32;					// �빮�ڷ� ��ȯ

	switch (ch)
	{
	case 'A': case 'E': case 'I': case 'O': case 'U':
		printf("�����Դϴ�.\n");
		break;
	default:
		if (ch >= 'A' && ch <= 'Z')
			printf("�����Դϴ�.\n");
		else
			printf("���ĺ��� �ƴմϴ�.\n");
	}
	return 0;
}