// ũ�Ⱑ 100�� MegaIT�迭�� �����ϰ� �빮�ڷ� �ʱ�ȭ�Ͽ� �����Ͻÿ�.

#define _CRT_SECURE_NO_WARNINGS
#define MEGA_IT 100
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	char alphabet[MEGA_IT];
	int i;
	char searchChar;
	int count;

	srand((unsigned int)time(NULL));	// ���� �ð��� �õ�� ���, ���� ������ �ʱ���
	printf("\n\n �빮�ڸ� �����ϰ� 100�� �����ϰ� ����Ͻÿ�\n\n");
	for (i = 0; i < MEGA_IT; i++)
	{
		alphabet[i] = rand() % 26 + 65;		// 65 ~ 90 ���̸� �����ϰ� ���� (A ~ Z ������ �빮��)
		printf("%4c", alphabet[i]);

		if (i % 10 == 9)		// 10��° ���ڸ��� �ٹٲ� 
			puts("");
	}

	do
	{
		printf("\n\n �˻� ���� �Է��ϱ� : ");
		if (scanf("%c", &searchChar) != 1) {
			printf("�Է� �����Դϴ�.\n");
			return 1;
		}
		while (getchar() != '\n');
	} while (searchChar < 'A' || searchChar > 'Z');

	count = 0;
	for (i = 0; i < MEGA_IT; i++)
	{
		if (alphabet[i] == searchChar)
			count++;
	}

	printf("\n\n�˻��� ���� %c�� ������ %d�� �Դϴ�.\n", searchChar, count);

	return 0;
}




