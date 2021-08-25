#include "treeAndBinarytree.h"
#include "../include/define.h"

void InThread(TBTNode *p, TBTNode *&pre);
TBTNode *First(TBTNode *p);
TBTNode *Next(TBTNode *p);
TBTNode *Last(TBTNode *p);
TBTNode *Prior(TBTNode *p);

void PreThread(TBTNode *p, TBTNode *&pre);
void PostThread(TBTNode *p, TBTNode *&pre);

void visitTBTNode(TBTNode *p);


/* 中序线索二叉树上中序遍历操作 */
void inThreadTravelling(TBTNode *root)
{
    for (TBTNode *p = First(root); p != NULL; p = Next(p))
    {
        visitTBTNode(p);
    }
}


/* 通过中序遍历建立中序线索二叉树的主程序 */
void createInThread(TBTNode *root)
{
    if (root != NULL)
    {
        TBTNode *pre = NULL;
        InThread(root, pre);

        // 后处理中序最后一个结点
        pre->rchild = NULL;
        pre->rtag = 1;
    }

}


/* 中序递归遍历二叉树并线索化 */
void InThread(TBTNode *p, TBTNode *&pre)
{
    // 树非空时
    if (p != NULL)
    {
        // 递归遍历左子树线并索化
        InThread(p->lchild, pre);
        // 若左孩子指针空，建立前驱线索
        if (p->lchild == NULL)
        {
            p->lchild = pre;
            p->ltag = 1;
        }
        
        // 若前驱结点存在且其右孩子指针空，建立前驱结点的后继线索
        if (pre != NULL && pre->rchild == NULL)
        {
            pre->rchild = p;
            pre->rtag = 1;
        }
        
        // pre后移到当前结点
        pre = p;
        // 递归遍历右子树线并索化   
        InThread(p->rchild, pre);
    }
}


/* 求以p为根的中序线索二叉树中的第一个结点（最左结点） */
TBTNode *First(TBTNode *p)
{
    // 左孩子存在则循环继续
    while (p->ltag == 0)
    {
        p = p->lchild;
    }
    // 返回最左下结点
    return p;
}



/* 求结点p在中序线索二叉树的后继结点 */
TBTNode *Next(TBTNode *p)
{
    // 若存在右子树，则求右子树的第一个结点
    if (p->rtag == 0)
    {
        return First(p->rchild);
    }
    // 否则直接返回后继线索
    return p->rchild;
}


/* 求以p为根的中序线索二叉树中的最后一个结点 */
TBTNode *Last(TBTNode *p)
{
    // 右孩子存在则循环继续
    while (p->rtag == 0)
    {
        p = p->rchild;
    }
    // 返回最右下结点
    return p;
}


/* 求结点p在中序线索二叉树的前驱结点 */
TBTNode *Prior(TBTNode *p)
{
    // 若存在左子树，则求左子树的最后一个结点
    if (p->ltag == 0)
    {
        return Last(p->lchild);
    }
    // 否则直接返回前驱线索
    return p->lchild;
}


/* 前序线索二叉树上中序遍历操作 */
void preThreadTravelling(TBTNode *root)
{
    // 树非空时
    if (root != NULL)
    {
        // 根结点指针赋值给中间指针
        TBTNode *p = root; 
        // 当指针不为空时保持循环（即走到最右结点时退出循环）
        while (p != NULL)
        {
            // 当左指针不是线索时，循环
            while (p->ltag != 1)
            {
                // 访问当前结点，并向左下移动
                visitTBTNode(p);
                p = p->lchild;   
            }
            // 退出循环时，左指针必为线索，首先访问当前结点
            visitTBTNode(p);
            // 此时其右指针若空则为最右结点，若非空则为其后继结点，移动到其后继       
            p = p->rchild;
        }
    }
}

/* 通过前序遍历建立中序线索二叉树的主程序 */
void createPreThread(TBTNode *root)
{
    if (root != NULL)
    {
        TBTNode *pre = NULL;
        PreThread(root, pre);

        // 后处理前序最后一个结点
        pre->rchild = NULL;
        pre->rtag = 1;
    }

}


/* 前序递归遍历二叉树并线索化 */
void PreThread(TBTNode *p, TBTNode *&pre)
{
    // 树非空时
    if (p != NULL)
    {
        // 若左孩子指针空，建立前驱线索
        if (p->lchild == NULL)
        {
            p->lchild = pre;
            p->ltag = 1;
        }
        // 若前驱结点存在且其右孩子指针空，建立前驱结点的后继线索
        if (pre != NULL && pre->rchild == NULL)
        {
            pre->rchild = p;
            pre->rtag = 1;
        }
        
        // pre后移到当前结点
        pre = p;
        // 左孩子指针不是线索时，递归遍历
        if (p->ltag != 1)
        {
            PreThread(p->lchild, pre);
        }
        
        // 右孩子指针不是线索时，递归遍历
        if (p->rtag != 1)
        {
            PreThread(p->rchild, pre);
        }
        
    }
}


/* 通过后序遍历建立中序线索二叉树的主程序 */
void createPostThread(TBTNode *root)
{
    if (root != NULL)
    {
        TBTNode *pre = NULL;
        PostThread(root, pre);

        // 后处理后序最后一个结点
        pre->rchild = NULL;
        pre->rtag = 1;
    }

}


/* 后序递归遍历二叉树并线索化 */
void PostThread(TBTNode *p, TBTNode *&pre)
{
    // 树非空时
    if (p != NULL)
    {
        // 递归遍历左子树线并索化
        PostThread(p->lchild, pre);
        // 递归遍历右子树线并索化   
        PostThread(p->rchild, pre);
        // 若左孩子指针空，建立前驱线索
        if (p->lchild == NULL)
        {
            p->lchild = pre;
            p->ltag = 1;
        }
        
        // 若前驱结点存在且其右孩子指针空，建立前驱结点的后继线索
        if (pre != NULL && pre->rchild == NULL)
        {
            pre->rchild = p;
            pre->rtag = 1;
        }
        
        // pre后移到当前结点
        pre = p;
    }
}


void visitTBTNode(TBTNode *p)
{
    cout<<p->data<<endl;
}