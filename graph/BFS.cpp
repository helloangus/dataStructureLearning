#include "../include/define.h"
#include "graph.h"


void BFS(AGraph *G, int visitMark[], int v);

// 广度优先搜索遍历的主函数
void BFS_main(AGraph *G)
{
    // 顶点访问标记数组，初始化为0，表示所有顶点都未被访问
    int visitMark[maxSize] = {0};
    BFS(G, visitMark, 0);
}


// 按广度优先搜索顶点
void BFS(AGraph *G, int visitMark[], int v)
{
    // 访问顶点
    visitMark[v] = 1;
    visit(&G->adjList[v]);
    // 定义循环队列
    int queue[maxSize];
    int front = 0, rear = 0;
    // 顶点入队
    rear = (rear+1)%maxSize;
    queue[rear] = v;
    // 当队列不空时循环
    int u;  // 出队元素临时变量
    ArcNode *p;
    while (front != rear)
    {
        // 出队
        front = (front+1)%maxSize;
        u = queue[front];
        // 依次检查出队顶点的所有邻接顶点
        p = G->adjList[u].firstArc;
        while (p != NULL)
        {
            // 访问没有访问过的邻接顶点并将其入队    
            if (visitMark[p->adjvex] == 0)
            {
                visitMark[p->adjvex] = 1;
                visit(&G->adjList[p->adjvex]);

                rear = (rear+1)%maxSize;
                queue[rear] = p->adjvex;
            }
            p = p->nextArc;
        }
        
    }

}