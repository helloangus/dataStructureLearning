#include "../include/include.h"
#include "../include/define.h"

void prefixOrderTravelling(BTNode *p)
{
    if (p != NULL)
    {
        // 访问根结点
        visitBTNode(p);

        prefixOrderTravelling(p->lchild);  // 先序遍历左子树
        prefixOrderTravelling(p->rchild);  // 先序遍历右子树
    }
    
}

void infixOrderTravelling(BTNode *p)
{
    if (p != NULL)
    {
        infixOrderTravelling(p->lchild);  // 中序遍历左子树
        // 访问根结点
        visitBTNode(p);
        infixOrderTravelling(p->rchild);  // 中序遍历右子树
    }
    
}

void postfixOrderTravelling(BTNode *p)
{
    if (p != NULL)
    {       
        postfixOrderTravelling(p->lchild);  // 后序遍历左子树
        postfixOrderTravelling(p->rchild);  // 后序遍历右子树
        // 访问根结点
        visitBTNode(p);
    }
    
}

