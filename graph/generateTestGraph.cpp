#include "../include/define.h"
#include "graph.h"

void generateaGraph(AGraph *&aGraph_undirected, MGraph *&mGraph_undirected, AGraph *&aGraph_directed)
{
    // 无向图
    aGraph_undirected = (AGraph*)malloc(sizeof(AGraph));
    aGraph_undirected->n = 5;
    aGraph_undirected->e = 5;

    aGraph_undirected->adjList[0].data = 'A';
    aGraph_undirected->adjList[0].firstArc = (ArcNode*)malloc(3*sizeof(ArcNode));
    aGraph_undirected->adjList[0].firstArc->adjvex = 3;
    aGraph_undirected->adjList[0].firstArc->nextArc = aGraph_undirected->adjList[0].firstArc + 1;
    aGraph_undirected->adjList[0].firstArc->nextArc->adjvex = 2;
    aGraph_undirected->adjList[0].firstArc->nextArc->nextArc = aGraph_undirected->adjList[0].firstArc + 2;
    aGraph_undirected->adjList[0].firstArc->nextArc->nextArc->adjvex = 1;
    aGraph_undirected->adjList[0].firstArc->nextArc->nextArc->nextArc = NULL;

    aGraph_undirected->adjList[1].data = 'B';
    aGraph_undirected->adjList[1].firstArc = (ArcNode*)malloc(1*sizeof(ArcNode));
    aGraph_undirected->adjList[1].firstArc->adjvex = 0;
    aGraph_undirected->adjList[1].firstArc->nextArc = NULL;

    aGraph_undirected->adjList[2].data = 'C';
    aGraph_undirected->adjList[2].firstArc = (ArcNode*)malloc(2*sizeof(ArcNode));
    aGraph_undirected->adjList[2].firstArc->adjvex = 3;
    aGraph_undirected->adjList[2].firstArc->nextArc = aGraph_undirected->adjList[2].firstArc + 1;
    aGraph_undirected->adjList[2].firstArc->nextArc->adjvex = 0;
    aGraph_undirected->adjList[2].firstArc->nextArc->nextArc = NULL;

    aGraph_undirected->adjList[3].data = 'D';
    aGraph_undirected->adjList[3].firstArc = (ArcNode*)malloc(2*sizeof(ArcNode));
    aGraph_undirected->adjList[3].firstArc->adjvex = 4;
    aGraph_undirected->adjList[3].firstArc->nextArc = aGraph_undirected->adjList[3].firstArc + 1;
    aGraph_undirected->adjList[3].firstArc->nextArc->adjvex = 2;
    aGraph_undirected->adjList[3].firstArc->nextArc->nextArc = aGraph_undirected->adjList[3].firstArc + 2;
    aGraph_undirected->adjList[3].firstArc->nextArc->nextArc->adjvex = 0;
    aGraph_undirected->adjList[3].firstArc->nextArc->nextArc->nextArc = NULL;

    aGraph_undirected->adjList[4].data = 'E';
    aGraph_undirected->adjList[4].firstArc = (ArcNode*)malloc(1*sizeof(ArcNode));
    aGraph_undirected->adjList[4].firstArc->adjvex = 3;
    aGraph_undirected->adjList[4].firstArc->nextArc = NULL;


    // 无向图
    mGraph_undirected = (MGraph *)malloc(sizeof(MGraph));
    mGraph_undirected->n = 5;
    mGraph_undirected->e = 8;
    for (int i = 0; i < mGraph_undirected->n; i++)
    {
        mGraph_undirected->vex[i].no = i;
        mGraph_undirected->vex[i].info = 'A' + i;    
    }
    for (int i = 0; i < mGraph_undirected->n; i++)
    {
        for (int j = 0; j < mGraph_undirected->n; j++)
        {
            if (i == j)
            {
                mGraph_undirected->edges[i][j] = 0;
            }
            else
            {
                mGraph_undirected->edges[i][j] = INF;
            }
        }
        
    }
    
    mGraph_undirected->edges[0][1] = 5; mGraph_undirected->edges[0][2] = 1; mGraph_undirected->edges[0][3] = 2; 
    mGraph_undirected->edges[1][0] = 5; mGraph_undirected->edges[1][2] = 3; mGraph_undirected->edges[1][4] = 4; 
    mGraph_undirected->edges[2][0] = 1; mGraph_undirected->edges[2][1] = 3; mGraph_undirected->edges[2][3] = 6; mGraph_undirected->edges[2][4] = 2; 
    mGraph_undirected->edges[3][0] = 2; mGraph_undirected->edges[3][2] = 6; mGraph_undirected->edges[3][4] = 3; 
    mGraph_undirected->edges[4][1] = 4; mGraph_undirected->edges[4][2] = 2; mGraph_undirected->edges[4][3] = 3; 


    // 有向图
    aGraph_directed = (AGraph*)malloc(sizeof(AGraph));
    aGraph_directed->n = 5;
    aGraph_directed->e = 6;

    aGraph_directed->adjList[0].data = 'A';
    aGraph_directed->adjList[0].firstArc = (ArcNode*)malloc(3*sizeof(ArcNode));
    aGraph_directed->adjList[0].firstArc->adjvex = 1;
    aGraph_directed->adjList[0].firstArc->nextArc = aGraph_directed->adjList[0].firstArc + 1;
    aGraph_directed->adjList[0].firstArc->nextArc->adjvex = 2;
    aGraph_directed->adjList[0].firstArc->nextArc->nextArc = aGraph_directed->adjList[0].firstArc + 2;
    aGraph_directed->adjList[0].firstArc->nextArc->nextArc->adjvex = 3;
    aGraph_directed->adjList[0].firstArc->nextArc->nextArc->nextArc = NULL;

    aGraph_directed->adjList[1].data = 'B';
    aGraph_directed->adjList[1].firstArc = (ArcNode*)malloc(1*sizeof(ArcNode));
    aGraph_directed->adjList[1].firstArc->adjvex = 4;
    aGraph_directed->adjList[1].firstArc->nextArc = NULL;

    aGraph_directed->adjList[2].data = 'C';
    aGraph_directed->adjList[2].firstArc = (ArcNode*)malloc(1*sizeof(ArcNode));
    aGraph_directed->adjList[2].firstArc->adjvex = 4;
    aGraph_directed->adjList[2].firstArc->nextArc = NULL;

    aGraph_directed->adjList[3].data = 'D';
    aGraph_directed->adjList[3].firstArc = (ArcNode*)malloc(1*sizeof(ArcNode));
    aGraph_directed->adjList[3].firstArc->adjvex = 4;
    aGraph_directed->adjList[3].firstArc->nextArc = NULL;

    aGraph_directed->adjList[4].data = 'E';
    aGraph_directed->adjList[4].firstArc = NULL;

    inputStatistic(aGraph_directed);
    outputStatistic(aGraph_directed);

}