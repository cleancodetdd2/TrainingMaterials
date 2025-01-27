/*
	rand() % 26 = 0 ==> 0 + 65 = 65 ==> 'A'
	rand() % 26 = 1 ==> 1 + 65 = 66 ==> 'B'
	....
	rand() % 26 = 25 ==> 25 + 65 = 90 ==> 'Z'
*/

#define _CRT_SECURE_NO_WARNINGS
#define ALPHABET_SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	char alphabet[ALPHABET_SIZE];
	int i;
	char searchChar;
	int count;

	srand((unsigned int)time(NULL)); //���� �ð��� �õ�� ����Ͽ� ���� ������ �ʱ�ȭ
	printf("\n\n �빮�ڸ� �����ϰ� 100�� ���� \n\n");
	for (i = 0; i < ALPHABET_SIZE; i++)
	{
		alphabet[i] = rand() % 26 + 65;   // A ~ Z ���� �빮�� �ʱ�ȭ 
		printf("%4c", alphabet[i]);

		if (i % 10 == 9)
			printf("\n");
	}

	do
	{
		printf("\n\n�˻� ���� �Է� : ");
		if (scanf("%c", &searchChar) != 1) {
			printf("�Է� �����Դϴ�.");
			return 1;
		}
		while (getchar() != '\n');
	} while (searchChar < 'A' || searchChar > 'Z');

	count = 0;
	for (i = 0; i < ALPHABET_SIZE; i++)
	{
		if (alphabet[i] == searchChar)		//�迭�� �Է��� ���ڿ� ������ �����Ѵٸ�
			++count;		// ������ 1������
	}

	printf("\n\n�˻� ���� %c�� ������ %d�� �Դϴ�.\n", searchChar, count);

	return 0;
}