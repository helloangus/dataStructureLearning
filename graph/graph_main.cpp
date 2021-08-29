#include "../include/define.h"
#include "graph.h"

int main()
{
    AGraph *aGraph;
    MGraph *mGraph;
    generateaGraph(aGraph, mGraph);

    cout<<endl;
    Dijkstra(mGraph, 3);
    cout<<endl;

}