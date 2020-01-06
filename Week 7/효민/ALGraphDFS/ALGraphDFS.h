#ifndef __AL_GRAPH_DFS__
#define __AL_GRAPH_DFS__
#include "DLinkedList.h"

//������ �̸����� ���ȭ
enum { A, B, C, D, E, F, G, H, I, J };

typedef struct _ual
{
	int numV;
	int numE;
	List* adjList;
	int* visitInfo;
}ALGraph;

//�׷����� �ʱ�ȭ
void GraphInit(ALGraph* pg, int nv);

//�׷����� ���ҽ� ����
void GraphDestroy(ALGraph* pg);

//������ �߰�
void AddEdge(ALGraph* pg, int fromV, int toV);

//������ ���� ���
void ShowGraphEdgeInfo(ALGraph* pg);

//������ ���� ���(DFS)
void DFShowGraphVertex(ALGraph* pg, int stratV);

#endif // !__AL_GRAPH_DFS__
