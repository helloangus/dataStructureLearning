#include "../include/define.h"
#include "graph.h"



/* 最小生成树的普里姆算法，返回最小生成树的权值 */
int Prim(MGraph *g, int v0)
{
    // 定义lowcost和vset数组
    int lowcost[maxSize] = {0};
    int vset[maxSize] = {0};
    
    // 载入v0各边的权值（即edges数组的值）    
    for (int i = 0; i < g->n; ++i)
    {
        lowcost[i] = g->edges[v0][i];
    }
    
    // v0入树
    int v = v0;  // 用于暂存入树顶点
    vset[v] = 1;

    int sum = 0;    // 最小生成树权值
    // 对剩余的n-1个顶点重复如下操作
    for (int i = 0; i < g->n-1; ++i)
    {
        // 设定所有边的最小值min为INF
        int min = INF;
        // 对到所有的顶点的边循环
        int k = 0;  // 暂存当前扫描到的最短边
        for (int j = 0; j < g->n; j++)
        {
            // 找出侯选边（所连接的顶点未入树）的最小者（小于min）
            if (vset[j] != 1 && lowcost[j] < min)
            {
                // 保存该边所连接的顶点信息
                k = j;
                // 更新min
                min = lowcost[j];
            }
            
        }
        // 最小边连接的顶点入树，并更新最小生成树权值
        v = k;
        vset[v] = 1;
        sum += min;
        // 考察所有剩余顶点到刚入树顶点的权值
        for (int j = 0; j < g->n; j++)
        {
            // 若比lowcost中的值小
            if (vset[j] != 1 && g->edges[v][j] < lowcost[j])
            {
                // 则更新对应lowcost的值
                lowcost[j] = g->edges[v][j];
            }
            
        }
        
    }
    
    // 返回最小生成树权值
    return sum;
}