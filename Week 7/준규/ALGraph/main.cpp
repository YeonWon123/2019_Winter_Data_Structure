/*

vertex에 연결된 edge의 수가 짝수여야 한붓 그리기 가능.

*/

#include <stdio.h>
#include "ALGraph.h"

int main(void)
{
	ALGraph graph;
	GraphInit(&graph, 5);

	AddEdge(&graph, A, B);
	AddEdge(&graph, A, D);
	AddEdge(&graph, B, C);
	AddEdge(&graph, C, D);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, A);

	ShowGraphEdgeInfo(&graph);
	GraphDestory(&graph);

	return 0;
}