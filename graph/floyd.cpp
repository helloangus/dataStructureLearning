#include "../include/define.h"
#include "graph.h"


void printPath(int u, int v,int Path[][maxSize], int Dist[][maxSize]);



// 求任意一对顶点间最短路径的弗洛伊德算法
void Floyd(MGraph *g)
{
    // 初始化Path和Dist数组
    int Path[maxSize][maxSize];
    int Dist[maxSize][maxSize];
    for (int i = 0; i < g->n; i++)
    {
        for (int j = 0; j < g->n; j++)
        {
            Dist[i][j] = g->edges[i][j];
            Path[i][j] = -1;
        }
        
    }
    
    // 把图中所有结点当作中间结点循环操作
    for (int k = 0; k < g->n; k++)
    {
        // 循环检测任意一对结点间的最短路径
        for (int i = 0; i < g->n; i++)
        {
            for (int j = 0; j < g->n; j++)
            {
                // 若两结点的最短路径大于以当前结点为中间结点的最短路径
                if (Dist[i][j] > Dist[i][k] + Dist[k][j])
                {
                    // 则更新这一对结点的最短路径和中间结点   
                    Dist[i][j] = Dist[i][k] + Dist[k][j];
                    Path[i][j] = k;
                }
            }
            
        }
        
    }

    for (int i = 0; i < g->n; i++)
    {
        for (int j = 0; j < g->n; j++)
        {
            cout<<endl;
            cout<<"<"<<i<<", "<<j<<">: "<<endl;
            printPath(i, j, Path, Dist);
            cout<<endl;
            cout<<Dist[i][j]<<endl;
            cout<<endl;
        }
        
    }
    
    
}


// 输出由u到v的最短路径及其长度
void printPath(int u, int v,int Path[][maxSize], int Dist[][maxSize])
{
    if (Dist[u][v] < INF)
    {
        // 若uv间有直接边相连，直接输出边
        if (Path[u][v] == -1)
        {
            cout<<" <"<<u<<", "<<v<<">,";
        }
        // 否则分段处理mid前半段和后半段
        else
        {
            int mid = Path[u][v];
            printPath(u, mid, Path, Dist);
            printPath(mid, v, Path, Dist);
        }
    }
    
}