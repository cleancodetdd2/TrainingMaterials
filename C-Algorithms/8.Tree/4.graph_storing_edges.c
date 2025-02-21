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
void addUnDirectedEdge(graph* pGrp, int src, int dst, int cost);  //무방향 그래프 간선 저장(양방향)
void addDirectedEdge(graph* pGrp, int src, int dst, int cost);	//방향 그래프 간선 저장(단방향)

int main()
{
	graph grp;

	//그래프 초기화 (정점 개수 4개)
	grapInit(&grp, 4);

	//간선 추가 (무방향 그래프)
	addUnDirectedEdge(&grp, 0, 1, 1);		//그래프, 출발지, 도착지, 가중치
	addUnDirectedEdge(&grp, 0, 2, 1);
	addUnDirectedEdge(&grp, 1, 2, 1);
	addUnDirectedEdge(&grp, 2, 3, 1);

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

//무방향 그래프(양방향 즉 뱡향그래프가 2개)
void addUnDirectedEdge(graph* pGrp, int src, int dst, int cost)
{
	addDirectedEdge(pGrp, src, dst, cost);		//단방향 추가
	addDirectedEdge(pGrp, dst, src, cost);		//반대 방향 추가
}

void addDirectedEdge(graph* pGrp, int src, int dst, int cost)
{
	node* newNode = (node*)malloc(sizeof(node));	//새로운 노드 동적 메모리 할당
	newNode->vertex = dst;		// 도착지 저장 (목적지 정점)
	newNode->cost = cost;		// 가중치 저장 
	newNode->next = NULL;		// 다음 노드의 주소 NULL로 초기화

	if (pGrp->head[src].next == NULL)	// 출발지의 next가 NULL이면(연결된 노드가 없으면)
	{
		pGrp->head[src].next = newNode;	// 출발지의 next에 새로운 노드의 주소 저장
		return;		// 연결이 되었으니 종료
	}

	newNode->next = pGrp->head[src].next;	// 새로운 노드의 next에 출발지의 next 주소 저장 (기존 노드와 연결)
	pGrp->head[src].next = newNode;	 // 출발지의 next에 새로운 노드의 주소 저장
}
