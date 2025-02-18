#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 매크로 함수 : 두 변수의 값을 교환
#define swap(type, x, y) do { type temp = x; x = y; y = temp; } while(0)

// 배열을 랜덤 값으로 초기화
void randomize(int* arr, int size, int start, int end) {
	for (int i = 0; i < size; i++)
		arr[i] = rand() % (end - start + 1) + start;  //지정한 범위 내 랜덤 값 생성
}

// 배열 출력 함수 (간격을 넓힘)
void print_array_spaced(int* arr, int size) {
	for (int i = 0; i < size; i++)	// 배열의 모든 요소 출력
		printf("%3d ", arr[i]);
	printf("\n");
	printf("\n");
}

//선택 정렬 함수
//배열에서 최솟값을 찾아 맨 앞부터 정렬하는 방식
void selection_sort(int* arr, int size) {
	int i, j, min;		// 최솟값 인덱스 변수
	printf(" 단계 |   i    | 초기 min 값 | 최종 min 값 | 교환 여부 |    정렬 후 배열\n");
	printf("-----------------------------------------------------------------------------\n");

	for (i = 0; i < size - 1; i++) {	// 배열 크기 -1만큼 반복(마지막 요소는 자동 정렬됨)
		min = i;	// 현재 정렬 위치를 최솟값으로 지정
		int initial_min_value = arr[min];	// 초기 최소값 저장 (현재 i 위치의 값)

		for (j = i + 1; j < size; j++) {	// 현재 i 이후의 값들과 비교하여 최솟값 찾기
			if (arr[min] > arr[j])			// 현재 최솟값보다 작은 값 발견시 최솟값 인덱스 변경
				min = j;
		}
		int final_min_value = arr[min];		// 최종적으로 찾은 최솟값 저장 
		int swap_happend = (i != min);	// 현재 i 위치의 값과 최솟값의 위치가 다름 => 교환필요
		
		if (swap_happend)	// 최소값이 현재 위치의 값과 다를 경우
			swap(int, arr[i], arr[min]);	// i위치의 값과 최솟값 교환 

		//정렬 과정 출력
		printf("  %3d  |  %3d  |    %10d  |    %10d  |  %7s  | ",
			i + 1, i, initial_min_value, final_min_value, swap_happend ? "Yes" : "No");
		print_array_spaced(arr, size);		//현재 정렬된 상태 출력
		printf("\n");
	}

}


int main()
{
	int size, start, end;	// 배열크기, 랜덤 범위 변수 선언
	int* arr;				// 동적 할당할 배열 포인터 선언

	srand((unsigned int)time(NULL));		// 난수 초기화 (프로그램 실행시 1회 수행)

	//배열 크기 입력
	printf("배열 크기 입력 : ");
	if (scanf("%d", &size) != 1 || size <= 0) {
		printf("유효한 배열 크기를 입력하세요.\n");
		return 1;	// 오류 발생 시 프로그램 종료
	}

	//메모리 동적 할당
	arr = calloc(size, sizeof(int));	// 배열을 0으로 초기화하여 동적 할당
	if (!arr) {	// 메모리 할당 실패
		printf("메모리 할당 실패\n");
		return 1;
	}

	//랜덤 범위 입력
	printf("랜덤 시작 수 / 끝 수 입력 (공백 구분) : ");
	if (scanf("%d %d", &start, &end) != 2 || start > end) {
		printf("유효한 숫자 범위를 입력하세요.\n");
		free(arr);		// 메모리 해제
		return 1;
	}

	randomize(arr, size, start, end);

	//정렬 전 배열 출력
	printf("\n\n--- 정렬 전 자료 출력 ---\n");
	print_array_spaced(arr, size);
	printf("\n\n");

	//선택 정렬 실행
	selection_sort(arr, size);

	//정렬 후 배열 출력
	printf("\n\n--- 정렬 후 자료 출력 ---\n");
	print_array_spaced(arr, size);
	printf("\n\n");

	// 동적 메모리 해제
	free(arr);		// 할당된 메모리 반환
	return 0;
}