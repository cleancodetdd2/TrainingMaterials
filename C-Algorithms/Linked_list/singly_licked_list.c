#define _CRT_SECURE_NO_WARNINGS
#include "myHeader.h"

int main() {

	int choice, data, pos;

	while (1) {
		//�޴� ���
		printf("\n--------------------------------\n");
		printf("\n ���� ����Ʈ �޴�(���) \n");
		printf("\n--------------------------------\n");
		printf("1. �տ� ����\n ");
		printf("2. �ڿ� ����\n ");
		printf("3. Ư�� ��ġ�� ����\n");
		printf("4. ù ��° ��� ����");
		printf("5. ������ ��� ����");
		printf("6. Ư�� ��ġ�� ��� ����\n");
		printf("7. Ư�� ���� ���� ��� ����\n");
		printf("8. ����Ʈ ���\n ");

		printf(" 0. ���α׷� ����\n");
		printf("\n--------------------------------\n");

		//����� �Է� �ޱ�
		printf("�޴� ���� : ");
		if (scanf("%d", &choice) != 1) {
			printf("�߸��� �Է��Դϴ�. ���ڸ� �Է��ϼ���.\n");
			clearBuffer();
			continue;
		}

		//clearBuffer();

		switch (choice) {
		case 1:		// ����Ʈ �տ� ����
			printf("������ �� �Է� : ");
			if (scanf("%d", &data) != 1) {
				printf("�߸��� �Է��Դϴ�. ���ڸ� �Է��ϼ���.\n");
				clearBuffer();
				break;
			}
			//clearBuffer();
			insertFront(data);
			printf("��尡 ����Ʈ �Ǿտ� ���ԵǾ����ϴ�.\n");
			break;

		case 8:		// ����Ʈ ���
			traverseList();
			break;

		case 0:
			clearList();		// ���α׷� ���� �� �޸� ���� ����
			printf("���α׷��� �����մϴ�.\n");
			return 0;

		default:
			printf("�߸��� �Է��Դϴ�. �޴��� �ִ� ��ȣ�� �Է��ϼ���.\n");
		}

	}

	//return 0;
}