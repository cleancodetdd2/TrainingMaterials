#include <stdio.h>
#include <stdlib.h>

int main()
{
	//gnuplot 실행을 위한 파이프(FILE 포인터) 생성
	FILE* gp = _popen("gnuplot", "w");	// gnuplot 프로세스를 실행하여 파이프를 염
	if (gp) {	// gnuplot 실행이 성공하면
		fprintf(gp, "set title 'Gnuplot 테스트 실행'\n");	//그래프 제목 설정
		fprintf(gp, "plot sin(x)\n");	// sin(x) 함수를 그래프로 출력
		fprintf(gp, "pause -1\n");	// 그래프 창 유지되도록 설정
		fflush(gp);	// 버퍼를 강제 비움 -> gnuplot 명령 즉시 실행하도록 함

		printf("gnuplot 실행 성공!\n");
		getchar();		// 사용자 입력 대기

		_pclose(gp);	// gnuplot 프로세스를 닫고 파이프를 해제
	}
	else
		fprintf(stderr, "gnuplot 실행 실패! 환경 변수 확인하세요!\n");


	return 0;
}