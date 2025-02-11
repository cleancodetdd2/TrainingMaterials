#include <stdio.h>

int main()
{
	int arr[2][3] = { {1,2,3}, {4,5,6} };	//2*3배열 초기화

	printf("arr			: %p (배열 자체의 시작 주소)\n", arr);
	printf("arr[0]		: %p (첫 번째 행의 시작 주소)\n", arr[0]);
	printf("&arr[0][0]	: %p (첫 번째 원소의 주소)\n", &arr[0][0]);

	printf("arr[1]		: %p (두 번째 행의 시작 주소)\n", arr[1]);
	printf("&arr[1][0]	: %p (두 번째 행의 첫번째 원소의 주소)\n", &arr[1][0]);
	printf("\n");

	//2차원 배열 각 요소와 주소 출력
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("arr[%d][%d] = %d, Address = %p\n", i, j, arr[i][j], &arr[i][j]);
		}
	}

	//포인터를 이용한 배열 접근
	printf("\n 포인터를 사용한 접근\n");
	int* ptr = &arr[0][0];	//arr의 첫번째 요소의 주소를 가리키는 포인터

	for (int i = 0; i < 6; i++) {
		//포인터 연산을 이용한 접근 *(ptr + i) = arr의 i번째 요소 
		printf("*(ptr + %d) = %d, Address = %p\n", i, *(ptr + i), (ptr + i));
	}
	return 0;
}