#include "../include/define.h"
#include "graph.h"


void printfPath(int path[], int a);

// 求某一顶点到其余顶点最短路径的迪杰斯特拉算法
void Dijkstra(MGraph *g, int v0)
{
    // 初始化dist、path、set数组
    int dist[maxSize];
    int path[maxSize];
    int set[maxSize];

    for (int i = 0; i < g->n; i++)
    {
        dist[i] = g->edges[v0][i];
        set[i] = 0;
        if (g->edges[v0][i] < INF)
        {
            path[i] = v0;
        }
        else
        {
            path[i] = -1;
        }
    }
    set[v0] = 1;
    path[v0] = -1;
    
    // 对剩余n-1个顶点循环操作
    for (int i = 0; i < g->n-1; i++)
    {
        // 暂存到根结点路径最短的顶点
        int min = INF;
        int u;
        // 循环在剩余顶点中找出一个到根结点路径最短的
        for (int j = 0; j < g->n; j++)
        {
            if (set[j] != 1 && dist[j] < min)
            {
                u = j;
                min = dist[j];
            }
            
        }
        
        // 并入到最短路径中
        set[u] = 1;
        // 以刚并入的顶点为中间点，对剩余顶点循环检测
        for (int j = 0; j < g->n; j++)
        {
            // 若新顶点的加入使得通往某顶点的最短路径变短
            if (set[j] != 1 && dist[u]+g->edges[u][j] < dist[j])
            {
                // 更新最短路径及其长度
                path[j] = u;
                dist[j] = dist[u] + g->edges[u][j];
            }   
        }
    }
    /* 函数结束时，dist[]中存放了v0点到其余顶点的最短路径长度，
    path[]中存放了其最短路径 */
    for (int i = 0; i < g->n; i++)
    {
        cout<<"From "<<v0<<" to "<<i<<endl;
        printfPath(path, i);
        cout<<dist[i]<<endl;
        cout<<endl;
    }
    
}


// 逆向输出到某节点的最短路径
void printfPath(int path[], int a)
{
    int stack[maxSize];
    int top = -1;
    // 从叶子结点依次入栈
    while (path[a] != -1)
    {
        ++top;
        stack[top] = a;
        a = path[a];
    }
    ++top;
    stack[top] = a;
    // 依次出栈打印
    while (top != -1)
    {
        cout<<stack[top]<<" ";
        --top;
    }
    cout<<endl;
    
}





