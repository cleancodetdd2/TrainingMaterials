#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>		// srand, rand() �Լ��� ����� ���
#include <time.h>		// time �Լ��� ����� ��� 

int main()
{
	int answer, in;
	int i;
	char conti;

	srand((unsigned int)time(NULL));

	do
	{	
		system("cls");		//ȭ�� ����� 
		answer = rand() % 100 + 1;	//1~100���� ���� ����
		printf("\n���� ���߱� ������ �غ��Ƿ���?\n\n");

		for (i = 1; i <= 5; i++)	//5���� �Է� ��ȸ
		{
			printf("\n[%d��° ����]\n", i);
			printf("1~100 �Է� : [   ]\b\b\b\b");
			if (scanf("%d", &in) != 1)
			{
				printf("��ȿ���� ���� �Է��Դϴ�. ���ڸ� �Է��ϼ���.\n");
				while (getchar() != '\n');	//���ۿ��� ���ͱ��� �о�� (���۸� ���)
				i--;	// ���� ���߱� ���� ��ȸ ����
				continue;
			}
			while (getchar() != '\n');  //���ۿ��� ���ͱ��� �о�� (���۸� ���)

			if (answer > in)  // 80 > 50
				printf("������ %d���� ū���Դϴ�.\n", in);
			else if (answer < in)	// 80 <  90
				printf("������ %d���� �������Դϴ�.\n", in);
			else
			{
				printf("�����Դϴ�. ��ī�մϴ�.\n");
				break;
			}
		}

		if (i == 6)
		{
			printf("\n\n5���� ������ȸ�� ��� �����߽��ϴ�.\n");
			printf("������ [%d]�Դϴ�.\n", answer);
		}

		printf("\n\n���� �ѹ� ��(�ƹ�Ű) / ����(Q/q)");
		conti = getchar();
		
	} while (conti != 'Q' && conti != 'q');

	return 0;
}