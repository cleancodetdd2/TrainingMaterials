#include <stdio.h>
#define SIZE 10000		// 큐의 최대 크기 정의
#define INF	99999999	// 언더플로우 발생 시 반환할 큰 음수 값

// 큐 배열, front, rear 변수
int queue[SIZE];
int front = 0;	// 큐의 앞쪽 인덱스
int rear = 0;	// 큐의 뒤쪽 인덱스 

// 큐에 데이터를 삽입하는 함수 (Enqueue)
void push(int data) {
	if (rear >= SIZE) {		//큐가 가득 찬 경우
		printf("큐 오버프로우가 발생했습니다\n");
		return;
	}
	queue[rear++] = data;		//데이터 삽입 후 rear 증가 
	printf("push(%d) 실행됨 (rear: %d)\n", data, rear);
}

//큐에서 데이터 제거하는 함수 (Dequeue)
void pop() {
	if (front == rear) {	// 큐가 비어있는 경우
		printf("큐 언더플로우가 발생했습니다.\n");
		return;
	}
	int data = queue[front++];	// front의 데이터를 반환하고 front 증가
	printf("pop() 실행됨 -> 반환값: %d (front: %d)\n", data, front);
	return data;
}

// 큐 내용 출력 함수
void show() {
	printf("----현재 큐 상태----\n");
	if (front == rear)
		printf("큐가 비어 있습니다.\n");
	else {
		for (int i = front; i < rear; i++)
			printf("%d ", queue[i]);
		printf("\n");
	}
	printf("-----------------------\n");
}

int main()
{
	printf("큐 초기화 완료\n\n");

	push(7);	//7 삽입
	push(5);	//5 삽입
	push(4);	//4 삽입
	pop();		//맨 앞(7) 제거
	push(6);	//6 삽입
	pop();		//맨 앞(5) 제거

	show();

	return 0;
}