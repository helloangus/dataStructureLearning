#include "../include/include.h"
#include "../include/define.h"

void prefixOrderTravelling(BTNode *p)
{
    if (p != NULL)
    {
        visit(p);

        prefixOrderTravelling(p->lchild);  // 先序遍历左子树
        prefixOrderTravelling(p->rchild);  // 先序遍历右子树
    }
    
}

void infixOrderTravelling(BTNode *p)
{
    if (p != NULL)
    {
        infixOrderTravelling(p->lchild);  // 先序遍历左子树
        visit(p);
        infixOrderTravelling(p->rchild);  // 先序遍历右子树
    }
    
}

void postfixOrderTravelling(BTNode *p)
{
    if (p != NULL)
    {       
        postfixOrderTravelling(p->lchild);  // 先序遍历左子树
        postfixOrderTravelling(p->rchild);  // 先序遍历右子树
        visit(p);
    }
    
}