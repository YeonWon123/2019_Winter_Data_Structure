#include<stdlib.h>
#include<stdio.h>
#include<string>
#include"ALGraphDFS.h"
#include"DLinkedList.h"

int WhoIsPrecede(int data1, int data2);

//ALGraph ����ü�� ����Ű�� �����Ϳ� ����� ������ �޾ƿ� �׷����� �ʱ�ȭ ��Ų��.
void GraphInit(ALGraph* pg, int nv)
{
	pg->numV = nv;
	pg->numE = 0;
	pg->adjList = (List*)malloc(sizeof(List) * nv);

	for (int i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}

	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);	//visitInfo�� ����� �迭 0���� �ʱ�ȭ
}

//�׷��� �ʱ�ȭ �������� �Ҵ�� ���ҽ� ��ȯ �� �׷��� �Ҹ�
void GraphDestroy(ALGraph* pg)
{

	if (pg->adjList != NULL)
	{
		free(pg->adjList);
	}
	if (pg->visitInfo != NULL)
	{
		free(pg->visitInfo);
	}
}

//��������� �޾ƿ� �����߰�
void AddEdge(ALGraph* pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

//�� ��忡 ����� �׷��� ���
void ShowGraphEdgeInfo(ALGraph* pg)
{
	int vx;
	for (int i = 0; i < pg->numV; i++)
	{
		printf("%c �� ����� ���:", i + 65);
		if (LFirst(&(pg->adjList[i]), &vx)) //adList[i]�� ����Ű�� list�� �����ϸ�
		{
			printf("%c ", vx + 65);
			while (LNext(&(pg->adjList[i]), &vx))
			{
				printf("%c ", vx + 65);
			}
		}
		printf("\n");
	}
}

//������ �����ִ� �Լ�
void DFSshowGraphVertex(ALGraph* pg, int startV)
{
	Stack stack;
	int visitV = startV;
	int nextV;

	StackInit(&stack);	//stack �ʱ�ȭ
	VisitVertex(pg, visitV);	//���� ������ �湮
	SPush(&stack, visitV);	//���� ������ ������ ��������

	//��������� �湮
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
	//visit�� ����� ������ ������ nextV�� ��� ���¿��� ���ϸ� ����
		int visitFlag = FALSE;
		if (VisitVertex(pg, nextV) == TRUE)
		{
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else
		{
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				if (VisitVertex(pg, nextV) == TRUE)
				{
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}
		if (visitFlag == FALSE)
		{
			if (SIsEmpty(&stack) == TRUE)
				break;
			else
				visitV = SPop(&stack);
		}
	}
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}
//�湮�� Vertex�� �ش� �迭index�� 1�� ����
int VisitVertex(ALGraph* pg, int visitV)
{
	if (pg->visitInfo[visitV] == 0)
	{
		pg->visitInfo[visitV] = 1;
		printf("%c ", visitV + 65);
		return TRUE;
	}
	return FALSE;
}

int WhoIsPrecede(int data1, int data2)
{
	if (data1 < data2)
		return 0;
	else
		return 1;
}