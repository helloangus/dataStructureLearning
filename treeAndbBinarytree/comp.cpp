#include "treeAndBinarytree.h"
#include "../include/define.h"

int op(int opandA,int opandB, char op);

// 计算操作数为一位整数的存储在二叉树中表达式的值
int comp(BTNode *p)
{
    // 判断是否为空树
    if (p !=NULL)
    {
        // 生成两个中间变量
        int opandA, opandB;
        // 若不是叶子结点
        if (p->lchild != NULL && p->rchild != NULL)
        {
            // 计算（返回）两个孩子结点的值
            opandA = comp(p->lchild);
            opandB = comp(p->rchild);
            // 计算当前结点的值，并返回    
            return op(opandA, opandB, p->data);
        }
        // 否则返回该结点的值
        else
        {
            return p->data - '0';
        }
    }
    // 若为空则返回0
    else
    {
        return 0;
    }
}


// 整数运算，不判断除数是否为0
int op(int opandA, int opandB, char op)
{
    if (op == '+')
    {
        return opandA + opandB;
    }
    else if (op == '-')
    {
        return opandA - opandB;
    }
    else if (op == '*')
    {
        return opandA * opandB;
    }
    else if (opandB != 0)
    {
        return opandA / opandB;
    }
    else
    {
        return 0;
    }
    
}