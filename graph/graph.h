#include <iostream>
#include "../include/define.h"
using namespace std;

#ifndef _GRAPHDEFINE_
#define _GRAPHDEFINE_

/* 图的邻接表存储结构 */
// 边结点定义
typedef struct ArcNode
{
    int adjvex;     // 该边所指向的结点的位置
    struct ArcNode *nextArc;    // 指向下一条边的指针
    int info;       // 该边的相关信息（如权值）
}ArcNode;

// 顶点结点定义
typedef struct
{
    char data;      // 顶点信息
    ArcNode *firstArc;  // 指向第一条边的指针
}VNode;

// 图的定义
typedef struct
{
    VNode adjList[maxSize]; // 邻接表
    int n,e;                // 顶点数和边数
}AGraph;


/* 图的邻接矩阵存储结构 */
// 顶点结点定义
typedef struct
{
    int no;     // 顶点编号
    char info;  // 顶点其他信息
}VertexType;

// 图的定义
typedef struct
{
    float edges[maxSize][maxSize];  // 邻接矩阵定义（默认有权图）
    int n, e;                       // 顶点数和边数
    VertexType vex[maxSize];        // 存放结点信息
}MGraph;




#endif

void generateaGraph(AGraph *&aGraph, MGraph *&mGraph);
void visit(VNode *p);

void DFS_main(AGraph *G);
void BFS_main(AGraph *G);

int Prim(MGraph *g, int v0);
int Kruskal(MGraph *g);

void Dijkstra(MGraph *g, int v0);