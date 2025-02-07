#include <stdio.h>

int main()
{
	int arr[2][3] = { {1,2,3}, {4,5,6} };	//2*3�迭 �ʱ�ȭ

	printf("arr			: %p (�迭 ��ü�� ���� �ּ�)\n", arr);
	printf("arr[0]		: %p (ù ��° ���� ���� �ּ�)\n", arr[0]);
	printf("&arr[0][0]	: %p (ù ��° ������ �ּ�)\n", &arr[0][0]);

	printf("arr[1]		: %p (�� ��° ���� ���� �ּ�)\n", arr[1]);
	printf("&arr[1][0]	: %p (�� ��° ���� ù��° ������ �ּ�)\n", &arr[1][0]);
	printf("\n");

	//2���� �迭 �� ��ҿ� �ּ� ���
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("arr[%d][%d] = %d, Address = %p\n", i, j, arr[i][j], &arr[i][j]);
		}
	}

	//�����͸� �̿��� �迭 ����
	printf("\n �����͸� ����� ����\n");
	int* ptr = &arr[0][0];	//arr�� ù��° ����� �ּҸ� ����Ű�� ������

	for (int i = 0; i < 6; i++) {
		//������ ������ �̿��� ���� *(ptr + i) = arr�� i��° ��� 
		printf("*(ptr + %d) = %d, Address = %p\n", i, *(ptr + i), (ptr + i));
	}
	return 0;
}