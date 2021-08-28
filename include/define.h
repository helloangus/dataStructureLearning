#ifndef _GLOBALDEFINE_
#define _GLOBALDEFINE_

#define maxSize 6
#define MIN 1e-6

/* 单链表 */
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode;


/* 二叉树链式存储结构（二叉链表）定义 */
typedef struct BTNode
{
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
}BTNode;


/* 线索二叉树结点定义 */
typedef struct TBTNode
{
    char data;
    int ltag, rtag;
    struct TBTNode *lchild;
    struct TBTNode *rchild;    
}TBTNode;





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

#endif