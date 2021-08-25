#include "treeAndBinarytree.h"
#include "../include/define.h"


BTNode *CreateBT_fromPreAndInfix(char prefix[], char infix[], int L1, int R1, int L2, int R2);
BTNode *CreateBT_fromPostAndInfix(char postfix[], char infix[], int L1, int R1, int L2, int R2);


/* isPostfix若为0，则输入前序和中序遍历序列构造二叉树，
   isPostfix若为1，则输入后序和中序遍历序列构造二叉树 */
BTNode *creatBT(bool isPostfix, char preOrPostfix[], char infix[])
{

    int length1 = 0;
    int length2 = 0;

    while (infix[length1] != '\0')
    {
        ++length1;
    }
    while (preOrPostfix[length2] != '\0')
    {
        ++length2;
    }
    

    if (isPostfix == 1)
    {
        return CreateBT_fromPostAndInfix(preOrPostfix, infix, 0, length1-1, 0, length2-1);
    }
    else
    {
        return CreateBT_fromPreAndInfix(preOrPostfix, infix, 0, length1-1, 0, length2-1);
    }
}

/* 根据输入的中序遍历序列和前序遍历序列(及其对应两端的数组下标)构造二叉树 */
BTNode *CreateBT_fromPreAndInfix(char prefix[], char infix[], int L1, int R1, int L2, int R2)
{

    // 若序列中没有元素，则树为空，返回NULL
    if (L1 > R1)
    {
        return NULL;
    }
    
    // 申请根结点空间，并初始化
    BTNode *s = (BTNode*)malloc(sizeof(BTNode));
    s->lchild = NULL;
    s->rchild = NULL;
    // 将当前子树根结点的数据赋值给新申请的结点
    s->data = prefix[L1];

    // 查找等于当前子树根结点（位于prefix[L1]上）在infix中的位置
    int i = 0;
    for (i = L2; i <= R2; ++i)
    {
        if (infix[i] == prefix[L1])
        {
            break;
        }
        
    }

    /* 通过在infix中找到的分界点i，确定prefix和infix中当前子树的左子树范围，
    并递归建立其左子树，将左子树的树根连接在当前树根的左指针域上 */
    s->lchild = CreateBT_fromPreAndInfix(prefix, infix, L1+1, L1+i-L2, L2, i-1);

    /* 通过在infix中找到的分界点i，确定prefix和infix中当前子树的右子树范围，
    并递归建立其右子树，将右子树的树根连接在当前树根的右指针域上 */
    s->rchild = CreateBT_fromPreAndInfix(prefix, infix, L1+i-L2+1, R1, i+1, R2);

    // 当前子树处理完毕，返回根结点s
    return s;
}


BTNode *CreateBT_fromPostAndInfix(char postfix[], char infix[], int L1, int R1, int L2, int R2)
{
    // 若序列中没有元素，则树为空，返回NULL
    if (L1 > R1)
    {
        return NULL;
    }
    
    // 申请根结点空间并初始化
    BTNode *s = (BTNode*)malloc(sizeof(BTNode));
    s->lchild = NULL;
    s->rchild = NULL;
    // 将当前子树根结点（位于postfix[R1]上）的数据赋值给新申请的结点
    s->data = postfix[R1];
    // 查找等于当前子树根结点在infix中的位置
    int i;
    for ( i = L2; i <= R2; ++i)
    {
        if (infix[i] == postfix[R1])
        {
            break;
        }
        
    }
    
    /* 通过在infix中找到的分界点i，确定postfix和infix中当前子树的左子树范围，
    并递归建立其左子树，将左子树的树根连接在当前树根的左指针域上 */
    s->lchild = CreateBT_fromPostAndInfix(postfix, infix, L1, L1+i-L2-1, L2, i-1);
    /* 通过在infix中找到的分界点i，确定postfix和infix中当前子树的右子树范围，
    并递归建立其右子树，将右子树的树根连接在当前树根的右指针域上 */
    s->rchild = CreateBT_fromPostAndInfix(postfix, infix, L1+i-L2, R1-1, i+1, R2);
    // 当前子树处理完毕，返回根结点s
    return s;
}