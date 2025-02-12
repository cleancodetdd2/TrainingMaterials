#define _CRT_SECURE_NO_WARNINGS
#include "myHeader.h"

int main() {

	int choice, data, pos;

	while (1) {
		//�޴� ���
		printf("\n--------------------------------\n");
		printf("\n ���� ����Ʈ �޴�(���) \n");
		printf("\n--------------------------------\n");
		printf("1. �տ� ����\n");
		printf("2. �ڿ� ����\n");
		printf("3. Ư�� ��ġ�� ����\n");
		printf("4. ù ��° ��� ����\n");
		printf("5. ������ ��� ����\n");
		printf("6. Ư�� ��ġ�� ��� ����\n");
		printf("7. Ư�� ���� ���� ��� ����\n");
		printf("8. ����Ʈ ���\n");

		printf("0. ���α׷� ����\n");
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

		case 2:	// ����Ʈ �ǵڿ� ����
			printf("������ �� �Է�: ");
			if (scanf("%d", &data) != 1) {
				printf("�߸��� �Է��Դϴ�. ���ڸ� �Է��ϼ���.\n");
				clearBuffer();
				break;
			}
			//clearBuffer();
			insertRear(data);
			printf("��尡 ����Ʈ �ڿ� ���ԵǾ����ϴ�.\n");
			break;

		case 3:
			printf("������ �� �Է�: ");
			if (scanf("%d", &data) != 1) {
				printf("�߸��� �Է��Դϴ�. ���ڸ� �Է��ϼ���.\n");
				clearBuffer();
				break;
			}
			//clearBuffer();

			printf("������ ��ġ �Է� (1���� ����): ");
			if (scanf("%d", &pos) != 1) {
				printf("�߸��� �Է��Դϴ�. ���ڸ� �Է��ϼ���.\n");
				clearBuffer();
				break;
			}
			//clearBuffer();
			insertAt(data, pos);
			printf("��尡 %d��° ��ġ�� ���ԵǾ����ϴ�.\n", pos);
			break;

		case 4:		// ù ��° ��� ����
			if (removeFront())
				printf("ù ��° ��尡 �����Ǿ����ϴ�.\n");
			else
				printf("������ ��尡 �����ϴ�.\n");
			break;

		case 5:		// ������ ��� ����
			if (removeRear())
				printf("������ ��尡 �����Ǿ����ϴ�.\n");
			else 
				printf("������ ��尡 �����ϴ�.\n");
			break;

		case 6:		// Ư�� ��ġ�� ��� ����
			printf("������ ��ġ �Է� (1���� ����): ");
			if (scanf("%d", &pos) != 1) {
				printf("�߸��� �Է��Դϴ�. ���ڸ� �Է��ϼ���.\n");
				clearBuffer();
				break;
			}
			//clearBuffer();

			if (removeAt(pos))
				printf("%d��° ��ġ�� ��尡 �����Ǿ����ϴ�.\n", pos);
			else
				printf("������ ��尡 ���ų� �߸��� ��ġ�Դϴ�.\n");
			break;

		case 7:		// Ư�� ���� ���� ��� ����
			printf("������ �� �Է� : ");
			if (scanf("%d", &data) != 1) {
				printf("�߸��� �Է��Դϴ�. ���ڸ� �Է��ϼ���.\n");
				clearBuffer();
				break;
			}
			//clearBuffer();

			if (removeByValue(data))
				printf("%d ���� ���� ��尡 �����Ǿ����ϴ�.\n", data);
			else
				printf("�ش� ���� ���� ��尡 �����ϴ�.\n");
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