#include <stdio.h>
#include <string.h>

// ���ڿ� �迭�� ����ϴ� �Լ�
void display(const char* stringArray[], int size)
{
	for (int i = 0; i < size; i++)		//�迭 ũ�⸸ŭ �ݺ�
	{
		printf("String: %s\n", stringArray[i]);		//���ڿ� ���
		int length = strlen(stringArray[i]);		//���ڿ� ���� ���
		//ù��° ���� ���
		printf("1st character => %c\n", stringArray[i][0]);
		//����° ���� ���(���ڿ� ���� üũ �� ó��)
		printf("3rd character => %c\n", (length > 2) ? stringArray[i][2] : "(N/A)");
		//������ ���� ���
		printf("Last character => %c\n\n", stringArray[i][length - 1]);

	}
}

int main()
{
	//���ڿ� ���ͷ��� �����ϴ� �迭
	const char* words[] = { "Korea", "China", "Taiwan", "Netherlands", "America" };

	//�迭 ũ��(�迭�� ���� ����) -- ��ü �迭 ũ�⸦ ���� ��� ũ��� ����
	int size = sizeof(words) / sizeof(words[0]);

	//���ڿ� �迭 ó��(���)
	display(words, size);

	return 0;
}