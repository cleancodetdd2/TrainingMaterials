/*
	��� ����, ���� ���� �Է� : 3 3 
	3�� ���� �Է�
	1 2
	1 3
	2 3

	  1
     / \ 
    2---3 

	DFS �湮 ���� : 1 3 2 
	----------------------------------------------------
	��� ����, ���� ���� �Է� : 6 6
	6�� ���� �Է�
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
	
	DFS �湮 ���� : 1 3 6 5 2 4

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// ��� ����ü ����
typedef struct Node {
	int index;			// ���� ����� �ε���
	struct Node* next;	// ���� ��带 ����Ű�� ������ 
} Node;

Node** adjacencyList;		// ���� ����Ʈ (�׷��� ����)
int visited[MAX_SIZE];		// �湮 ���θ� �����ϴ� �迭
int n, m;					// ��� ����(n)�� ���� ����(m)

void addEdge(int src, int dest);
void dfs(int node);

int main()
{
	//����� �Է�
	printf("��� ����(n)�� ���� ����(m)�� �Է��ϼ���(���� ����): ");
	scanf("%d %d", &n, &m);

	// �� ����� ��������Ʈ ����� �����ϴ� å��
	adjacencyList = (Node**)malloc(sizeof(Node*) * (n + 1));
	if (!adjacencyList) {
		fprintf(stderr, "�޸� �Ҵ� ����\n");
		return 1;
	}

	for (int i = 1; i <= n; i++) {
		adjacencyList[i] = (Node*)malloc(sizeof(Node));
		if (!adjacencyList[i]) {
			fprintf(stderr, "�޸� �Ҵ� ����\n");
			return 1;
		}
		adjacencyList[i]->next = NULL;	// �� ����Ʈ�� �ʱⰪ�� NULL
	}

	// ���� ���� �Է� �� �׷��� ����
	printf("%d���� ������ �Է��ϼ���(�� ������ �� ������ �������� ����):\n", m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);		// �� ���� �Է� �ޱ� 
		addEdge(x, y);				// ���� �߰� 
		addEdge(y, x);				// ������ �׷��� (����� �߰�)
	}

	// DFS ����
	printf("DFS �湮 ���� :");
	dfs(1);		// 1�� ������ DFS ���� 
	printf("\n");

	// ���� �޸� ����
	for (int i = 1; i <= n; i++) {
		Node* current = adjacencyList[i];
		while (current != NULL) {
			Node* temp = current;
			current = current->next;
			free(temp);	 // �Ҵ�� ��� �޸� ����
		}
	}
	free(adjacencyList);	// ���� ����Ʈ �迭 �޸� ����

	return 0;
}

// ���ο� ��带 ����Ʈ �տ� �߰��ϴ� �Լ�
void addEdge(int src, int dest)
{
	//���ο� ��� ���� �Ҵ�
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (!newNode) {
		fprintf(stderr, "�޸� �Ҵ� ����\n");
		exit(1);
	}

	newNode->index = dest;		// ����� �ε��� ����
	newNode->next = adjacencyList[src]->next;  //���� ����Ʈ�� ù ��° ��带 ����Ŵ
	adjacencyList[src]->next = newNode;	//����Ʈ�� ��带 ���ο� ���� ����
}

// ���� �켱 Ž�� �Լ�
void dfs(int node)
{
	if (visited[node]) return;		//�̹� �湮�� ����� ����

	visited[node] = 1;	// �湮 ǥ��
	printf("%d ", node);		// �湮�� ��� ���

	Node* current = adjacencyList[node]->next;  // ���� ��� Ž��
	while (current != NULL) {
		dfs(current->index);	//��� ȣ��� ���� �켱 Ž�� ����
		current = current->next;	// ���� ���� ���� �̵�
	}

}
