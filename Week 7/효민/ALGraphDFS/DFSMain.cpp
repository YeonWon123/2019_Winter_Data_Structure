#include <iostream>
#include "ALGraphDFS.h"
using namespace std;

int main()
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

	DFShowGraphVertex(&graph, A);
	cout << "\n";
	DFShowGraphVertex(&graph, C);
	cout << "\n";
	DFShowGraphVertex(&graph, E);
	cout << "\n";
	DFShowGraphVertex(&graph, G);
	cout << "\n";

	GraphDestroy(&graph);
	return 0;
}