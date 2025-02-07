#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>		// rand(), srand(), malloc(), free()
#include <time.h>		// time()

int main()
{
	int alphCnt, i;
	char* lettes;

	//����� �Է�
	printf("�빮�� ���� �Է� : ");
	if (scanf("%d", &alphCnt) != 1 || alphCnt <= 0) {
		printf("�Է� ���� : �ùٸ� ����� �Է��ϼ���.\n");
		return 1;
	}

	//���� �޸� �Ҵ�
	lettes = (char*)malloc(sizeof(char) * alphCnt);
	if (lettes == NULL) {
		printf("�޸� �Ҵ� ����\n");
		return 1;
	}

	//���� �õ� ����
	srand(time(NULL));

	//������ �빮�� ���� 
	for (i = 0; i < alphCnt; i++)
		lettes[i] = (rand() % 26) + 'A';	// 'A' ~ 'Z' �Ҵ�

	//���
	printf("\n������ ���� �빮�� : ");
	for (i = 0; i < alphCnt; i++)
		printf("%c ", lettes[i]);
	printf("\n");

	// ���� �޸� ����
	free(lettes);
	lettes = NULL;
	printf("�޸� ���� �Ϸ�\n");

	return 0;
}
