#include "treeAndBinarytree.h"
#include "../include/define.h"


void visitBTNode(BTNode *p)
{
    cout<<p->data<<endl;
}

// 计算二叉树深度
int getDepth(BTNode *p)
{
    // 当是空树时，返回深度0
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        // 计算左右子树的深度
        int LD, RD;
        LD = getDepth(p->lchild);
        RD = getDepth(p->rchild);
        // 返回左右子树最大深度加一
        return ((LD>=RD) ? LD : RD) + 1;
    }
    
}


// 求二叉树的宽度和深度（具有结点数最多的那层的结点个数）
int getWidth(BTNode *p)
{
    // 新增一个可以存储结点层号的结构体
    typedef struct
    {
        BTNode *p;
        int lno;
    }St;

    // 二叉树非空时
    if (p != NULL)
    {
        // 生成一个足够长的非循环队列
        St que[maxSize];
        int front, rear;
        front = rear = 0;

        int Lno = 0;
        BTNode *q;
        // 树根入列
        ++rear;
        que[rear].p = p;
        // 树根层号设为1
        que[rear].lno = 1;
        // 队列非空时循环
        while (rear != front)
        {
            // 出队元素
            ++front;
            q = que[front].p;
            // 获取当前元素层号
            Lno = que[front].lno;
            // 若左子树存在，左子树根结点入队，层号为当前层号加一
            if (q->lchild != NULL)
            {
                ++rear;
                que[rear].p = q->lchild;
                que[rear].lno = Lno + 1;
            }
            // 若右子树存在，右子树根结点入队，层号为当前层号加一    
            if (q->rchild != NULL)
            {
                ++rear;
                que[rear].p = q->rchild;
                que[rear].lno = Lno + 1;
            }
            
        }
        // 循环结束，此时的当前元素层号也就是二叉树的深度
        // 在队列中分层搜索，找到最多的某层的结点数    
        int max = 0;
        for (int i = 1; i <= Lno; ++i)
        {
            int n = 0;
            for (int j = 0; j <= rear; ++j)
            {
                if (que[j].lno == i)
                {
                    ++n;
                }
            }
            if (max < n)
            {
                max = n;
            }
        }
        return max;
    }
    // 空树直接返回0
    else
    {
        return 0;
    }
}


void level(BTNode *p)
{
    // 树非空
    if (p != NULL)
    {
        // 建立循环队列
        BTNode *que[maxSize];
        int front, rear;
        front = rear = 0;
        // 出队元素指针
        BTNode *q;
        // 根结点入队
        rear = (rear + 1) % maxSize;
        que[rear] = p;
        // 队列不空时循环
        while (rear != front)
        {
            // 出队元素
            front = (front + 1) % maxSize;
            q = que[front];
            // 访问元素
            visitBTNode(q);
            // 若左子树存在，则左子树根结点入队
            if (q->lchild != NULL)
            {
                rear = (rear + 1) % maxSize;
                que[rear] = q->lchild;
            }
            // 若右子树存在，则右子树根结点入队
            if (q->rchild)
            {
                rear = (rear + 1) % maxSize;
                que[rear] = q->rchild;
            }
        }
    }
}


// 带剪枝操作的结点搜索函数（即仅在左子树中未找到时才在右子树中查找）
void search(BTNode *p, BTNode *&q, int key)
{
    // 若为空树，保持不变（不可以返回NULL，因为在叶子结点的孩子结点中搜索的时候必为空树，可能重置q）
    if (p != NULL)
    {
        // 若当前结点hit，bt赋值给q
        if (p->data == key)
        {
            q = p;
        }
        else
        {
            // 现在左子树中查找
            search(p->lchild, q, key);
            // 若未找到，则继续在右子树中查找        
            if (q == NULL)
            {
                search(p->rchild, q, key);
            }
            
        }
        
    }
    
    
}