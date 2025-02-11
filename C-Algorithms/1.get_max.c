#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_ELEMENTS 100	//최대 학생수 

// 학생 점수를 저장할 배열 (자료 구조)
int scores[MAX_ELEMENTS];

// 최대 점수를 찾는 함수 (알고리즘)
int get_max_score(int n)
{
	int i, largest;

	//if (n <= 0) return -1;		//예외처리

	largest = scores[0];		//첫번째 점수를 최대값으로 초기화 
	for (i = 1; i < n; i++) {	//배열을 순회하면서 최대값 찾기
		if (scores[i] > largest)
			largest = scores[i];
	}

	return largest;		//최대 점수 반환 
}

int main()
{
	int i, n, max_score;

	printf("학생 수를 입력하세요 (최대 %d명): ", MAX_ELEMENTS);
	if (scanf("%d", &n) != 1) {
		printf("입력 오류입니다.\n");
		return 1;
	}

	if (n <= 0 || n > MAX_ELEMENTS) {
		printf("잘못된 학생 수입니다\n");
		return 1;
	}

	//학생 점수 입력
	printf("각 학생의 점수를 입력하세요\n");
	for (i = 0; i < n; i++) {
		printf("학생 %d: ", i + 1);
		scanf("%d", &scores[i]);
	}

	max_score = get_max_score(n);

	printf("최고 점수는 %d점 입니다.\n", max_score);

	return 0;
}