#include <iostream>
#include "ALGraphBFS.h"
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
	BFShowGraphVertex(&graph, A);
	cout << endl;
	BFShowGraphVertex(&graph, C);
	cout << endl;
	BFShowGraphVertex(&graph, E);
	cout << endl;
	BFShowGraphVertex(&graph, G);
	cout << endl;

	GraphDestroy(&graph);
	return 0;
}