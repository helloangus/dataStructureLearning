#include "../include/include.h"
#include "../include/define.h"

void prefixOrderTravelling(BTNode *bt)
{
    if (bt != NULL)
    {
        // 访问根结点
        visit(bt);

        prefixOrderTravelling(bt->lchild);  // 先序遍历左子树
        prefixOrderTravelling(bt->rchild);  // 先序遍历右子树
    }
    
}

void infixOrderTravelling(BTNode *bt)
{
    if (bt != NULL)
    {
        infixOrderTravelling(bt->lchild);  // 中序遍历左子树
        // 访问根结点
        visit(bt);
        infixOrderTravelling(bt->rchild);  // 中序遍历右子树
    }
    
}

void postfixOrderTravelling(BTNode *bt)
{
    if (bt != NULL)
    {       
        postfixOrderTravelling(bt->lchild);  // 后序遍历左子树
        postfixOrderTravelling(bt->rchild);  // 后序遍历右子树
        // 访问根结点
        visit(bt);
    }
    
}

