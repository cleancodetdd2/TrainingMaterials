// ���Ḯ��Ʈ�� �̿��� ���� ���� 
#include <stdio.h>
#include <stdlib.h>

// ������ ������ ��� 
typedef struct node {
	int vertex;			// ����
	int cost;			// ����ġ (���, ����)
	struct node* next;	// ���� ����� �ּ� 
}node;

// ��带 ������ �׷��� ����ü
typedef struct graph {
	node* head;		// ���� �Ҵ�� ����� �ּ� ����(����� ��� �迭�� �ּ�)
	int vertexCount;	// ������ ���� 
}graph;

void grapInit(graph* pGrp, int count);		//�׷��� �ʱ�ȭ 
void display(graph* pGrp);					//���� ���� ��� (�׷��� ���)
void addUnDirectedEdge(graph* pGrp, int src, int dst, int cost);  //������ �׷��� ���� ����(�����)
void addDirectedEdge(graph* pGrp, int src, int dst, int cost);	//���� �׷��� ���� ����(�ܹ���)

int main()
{
	graph grp;

	//�׷��� �ʱ�ȭ (���� ���� 4��)
	grapInit(&grp, 4);

	//���� �߰� (������ �׷���)
	addUnDirectedEdge(&grp, 0, 1, 1);		//�׷���, �����, ������, ����ġ
	addUnDirectedEdge(&grp, 0, 2, 1);
	addUnDirectedEdge(&grp, 1, 2, 1);
	addUnDirectedEdge(&grp, 2, 3, 1);

	//���� ���� ��� (�׷��� ���)
	display(&grp);

	return 0;
}

void grapInit(graph* pGrp, int count) {

	int i;
	pGrp->vertexCount = count;		//���� ���� ����
	//������ ������ŭ ���� �޸� �Ҵ�
	pGrp->head = malloc(sizeof(node) * count);	// ��� �迭 

	for (i = 0; i < count; i++)
	{
		pGrp->head[i].vertex = i;	// ������ ��ȣ ���� 
		pGrp->head[i].cost = 1;		// ����ġ 1�� �ʱ�ȭ 
		pGrp->head[i].next = NULL;	// ���� ����� �ּ� NULL�� �ʱ�ȭ (�ʱ⿬�����)
	}
}

void display(graph* pGrp)
{
	int i;
	node* curNode;
	for (i = 0; i < pGrp->vertexCount; i++)
	{
		curNode = pGrp->head[i].next;
		printf("����� ��� : %d => ", pGrp->head[i].vertex);	//����� ���	

		while (curNode != NULL)	// �湮 ��尡 �ִٸ� ���(����� ��尡 �ִٸ� ���)
		{
			printf("%d(%d) ", curNode->vertex, curNode->cost); //������, ����ġ ���
			curNode = curNode->next;	// ���� ���� �̵� 
		}
		printf("\n");
	}
}

//������ �׷���(����� �� ����׷����� 2��)
void addUnDirectedEdge(graph* pGrp, int src, int dst, int cost)
{
	addDirectedEdge(pGrp, src, dst, cost);		//�ܹ��� �߰�
	addDirectedEdge(pGrp, dst, src, cost);		//�ݴ� ���� �߰�
}

void addDirectedEdge(graph* pGrp, int src, int dst, int cost)
{
	node* newNode = (node*)malloc(sizeof(node));	//���ο� ��� ���� �޸� �Ҵ�
	newNode->vertex = dst;		// ������ ���� (������ ����)
	newNode->cost = cost;		// ����ġ ���� 
	newNode->next = NULL;		// ���� ����� �ּ� NULL�� �ʱ�ȭ

	if (pGrp->head[src].next == NULL)	// ������� next�� NULL�̸�(����� ��尡 ������)
	{
		pGrp->head[src].next = newNode;	// ������� next�� ���ο� ����� �ּ� ����
		return;		// ������ �Ǿ����� ����
	}

	newNode->next = pGrp->head[src].next;	// ���ο� ����� next�� ������� next �ּ� ���� (���� ���� ����)
	pGrp->head[src].next = newNode;	 // ������� next�� ���ο� ����� �ּ� ����
}
