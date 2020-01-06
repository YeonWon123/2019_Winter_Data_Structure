#include<stdlib.h>
#include<stdio.h>
#include<string>
#include"ALGraphDFS.h"
#include"DLinkedList.h"

int WhoIsPrecede(int data1, int data2);

//ALGraph 구조체를 가리키는 포인터와 노드의 개수를 받아와 그래프를 초기화 시킨다.
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
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);	//visitInfo에 저장된 배열 0으로 초기화
}

//그래프 초기화 과정에서 할당된 리소스 반환 즉 그래프 소멸
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

//노드정보를 받아와 간선추가
void AddEdge(ALGraph* pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

//각 노드에 연결된 그래프 출력
void ShowGraphEdgeInfo(ALGraph* pg)
{
	int vx;
	for (int i = 0; i < pg->numV; i++)
	{
		printf("%c 에 연결된 노드:", i + 65);
		if (LFirst(&(pg->adjList[i]), &vx)) //adList[i]가 가리키는 list가 존재하면
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

//정점을 보여주는 함수
void DFSshowGraphVertex(ALGraph* pg, int startV)
{
	Stack stack;
	int visitV = startV;
	int nextV;

	StackInit(&stack);	//stack 초기화
	VisitVertex(pg, visitV);	//시작 정점을 방문
	SPush(&stack, visitV);	//시작 정점의 정보를 스택으로

	//모든정점의 방문
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
	//visit와 연결된 정점의 정보가 nextV에 담긴 상태에서 이하를 진행
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
//방문한 Vertex는 해당 배열index를 1로 수정
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