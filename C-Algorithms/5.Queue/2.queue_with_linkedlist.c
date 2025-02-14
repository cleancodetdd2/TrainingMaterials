#include <stdio.h>
#include <stdlib.h>

#define INF 99999999	//에러 발생 시 반환할 큰 수 (매우 큰 음수)

//노드 구조체 (각 요소를 저장하는 구조체)
typedef struct Node {
	int data;			// 데이터 저장
	struct Node* next;	// 다음 노드를 가리키는 포인터 
} Node;

//큐 구조체 (큐 전체를 관리)
typedef struct {
	Node* front;	// 큐의 첫번째 노드 (출구, 데이터를 꺼내는 곳)
	Node* rear;		// 큐의 마지막 노드 (입구, 데이터를 넣는 곳)
	int count;		// 큐에 들어 있는 원소 
} Queue;

//큐 초기화 함수 (처음 사용할 때 실행)
void initQueue(Queue* queue) {
	queue->front = queue->rear = NULL;	// front와 rear를 NULL로 초기화
	queue->count = 0;					// 큐의 크기를 0으로 설정
}

//큐가 비어있는지 확인하는 함수
int isEmpty(Queue* queue) {
	return queue->count == 0;	// 원소 개수가 0이면 비어 있음
}

//큐에 데이터 추가 (Enqueue)
void push(Queue* queue, int data)
{
	// 새 노드 동적 할당(메모리 공간 확보)
	Node* node = (Node*)malloc(sizeof(Node));

	// 메모리 할당 실패 체크
	if (node == NULL) {
		printf("메모리 할당 실패!\n");	// 에러 메시지 출력
		return;		// 함수 종료
	}

	node->data = data;		// 노드에 데이터 저장
	node->next = NULL;		// 새 노드에 마지막 노드이므로 next는 NULL

	if (isEmpty(queue)) {	// 큐가 비어 있다면	
		queue->front = node;	// front도 새 노드를 가리키도록 설정 
	}
	else
		queue->rear->next = node;	// 기존 rear의 next를 새노드를 연결

	queue->rear = node;	// rear를 새 노드로 업데이트 
	queue->count++;		// 큐 원소 개수 증가 
}

//큐에서 데이터 제거(Dequeue)
int pop(Queue* queue) {
	if (isEmpty(queue)) {	// 큐가 비어 있는 경우
		printf("큐 언더플로우가 발생합니다\n");		// 에러 메시지 출력
		return -INF;		// 큐가 비어있음을 나타내는 값 반환
	}

	Node* node = queue->front;		// 제거할 노드(맨 앞 노드)
	int data = node->data;			// 노드의 데이터 저장

	queue->front = node->next;		// front를 다음 노드로 이동

	free(node);			// 제거할 노드의 메모리 해제
	queue->count--;		// 큐 원소 개수 감소 

	//큐가 완전히 비었으면 rear도 NULL로 초기화
	if (isEmpty(queue))
		queue->rear = NULL;

	return data;		// 제거된 데이터 반환
}

// 큐 메모리 해제 함수 (프로그램 종료 시 사용)
void clearQueue(Queue* queue) {
	while (!isEmpty(queue)) {	// 큐가 비어있을 때까지
		pop(queue);				// 하나씩 제거 
	}
}

// 큐 출력 함수 (현재 큐의 내용 확인)
void show(Queue* queue) {
	Node* cur = queue->front;	// 첫번째 노드부터 탐색

	printf("----큐의 내용----\n");
	while (cur != NULL) {	// 큐의 끝까지 반복
		printf("%d\n", cur->data);		// 현재 노드의 데이터 출력
		cur = cur->next;				// 다음 노드로 이동
	}
	printf("-----------------\n");
}

int main()
{
	Queue queue;		// 큐선언
	initQueue(&queue);	// 큐 초기화 

	push(&queue, 7);	// 7 추가
	push(&queue, 5);	// 5 추가
	push(&queue, 4);	// 4 추가

	pop(&queue);		// 첫번째 원소 제거 (7제거)
	push(&queue, 6);	// 6 추가
	pop(&queue);		// 첫번째 원소 제거 (5제거)

	show(&queue);	// 현재 큐의 상태 출력

	clearQueue(&queue);	// 프로그램 종료 전 메모리 해제
	return 0;	// 프로그램 정상 종료
}