#include "../include/define.h"
#include "graph.h"

// 边数组的结构体定义
typedef struct
{
    int a, b;   // a, bw为一条边的两个顶点
    int weight; // 边的权值
}Road;


void generateRoad(MGraph *g, Road *road);
void sort(Road *road, int edgeNum);
int getRoot(int v[], int a);

// 最小生成树的克鲁斯卡尔算法，返回生成树的权值
int Kruskal(MGraph *g)
{
    // 定义并查集
    int v[maxSize] = {0};
    // 初始化并查集的各自根结点为本身
    for (int i = 0; i < g->n; i++)
    {
        v[i] = g->vex[i].no;
    }
    
    // 生成边数组
    Road road[maxSize];
    generateRoad(g, road);
    // 整理边数组，使其权值按从小到大排序
    sort(road, g->e);
    // 对边数组循环
    int sum = 0;
    for (int i = 0; i < g->e; i++)
    {
        // 获取边的两结点在并查集中的根
        int a = getRoot(v, road[i].a);
        int b = getRoot(v, road[i].b);
        // 若两个根不相同（两结点在并查集中不属于同一棵树）
        if (a != b)
        {
            // 则把a挂到b结点上
            v[a] = b;
            // 更新生成树权值       
            sum += road[i].weight;
        }
        
    }
    return sum;
}


// 根据输入邻接矩阵生成边数组
void generateRoad(MGraph *g, Road *road)
{
    int edgeNum = 0;
    // 只扫描矩阵的下半三角
    for (int i = 0; i < g->n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (g->edges[i][j] != 0 && g->edges[i][j] != INF)
            {
                road[edgeNum].a = i;
                road[edgeNum].b = j;
                road[edgeNum].weight = g->edges[i][j];
                ++edgeNum;
            }
            
        }
        
    }
    
}


// 按从小到大顺序排序数组
void sort(Road *road, int edgeNum)
{
    for (int i = 0; i < edgeNum; i++)
    {
        int maxWeight = 0;
        int k = 0;
        for (int j = 0; j < edgeNum - i; j++)
        {
            if (road[j].weight > maxWeight)
            {
                maxWeight = road[j].weight;
                k = j;
            }
            
        }
        Road temp = road[edgeNum-1-i];
        road[edgeNum-1-i] = road[k];
        road[k] = temp;
        
    }
    
}


// 在并查集中查找根结点的函数
int getRoot(int v[], int a)
{
    // 当未到达根结点时继续向上爬
    while (a != v[a])
    {
        a = v[a];
    }
    return a;
}
