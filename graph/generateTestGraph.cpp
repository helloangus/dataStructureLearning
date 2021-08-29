#include "../include/define.h"
#include "graph.h"

void generateaGraph(AGraph *&aGraph, MGraph *&mGraph)
{
    aGraph = (AGraph*)malloc(sizeof(AGraph));
    aGraph->n = 5;
    aGraph->e = 5;

    aGraph->adjList[0].data = 'A';
    aGraph->adjList[0].firstArc = (ArcNode*)malloc(3*sizeof(ArcNode));
    aGraph->adjList[0].firstArc->adjvex = 3;
    aGraph->adjList[0].firstArc->nextArc = aGraph->adjList[0].firstArc + 1;
    aGraph->adjList[0].firstArc->nextArc->adjvex = 2;
    aGraph->adjList[0].firstArc->nextArc->nextArc = aGraph->adjList[0].firstArc + 2;
    aGraph->adjList[0].firstArc->nextArc->nextArc->adjvex = 1;
    aGraph->adjList[0].firstArc->nextArc->nextArc->nextArc = NULL;

    aGraph->adjList[1].data = 'B';
    aGraph->adjList[1].firstArc = (ArcNode*)malloc(1*sizeof(ArcNode));
    aGraph->adjList[1].firstArc->adjvex = 0;
    aGraph->adjList[1].firstArc->nextArc = NULL;

    aGraph->adjList[2].data = 'C';
    aGraph->adjList[2].firstArc = (ArcNode*)malloc(2*sizeof(ArcNode));
    aGraph->adjList[2].firstArc->adjvex = 3;
    aGraph->adjList[2].firstArc->nextArc = aGraph->adjList[2].firstArc + 1;
    aGraph->adjList[2].firstArc->nextArc->adjvex = 0;
    aGraph->adjList[2].firstArc->nextArc->nextArc = NULL;

    aGraph->adjList[3].data = 'D';
    aGraph->adjList[3].firstArc = (ArcNode*)malloc(2*sizeof(ArcNode));
    aGraph->adjList[3].firstArc->adjvex = 4;
    aGraph->adjList[3].firstArc->nextArc = aGraph->adjList[3].firstArc + 1;
    aGraph->adjList[3].firstArc->nextArc->adjvex = 2;
    aGraph->adjList[3].firstArc->nextArc->nextArc = aGraph->adjList[3].firstArc + 2;
    aGraph->adjList[3].firstArc->nextArc->nextArc->adjvex = 0;
    aGraph->adjList[3].firstArc->nextArc->nextArc->nextArc = NULL;

    aGraph->adjList[4].data = 'E';
    aGraph->adjList[4].firstArc = (ArcNode*)malloc(1*sizeof(ArcNode));
    aGraph->adjList[4].firstArc->adjvex = 3;
    aGraph->adjList[4].firstArc->nextArc = NULL;


    mGraph = (MGraph *)malloc(sizeof(MGraph));
    mGraph->n = 5;
    mGraph->e = 8;
    for (int i = 0; i < mGraph->n; i++)
    {
        mGraph->vex[i].no = i;
        mGraph->vex[i].info = 'A' + i;    
    }
    for (int i = 0; i < mGraph->n; i++)
    {
        for (int j = 0; j < mGraph->n; j++)
        {
            if (i == j)
            {
                mGraph->edges[i][j] = 0;
            }
            else
            {
                mGraph->edges[i][j] = INF;
            }
        }
        
    }
    
    mGraph->edges[0][1] = 5; mGraph->edges[0][2] = 1; mGraph->edges[0][3] = 2; 
    mGraph->edges[1][0] = 5; mGraph->edges[1][2] = 3; mGraph->edges[1][4] = 4; 
    mGraph->edges[2][0] = 1; mGraph->edges[2][1] = 3; mGraph->edges[2][3] = 6; mGraph->edges[2][4] = 2; 
    mGraph->edges[3][0] = 2; mGraph->edges[3][2] = 6; mGraph->edges[3][4] = 3; 
    mGraph->edges[4][1] = 4; mGraph->edges[4][2] = 2; mGraph->edges[4][3] = 3; 
}