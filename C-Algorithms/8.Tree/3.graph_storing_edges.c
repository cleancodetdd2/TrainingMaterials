// 2차원 배열을 이용한 간선 저장
#include <stdio.h>
#include <stdlib.h>

typedef struct graph
{
	int vertexCount;		// 정점의 갯수
	int** arr;				// 동적 할당된 포인터 배열의 주소 저장 (2차원)
}graph;

void grapInit(graph* pGrp, int count);
void edgeDisplay(graph* pGrp);
void unDirectedEdge(graph* pGrp, int src, int dest);
void memoryFree(graph* pGrp);

int main()
{
	graph grp;

	//그래프 초기화 (정점 개수 4개)
	grapInit(&grp, 4);

	//간선 정보 저장 (무방향 간선 추가)
	unDirectedEdge(&grp, 0, 1);		//구조체, 출발지, 도착지
	unDirectedEdge(&grp, 0, 2);		//구조체, 출발지, 도착지
	unDirectedEdge(&grp, 1, 2);		//구조체, 출발지, 도착지
	unDirectedEdge(&grp, 2, 3);		//구조체, 출발지, 도착지

	//그래프 출력 (인접 행렬 형태)
	edgeDisplay(&grp);

	//메모리 해제
	memoryFree(&grp);

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
	for (i = 0; i < count; i++) {
		// calloc(개수,바이트크기) : 0으로 초기화
		pGrp->arr[i] = (int*)calloc(count, sizeof(int));	//일차원 배열
		if (pGrp->arr[i] == NULL) {
			printf("메모리 할당 실패\n");
			exit(1);
		}
	}
	
}

// 인접 행렬 출력 함수
void edgeDisplay(graph* pGrp)
{
	int i, j;
	printf("\n\n --- 간선 연결 현황 (인접 행렬) ---\n\n");
	printf("     ");

	for (i = 0; i < pGrp->vertexCount; i++)
		printf(" %5d ", i);
	printf("\n");

	for(i = 0; i < pGrp->vertexCount; i++) {	// 출발지
		printf("출발지 %d => ", i);
		for (j = 0; j < pGrp->vertexCount; j++) {	// 도착지
			printf("%5d", pGrp->arr[i][j]);
		}
		printf("\n");
	}
}

// 무방향 간선 추가 함수 // 구조체, 출발지(행), 도착지(열)
void unDirectedEdge(graph* pGrp, int src, int dest)
{
	//정점 범위 체크
	if (src >= pGrp->vertexCount || dest >= pGrp->vertexCount || src < 0 || dest < 0) {
		printf("에러 : 유효하지 않은 간선 (%d, %d)\n", src, dest);
		return;
	}

	// 무방향 그래프 (양방향)
	pGrp->arr[src][dest] = 1;
	pGrp->arr[dest][src] = 1;

}

void memoryFree(graph* pGrp)
{
	int i;
	for (i = 0; i < pGrp->vertexCount; i++)
	{
		printf("arr[%d]가리키는 일차원 배열 제거\n", i);
		free(pGrp->arr[i]);		// free(포인터) : 포인터가 가리키는 메모리가 해제
		pGrp->arr[i] = NULL;	// 이중 해제 방지 
	}

	printf("이차원 배열을 만들기 위한 포인터 배열 제거\n");
	free(pGrp->arr);
	pGrp->arr = NULL;
}
