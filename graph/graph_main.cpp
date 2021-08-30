#include "../include/define.h"
#include "graph.h"


int main()
{
    AGraph *aGraph_undirected;
    MGraph *mGraph_undirected;
    AGraph *aGraph_directed;
    generateaGraph(aGraph_undirected, mGraph_undirected, aGraph_directed);

    cout<<endl;
    if (topSort(aGraph_directed) != 0)
    {
        cout<<"ERROR"<<endl;
    } 
    cout<<endl;

}