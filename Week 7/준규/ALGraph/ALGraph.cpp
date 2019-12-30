
#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "ALGraph.h"

#include <iostream>
#include <string>

using namespace std;

int WhoIsPreced(int data1, int data2);

void GraphInit(ALGraph* pg, int nv)
{
	int i;

	pg->adjList = (List*)malloc(sizeof(List)*nv);
	pg->numV = nv;
	pg->numE = 0;

	for (int i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPreced);
	}
}

void GraphDestory(ALGraph* pg)
{
	if (pg->adjList != NULL)
		free(pg->adjList);
}

void AddEdge(ALGraph* pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

void ShowGraphEdgeInfo(ALGraph* pg)
{
	int i;
	int vx;

	for (int i = 0; i < pg->numV; i++)
	{
		cout << (char)(i + 65) << "와 연결된 정점: ";
		if (LFirst(&(pg->adjList[i]), &vx))
		{
			cout << (char)(vx+65);
			
			while (LNext(&(pg->adjList[i]), &vx))
				cout << (char)(vx + 65);
		}
		cout << endl;
	}
}


int WhoIsPreced(int data1, int data2)
{
	if (data1 < data2)
		return 0;
	else
		return 1;
}