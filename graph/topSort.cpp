#include "../include/define.h"
#include "graph.h"


// 拓扑排序算法，若返回值为-1，则图中存在环路，操作失败
int topSort(AGraph *g)
{
    // 定义并初始化栈
    int stack[maxSize];
    int top = -1;
    // 调用入度统计函数
    inputStatistic(g);
    // 将图中入度为0的顶点入栈
    for (int i = 0; i < g->n; i++)
    {
        if (g->adjList[i].inputCount == 0)
        {
            ++top;
            stack[top] = i;
        }
        
    }
    
    // 栈非空时循环
    int n = 0;  // 用于统计出栈顶点个数
    while (top != -1)
    {
        // 栈顶出栈，输出
        int k = stack[top];
        --top;
        visit(&g->adjList[k]);
        // 统计出栈顶点个数
        ++n;
        // 遍历所有当前顶点所引出边指向的结点
        ArcNode *p = g->adjList[k].firstArc;
        while (p != NULL)
        {
            // 将其入度减一
            --(g->adjList[p->adjvex].inputCount);
            // 若入度变为0，则入栈
            if (g->adjList[p->adjvex].inputCount == 0)
            {
                ++top;
                stack[top] = p->adjvex;
            }
            p = p->nextArc;
        }
        
    }
    
    // 若循环结束时，统计得到的出栈顶点个数与n相同，则操作成功
    if (n == g->n)
    {
        return 0;
    }
    // 否则输入图存在环路，操作失败
    else
    {
        return -1;
    }
}