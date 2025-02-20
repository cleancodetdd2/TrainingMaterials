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

int main()
{
	graph grp;

	//�׷��� �ʱ�ȭ (���� ���� 4��)
	grapInit(&grp, 4);

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
