/*
	노드 개수, 간선 개수 입력 : 3 3 
	3개 간선 입력
	1 2
	1 3
	2 3

	  1
     / \ 
    2---3 

	DFS 방문 순서 : 1 3 2 
	----------------------------------------------------
	노드 개수, 간선 개수 입력 : 6 6
	6개 간선 입력
	1 2
	1 3
	2 4
	2 5
	3 6
	5 6

		1
       / \
      2   3
	 / \   \
    4   5---6
	
	DFS 방문 순서 : 1 3 6 5 2 4

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// 노드 구조체 정의
typedef struct Node {
	int index;			// 현재 노드의 인덱스
	struct Node* next;	// 다음 노드를 가리키는 포인터 
} Node;

Node** adjacencyList;		// 인접 리스트 (그래프 저장)
int visited[MAX_SIZE];		// 방문 여부를 저장하는 배열
int n, m;					// 노드 개수(n)와 간선 개수(m)

void addEdge(int src, int dest);
void dfs(int node);

int main()
{
	//사용자 입력
	printf("노드 개수(n)와 간선 개수(m)을 입력하세요(공백 구분): ");
	scanf("%d %d", &n, &m);

	// 각 노드의 인접리스트 목록을 저장하는 책상
	adjacencyList = (Node**)malloc(sizeof(Node*) * (n + 1));
	if (!adjacencyList) {
		fprintf(stderr, "메모리 할당 실패\n");
		return 1;
	}

	for (int i = 1; i <= n; i++) {
		adjacencyList[i] = (Node*)malloc(sizeof(Node));
		if (!adjacencyList[i]) {
			fprintf(stderr, "메모리 할당 실패\n");
			return 1;
		}
		adjacencyList[i]->next = NULL;	// 각 리스트의 초기값은 NULL
	}

	// 간선 정보 입력 및 그래프 구성
	printf("%d개의 간선을 입력하세요(각 간선의 두 정점을 공백으로 구분):\n", m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);		// 두 정점 입력 받기 
		addEdge(x, y);				// 간선 추가 
		addEdge(y, x);				// 무방향 그래프 (양방향 추가)
	}

	// DFS 수행
	printf("DFS 방문 순서 :");
	dfs(1);		// 1번 노드부터 DFS 시작 
	printf("\n");

	// 동적 메모리 해제
	for (int i = 1; i <= n; i++) {
		Node* current = adjacencyList[i];
		while (current != NULL) {
			Node* temp = current;
			current = current->next;
			free(temp);	 // 할당된 노드 메모리 해제
		}
	}
	free(adjacencyList);	// 인접 리스트 배열 메모리 해제

	return 0;
}

// 새로운 노드를 리스트 앞에 추가하는 함수
void addEdge(int src, int dest)
{
	//새로운 노드 동적 할당
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (!newNode) {
		fprintf(stderr, "메모리 할당 실패\n");
		exit(1);
	}

	newNode->index = dest;		// 노드의 인덱스 설정
	newNode->next = adjacencyList[src]->next;  //기존 리스트의 첫 번째 노드를 가리킴
	adjacencyList[src]->next = newNode;	//리스트의 헤드를 새로운 노드로 변경
}

// 깊이 우선 탐색 함수
void dfs(int node)
{
	if (visited[node]) return;		//이미 방문한 노드라면 종료

	visited[node] = 1;	// 방문 표시
	printf("%d ", node);		// 방문한 노드 출력

	Node* current = adjacencyList[node]->next;  // 인접 노드 탐색
	while (current != NULL) {
		dfs(current->index);	//재귀 호출로 깊이 우선 탐색 수행
		current = current->next;	// 다음 인접 노드로 이동
	}

}
