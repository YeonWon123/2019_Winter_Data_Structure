#include <stdio.h>
#include "ALGraphDFS.h"

int main(void)
{
	ALGraph graph;
	GraphInit(&graph, 7);

	AddEdge(&graph, A, B);
	AddEdge(&graph, A, D);
	AddEdge(&graph, B, C);
	AddEdge(&graph, D, C);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, F);
	AddEdge(&graph, E, G);

	ShowGraphEdgeInfo(&graph);

	DFSshowGraphVertex(&graph, A); printf("\n");
	DFSshowGraphVertex(&graph, C); printf("\n");
	DFSshowGraphVertex(&graph, E); printf("\n");
	DFSshowGraphVertex(&graph, G); printf("\n");

	GraphDestroy(&graph);
	return 0;


}