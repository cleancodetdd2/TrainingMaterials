/*
	정렬
		- 알고리즘을 이해하는데 첫 단계라 할수 있음.
		- 종류
			- 버블 정렬, 선택 정렬, 삽입 정렬
				- 구현이 쉽고 작은 데이터 집합에 적합
				- 큰 데이터는 비효율적임
			- 병합 정렬, 퀵 정렬, 힙 정렬
				- 큰 데이터를 정렬하는데 적합
				- 작은 데이터 정렬에는 과함 

	버블 정렬
		- 서로 인접한 두 요소를 비교하여 정렬하는 알고리즘 
		- 인접한 2개의 요소를 비교해서 교환함 
		- 일반적으로 데이터의 교환이 이동 작업보다 복잡함 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(const int* arr, int size);

static inline void swap(int* x, int* y) {
	int temp = *x;	// 임시변수에 x 저장
	*x = *y;		// x에 y 값을 대입 
	*y = temp;		// y에 임시 변수 값 대입 
}

//개선된 버블 정렬
void optimizedBubbleSort(int* arr, int size) {
	int swapped;
	for (int i = 0; i < size - 1; i++) {
		swapped = 0;		// 정렬 여부 체크 
		for (int j = 0; j < size - 1; j++) {	
			if (arr[j] > arr[j + 1]) {			// 인접한 두 값 비교 
				printf("교환: %d <-> %d\n", arr[j], arr[j + 1]);	//교환된 값 출력
				swap(&arr[j], &arr[j + 1]);		// 값 교환 
				swapped = 1;					// 교환 발생 표시 
			}
		}
		//교환이 없으면 정렬 완료
		if (!swapped) break;
		// 현재 정렬 단계에서 배열 상태 출력
		printf("패스 %d 후 배열 상태 : ", i + 1);
		printArray(arr, size);
	}
}

//랜덤 배열 생성 함수
void generateRandomArray(int* arr, int size, int min, int max) {
	for (int i = 0; i < size; i++)
		arr[i] = rand() % (max - min + 1) + min;	// 지정된 범위 내에서 랜덤 값 생성
}

// 배열 출력 함수
void printArray(const int* arr, int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);	// 각 요소 출력
	puts("");					// 줄 바꿈 
}

int main()
{
	int size, min, max;
	int* arr;

	srand((unsigned int)time(NULL));	// 프로그램 실행 시 한 번만 시드 설정

	printf("배열 크기 입력: ");
	if (scanf("%d", &size) != 1 || size <= 0) {		// 유효한 입력인지 체크
		printf("잘못된 입력입니다. 프로그램을 종료합니다.\n");
		return 1;
	}

	arr = (int*)calloc(size, sizeof(int));	// 동적 메모리 할당
	if (!arr) {		// 메모리 할당 실패 처리
		printf("메모리 할당 실패!\n");
		return 1;
	}

	printf("랜덤 시작값과 끝값 입력 (공백 구분): ");
	if (scanf("%d %d", &min, &max) != 2 || min > max) {
		printf("잘못된 입력입니다. 프로그램을 종료합니다.\n");
		free(arr);
		return 1;
	}

	generateRandomArray(arr, size, min, max);		// 랜덤 배열 생성

	printf("\n정렬 전 배열 : \n");
	printArray(arr, size);							// 정렬 전 배열 출력

	optimizedBubbleSort(arr, size);					// 개선된 버블 정렬 실행

	printf("\n정렬 후 배열 : \n");
	printArray(arr, size);							// 정렬 후 배열 출력

	free(arr);		// 메모리 해제

	return 0;
}