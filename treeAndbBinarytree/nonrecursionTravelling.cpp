#include "../include/include.h"
#include "../include/define.h"

void prefixOrderNonrecursion(BTNode *p)
{
    // 树非空时
    if (p != NULL)
    {
        // 定义栈并初始化
        BTNode *Stack[maxSize];
        int top = -1;

        BTNode *q;
        // 根结点入栈
        ++top;
        Stack[top] = p;
        // 栈空退出循环
        while (top != -1)
        {
            // 出栈栈顶结点
             q = Stack[top];
             --top;
            // 访问结点
            visitBTNode(q);
            // 该结点右孩子存在则入栈右孩子
            if (q->rchild != NULL)
            {
                ++top;
                Stack[top] = q->rchild;
            }
            
            // 该结点左孩子存在则入栈左孩子
            if (q->lchild != NULL)
            {
                ++top;
                Stack[top] = q->lchild;
            }    
        }
               
    }
    
}


void infixOrderNonrecursion(BTNode *p)
{
    // 树非空
    if (p != NULL)
    {
        // 生成栈并初始化
        BTNode *Stack[maxSize];
        int top = -1;
        // 中间结点指针初始化为根结点
        BTNode *q = p;
        // 栈不空或中间结点指针不为空则循环（根结点出栈后时栈已经空了，但是p指向的根结点的右孩子，不为空，可继续循环）
        while (top != -1 || q != NULL)
        {
            // 当前结点左孩子存在时，循环入栈，结点指针移到其左孩子上（同时还起到若上轮循环出栈结点的右孩子存在则入栈的作用）
            while (q != NULL)   // 该句除了判断是否左孩子存在，同时还避免了在叶子结点的右孩子（NULL）进行循环操作
            {
                ++top;
                Stack[top] = q;
                q = q->lchild;
            }
            
            // 内层循环结束后，当栈不空时（某结点不可能只有右孩子，如果有右孩子则必有左孩子，这样该结点就必在栈中）
            if (top != -1)
            {
                // 出栈栈顶结点
                q = Stack[top];
                --top;
                // 访问结点
                visitBTNode(q);
                // 结点指针移到其右孩子上（当前结点的左孩子已经访问过三次了）   
                q = q->rchild;
            }
             
        }
        
    }
}


void postfixOrderNonrecursion(BTNode *p)
{
    // 树非空时
    if (p != NULL)
    {
        // 定义两个栈并初始化(Stack1与prefix中完全相同，所有出栈结点直接进入Stack2)
        BTNode *Stack1[maxSize];
        int top1 = -1;
        BTNode *Stack2[maxSize];
        int top2 = -1;

        BTNode *q;
        // 根结点入栈
        ++top1;
        Stack1[top1] = p;
        // 栈空退出循环
        while (top1 != -1)
        {
            // 出栈栈顶结点
             q = Stack1[top1];
             --top1;
            // 入栈Stack2
            ++top2;
            Stack2[top2] = q;

            // 相比prefix，左右孩子入栈顺序交换
            // 该结点左孩子存在则入栈左孩子
            if (q->lchild != NULL)
            {
                ++top1;
                Stack1[top1] = q->lchild;
            }
            // 该结点右孩子存在则入栈右孩子
            if (q->rchild != NULL)
            {
                ++top1;
                Stack1[top1] = q->rchild;
            }
            
        }
        // Stack2依次出栈，完成由逆后序遍历序列到后序遍历序列的转化
        while (top2 != -1)
        {
            q = Stack2[top2];
            --top2;
            visitBTNode(q);
        }
        

    }
    
}