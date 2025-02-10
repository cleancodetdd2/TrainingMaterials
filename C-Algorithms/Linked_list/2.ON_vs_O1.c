#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>	// Windows API 사용

// 반복문 방식 : ON - 1부터 N까지 숫자를 더하는 방식
int sum_loop(int N) {
	int total = 0;
	for (int i = 1; i <= N; i++)	//N번 반복하여 합산
		total += i;
	return total;		// 최종 합 반환 
}

// 수학 공식 방식 : O(1) - 단순한 공식으로 계산
int sum_formula(int N) {
	return (N * (N + 1)) / 2;		//등차수열 합 공식 사용 
}

int main()
{
	//테스트할 N값 배열
	int N_values[] = { 10, 100, 1000, 10000, 50000, 1000000 };
	int size = sizeof(N_values) / sizeof(N_values[0]);	// 배열 크기 계산

	//동적 메모리 할당 
	double* times_loop = (double*)malloc(size * sizeof(double));	// O(N) 실행 시간 저장 
	double* times_formula = (double*)malloc(size * sizeof(double));	// O(1) 실행 시간 저장 

	//메모리 할당 실패 시 프로그램 종료
	if (times_loop == NULL || times_formula == NULL) {
		fprintf(stderr, "메모리 할당 실패함: 충분한 메모리가 없습니다.");
		free(times_loop);
		free(times_formula);
		return EXIT_FAILURE;
	}

	// 결과를 저장할 파일 열기 (쓰기 모드)
	FILE* fp;
	errno_t err = fopen_s(&fp, "result.txt", "w");
	if (err != 0 || fp == NULL) {
		fprintf(stderr, "파일을 열 수 없습니다.\n");
		free(times_loop);
		free(times_formula);
		return EXIT_FAILURE;
	}

	fprintf(fp, "# N 실행시간(반복문)  실행시간(공식)");		// 파일에 헤더 작성

	for (int i = 0; i < size; i++) {
		int N = N_values[i];			// 현재 테스트할 N 값

		// O(N) 실행 시간 측정
		LARGE_INTEGER freq, start, end;
		QueryPerformanceFrequency(&freq);	// 고해상도 타이머 주파수 가져오기

		QueryPerformanceFrequency(&start);	// 시작 시간 기록
		sum_loop(N);						// 함수 실행
		QueryPerformanceFrequency(&end);	// 종료 시간 기록

		double queryPerformance_loop = 
			(double)(end.QuadPart - start.QuadPart) / freq.QuadPart * 10000000;
		times_loop[i] = queryPerformance_loop;		//결과 저장 

		// O(1) 실행 시간 측정
		QueryPerformanceFrequency(&start);	// 시작 시간 기록
		sum_formula(N);						// 함수 실행
		QueryPerformanceFrequency(&end);	// 종료 시간 기록

		double formula_loop =
			(double)(end.QuadPart - start.QuadPart) / freq.QuadPart * 10000000;
		times_formula[i] = formula_loop;		//결과 저장 

		//콘솔 출력
		printf("N: %d | O(N) 반복문 방식: %.2f  마이크로s | O(1) 수학 공식 방식 : %.2f 마이크로 s\n",
				N, queryPerformance_loop, formula_loop);

		//파일에 저장
		fprintf(fp, "%d %.2f %.2f\n", N, queryPerformance_loop, formula_loop);

	}

	fclose(fp);		// 파일 닫기 
	printf("\n 실행 완료! 'result.txt'에 결과 저장");

	FILE* gp = _popen("gnuplot", "w");	// gnuplot 프로세스를 실행하여 파이프를 염
	if (gp) {
		fprintf(gp, "set title 'O(N) vs O(1) 실행 시간 비교'\n");  // 그래프 제목
		fprintf(gp, "set xlabel 'N 값'\n");  // X축 라벨
		fprintf(gp, "set ylabel '실행 시간 (마이크로초)'\n");  // Y축 라벨
		fprintf(gp, "set grid\n");  // 그리드 추가
		fprintf(gp, "plot 'result.txt' using 1:2 with linespoints title 'O(N) 반복문' linecolor rgb 'red', "
			"'result.txt' using 1:3 with linespoints title 'O(1) 공식' linecolor rgb 'blue'\n");
		fprintf(gp, "pause mouse close\n");  // 마우스 클릭 시 창 유지
		fflush(gp);
		_pclose(gp);
		printf("\nGnuplot 그래프를 실행했습니다. 창에서 확인하세요!\n");
	}
	else {
		fprintf(stderr, "Gnuplot 실행 실패! 환경 변수를 확인하세요.\n");
	}

	// 동적 메모리 해제
	free(times_loop);
	free(times_formula);

	return 0;
}

