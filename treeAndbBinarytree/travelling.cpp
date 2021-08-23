#include "../include/include.h"
#include "../include/define.h"

void prefixOrderTravelling(BTNode *p)
{
    if (p != NULL)
    {
        // 访问根节点
        visit(p);

        prefixOrderTravelling(p->lchild);  // 先序遍历左子树
        prefixOrderTravelling(p->rchild);  // 先序遍历右子树
    }
    
}

void infixOrderTravelling(BTNode *p)
{
    if (p != NULL)
    {
        infixOrderTravelling(p->lchild);  // 中序遍历左子树
        // 访问根节点
        visit(p);
        infixOrderTravelling(p->rchild);  // 中序遍历右子树
    }
    
}

void postfixOrderTravelling(BTNode *p)
{
    if (p != NULL)
    {       
        postfixOrderTravelling(p->lchild);  // 后序遍历左子树
        postfixOrderTravelling(p->rchild);  // 后序遍历右子树
        // 访问根节点
        visit(p);
    }
    
}

void level(BTNode *p)
{
    // 树非空
    if (p != NULL)
    {
        // 建立循环队列
        int front, rear;
        BTNode *que[maxSize];
        front = rear = 0;
        // 出队元素指针
        BTNode *q;
        // 根节点入队
        rear = (rear + 1) % maxSize;
        que[rear] = p;
        // 队列不空时循环
        while (rear != front)
        {
            // 出队元素
            front = (front + 1) % maxSize;
            q = que[front];
            // 访问元素
            visit(q);
            // 若左子树存在，则左子树根节点入队
            if (q->lchild != NULL)
            {
                rear = (rear + 1) % maxSize;
                que[rear] = q->lchild;
            }
            // 若右子树存在，则右子树根节点入队
            if (q->rchild)
            {
                rear = (rear + 1) % maxSize;
                que[rear] = q->rchild;
            }
        }
    }
}