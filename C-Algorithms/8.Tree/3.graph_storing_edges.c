// 2���� �迭�� �̿��� ���� ����
#include <stdio.h>
#include <stdlib.h>

typedef struct graph
{
	int vertexCount;		// ������ ����
	int** arr;				// ���� �Ҵ�� ������ �迭�� �ּ� ���� (2����)
}graph;

void grapInit(graph* pGrp, int count);
void edgeDisplay(graph* pGrp);
void unDirectedEdge(graph* pGrp, int src, int dest);
void memoryFree(graph* pGrp);

int main()
{
	graph grp;

	//�׷��� �ʱ�ȭ (���� ���� 4��)
	grapInit(&grp, 4);

	//���� ���� ���� (������ ���� �߰�)
	unDirectedEdge(&grp, 0, 1);		//����ü, �����, ������
	unDirectedEdge(&grp, 0, 2);		//����ü, �����, ������
	unDirectedEdge(&grp, 1, 2);		//����ü, �����, ������
	unDirectedEdge(&grp, 2, 3);		//����ü, �����, ������

	//�׷��� ��� (���� ��� ����)
	edgeDisplay(&grp);

	//�޸� ����
	memoryFree(&grp);

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
	for (i = 0; i < count; i++) {
		// calloc(����,����Ʈũ��) : 0���� �ʱ�ȭ
		pGrp->arr[i] = (int*)calloc(count, sizeof(int));	//������ �迭
		if (pGrp->arr[i] == NULL) {
			printf("�޸� �Ҵ� ����\n");
			exit(1);
		}
	}
	
}

// ���� ��� ��� �Լ�
void edgeDisplay(graph* pGrp)
{
	int i, j;
	printf("\n\n --- ���� ���� ��Ȳ (���� ���) ---\n\n");
	printf("     ");

	for (i = 0; i < pGrp->vertexCount; i++)
		printf(" %5d ", i);
	printf("\n");

	for(i = 0; i < pGrp->vertexCount; i++) {	// �����
		printf("����� %d => ", i);
		for (j = 0; j < pGrp->vertexCount; j++) {	// ������
			printf("%5d", pGrp->arr[i][j]);
		}
		printf("\n");
	}
}

// ������ ���� �߰� �Լ� // ����ü, �����(��), ������(��)
void unDirectedEdge(graph* pGrp, int src, int dest)
{
	//���� ���� üũ
	if (src >= pGrp->vertexCount || dest >= pGrp->vertexCount || src < 0 || dest < 0) {
		printf("���� : ��ȿ���� ���� ���� (%d, %d)\n", src, dest);
		return;
	}

	// ������ �׷��� (�����)
	pGrp->arr[src][dest] = 1;
	pGrp->arr[dest][src] = 1;

}

void memoryFree(graph* pGrp)
{
	int i;
	for (i = 0; i < pGrp->vertexCount; i++)
	{
		printf("arr[%d]����Ű�� ������ �迭 ����\n", i);
		free(pGrp->arr[i]);		// free(������) : �����Ͱ� ����Ű�� �޸𸮰� ����
		pGrp->arr[i] = NULL;	// ���� ���� ���� 
	}

	printf("������ �迭�� ����� ���� ������ �迭 ����\n");
	free(pGrp->arr);
	pGrp->arr = NULL;
}
