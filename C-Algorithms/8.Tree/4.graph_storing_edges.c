// 연결리스트를 이용한 간선 저장 
#include <stdio.h>
#include <stdlib.h>

// 간선을 저장할 노드 
typedef struct node {
	int vertex;			// 정점
	int cost;			// 가중치 (비용, 길이)
	struct node* next;	// 다음 노드의 주소 
}node;

// 노드를 관리할 그래프 구조체
typedef struct graph {
	node* head;		// 동적 할당된 노드의 주소 저장(출발지 노드 배열의 주소)
	int vertexCount;	// 정점의 개수 
}graph;

void grapInit(graph* pGrp, int count);		//그래프 초기화 
void display(graph* pGrp);					//간선 정보 출력 (그래프 출력)

int main()
{
	graph grp;

	//그래프 초기화 (정점 개수 4개)
	grapInit(&grp, 4);

	//간선 정보 출력 (그래프 출력)
	display(&grp);

	return 0;
}

void grapInit(graph* pGrp, int count) {

	int i;
	pGrp->vertexCount = count;		//정점 개수 저장
	//정점의 개수만큼 동적 메모리 할당
	pGrp->head = malloc(sizeof(node) * count);	// 노드 배열 

	for (i = 0; i < count; i++)
	{
		pGrp->head[i].vertex = i;	// 정점의 번호 저장 
		pGrp->head[i].cost = 1;		// 가중치 1로 초기화 
		pGrp->head[i].next = NULL;	// 다음 노드의 주소 NULL로 초기화 (초기연결없음)
	}
}

void display(graph* pGrp)
{
	int i;
	node* curNode;
	for (i = 0; i < pGrp->vertexCount; i++)
	{
		curNode = pGrp->head[i].next;
		printf("출발지 노드 : %d => ", pGrp->head[i].vertex);	//출발지 출력	

		while (curNode != NULL)	// 방문 노드가 있다면 출력(연결된 노드가 있다면 출력)
		{
			printf("%d(%d) ", curNode->vertex, curNode->cost); //도착지, 가중치 출력
			curNode = curNode->next;	// 다음 노드로 이동 
		}
		printf("\n");
	}
}
