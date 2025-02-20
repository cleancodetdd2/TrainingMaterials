// 2차원 배열을 이용한 간선 저장
#include <stdio.h>
#include <stdlib.h>

typedef struct graph
{
	int vertexCount;		// 정점의 갯수
	int** arr;				// 동적 할당된 포인터 배열의 주소 저장 (2차원)
}graph;

void grapInit(graph* pGrp, int count);

int main()
{
	graph grp;

	//그래프 초기화 (정점 개수 4개)
	grapInit(&grp, 4);

	return 0;
}

// 그래프 초기화 함수
void grapInit(graph* pGrp, int count)
{
	int i;
	pGrp->vertexCount = count;		// 정점의 개수 저장 
	//int형 포인터 변수를 count 만큼 동적 메모리 할당 (포인터배열, 2차원배열)
	pGrp->arr = malloc(sizeof(int*) * count); 
	if (pGrp->arr == NULL) {
		printf("메모리 할당 실패\n");
		exit(1);
	}

	// 각 행에 대해 열을 할당

	
}
