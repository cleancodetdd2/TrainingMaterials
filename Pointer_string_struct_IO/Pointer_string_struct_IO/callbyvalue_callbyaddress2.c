#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void toUpperCase(char* p);

int main()
{
	char ch;
	printf("���ĺ� �ҹ� �Է� : ");
	if (scanf("%c", &ch) != 1) {
		printf("�Է� �����Դϴ�.\n");
		return 1;
	}
	while (getchar() != '\n');

	toUpperCase(&ch);
	printf("����� %c�Դϴ�.\n", ch);

	return 0;
}

void toUpperCase(char* p) {
	if (*p >= 'a' && *p <= 'z')
		*p -= 32;
}