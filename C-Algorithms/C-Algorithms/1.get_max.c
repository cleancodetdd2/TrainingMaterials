#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_ELEMENTS 100	//�ִ� �л��� 

// �л� ������ ������ �迭 (�ڷ� ����)
int scores[MAX_ELEMENTS];

// �ִ� ������ ã�� �Լ� (�˰���)
int get_max_score(int n)
{
	int i, largest;

	//if (n <= 0) return -1;		//����ó��

	largest = scores[0];		//ù��° ������ �ִ밪���� �ʱ�ȭ 
	for (i = 1; i < n; i++) {	//�迭�� ��ȸ�ϸ鼭 �ִ밪 ã��
		if (scores[i] > largest)
			largest = scores[i];
	}

	return largest;		//�ִ� ���� ��ȯ 
}

int main()
{
	int i, n, max_score;

	printf("�л� ���� �Է��ϼ��� (�ִ� %d��): ", MAX_ELEMENTS);
	if (scanf("%d", &n) != 1) {
		printf("�Է� �����Դϴ�.\n");
		return 1;
	}

	if (n <= 0 || n > MAX_ELEMENTS) {
		printf("�߸��� �л� ���Դϴ�\n");
		return 1;
	}

	//�л� ���� �Է�
	printf("�� �л��� ������ �Է��ϼ���\n");
	for (i = 0; i < n; i++) {
		printf("�л� %d: ", i + 1);
		scanf("%d", &scores[i]);
	}

	max_score = get_max_score(n);

	printf("�ְ� ������ %d�� �Դϴ�.\n", max_score);

	return 0;
}