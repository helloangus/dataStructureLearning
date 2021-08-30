#include "../include/define.h"
#include "graph.h"

void visit(VNode *p)
{
    cout<<p->data<<endl;
}


// 有向图入度统计
void inputStatistic(AGraph *g)
{
    for (int i = 0; i < g->n; i++)
    {
        g->adjList[i].inputCount = 0;
    }
    
    // 对每个点循环操作
    for (int i = 0; i < g->n; i++)
    {
        // 扫描所有引出的边
        ArcNode *p = g->adjList[i].firstArc;
        while (p != NULL)
        {
            // 边存在，则将指向顶点的入度加一 
            ++(g->adjList[p->adjvex].inputCount);
            p = p->nextArc;
        }
        
    }
}

// 有向图出度统计
void outputStatistic(AGraph *g)
{
    for (int i = 0; i < g->n; i++)
    {
        g->adjList[i].outputCount = 0;
    }
    // 对每个点循环操作
    for (int i = 0; i < g->n; i++)
    {
        // 统计每个点引出的边
        ArcNode *p = g->adjList[i].firstArc;
        while (p != NULL)
        {
            ++(g->adjList[i].outputCount);
            p = p->nextArc;
        }
            
    }
    
}