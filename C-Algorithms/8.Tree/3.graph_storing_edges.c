// 2���� �迭�� �̿��� ���� ����
#include <stdio.h>
#include <stdlib.h>

typedef struct graph
{
	int vertexCount;		// ������ ����
	int** arr;				// ���� �Ҵ�� ������ �迭�� �ּ� ���� (2����)
}graph;

void grapInit(graph* pGrp, int count);

int main()
{
	graph grp;

	//�׷��� �ʱ�ȭ (���� ���� 4��)
	grapInit(&grp, 4);

	return 0;
}

// �׷��� �ʱ�ȭ �Լ�
void grapInit(graph* pGrp, int count)
{
	int i;
	pGrp->vertexCount = count;		// ������ ���� ���� 
	//int�� ������ ������ count ��ŭ ���� �޸� �Ҵ� (�����͹迭, 2�����迭)
	pGrp->arr = malloc(sizeof(int*) * count); 
	if (pGrp->arr == NULL) {
		printf("�޸� �Ҵ� ����\n");
		exit(1);
	}

	// �� �࿡ ���� ���� �Ҵ�

	
}
