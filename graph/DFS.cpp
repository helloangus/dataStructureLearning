#include "../include/define.h"
#include "graph.h"

void DFS(AGraph *G, int visitMark[], int v);

// 深度优先搜索遍历的主函数
void DFS_main(AGraph *G)
{
    // 顶点访问标记数组，初始化为0，表示所有顶点都未被访问
    int visitMark[maxSize] = {0};
    DFS(G, visitMark, 0);
}

// 按深度优先搜索顶点
void DFS(AGraph *G, int visitMark[], int v)
{
    // 置已访问标记
    visitMark[v] = 1;
    // 访问顶点
    visit(&G->adjList[v]);
    // 定义边的遍历指针p
    ArcNode *p;
    // p指向顶点v的第一条边
    p = G->adjList[v].firstArc;
    // 当p不为空时保持循环（即走到没有边了）
    while (p != NULL)
    {
        // 若该边所指向的顶点未被访问，则递归访问它
        if (visitMark[p->adjvex] != 1)
        {
            DFS(G, visitMark, p->adjvex);
        }
        
        // p指向下一条边    
        p = p->nextArc;
    }
    
    /* 若在此处使用visit函数，则输出的是逆拓扑排序序列 */
}