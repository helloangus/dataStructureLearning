#include "treeAndBinarytree.h"
#include "../include/define.h"


BTNode *CreateBT_fromPreAndInfix(char prefix[], char infix[], int L1, int R1, int L2, int R2);
BTNode *CreateBT_fromPostAndInfix(char postfix[], char infix[], int L1, int R1, int L2, int R2);
BTNode *CreateBT_fromLevelAndInfix(char level[], char infix[], int n, int L, int R);

int SearchIndexInArray(char array[], char key, int L, int R);
void GetSubLevel(char subLevel[], char level[], char infix[], int n, int L, int R);

/* type若为0，则输入前序和中序遍历序列构造二叉树，
   type若为1，则输入后序和中序遍历序列构造二叉树，
   type若为2，则输入层次和中序遍历序列构造二叉树 */
BTNode *creatBT(int type, char preOrPostfixOrLevel[], char infix[])
{

    int length = 0;

    while (preOrPostfixOrLevel[length] != '\0')
    {
        ++length;
    }
    

    if (type == 2)
    {
        return CreateBT_fromLevelAndInfix(preOrPostfixOrLevel, infix, length, 0, length-1);
    }
    else if (type == 1)
    {
        return CreateBT_fromPostAndInfix(preOrPostfixOrLevel, infix, 0, length-1, 0, length-1);
    }
    else
    {
        return CreateBT_fromPreAndInfix(preOrPostfixOrLevel, infix, 0, length-1, 0, length-1);
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


BTNode *CreateBT_fromLevelAndInfix(char level[], char infix[], int n, int L, int R)
{
    // 若序列中没有元素，返回NULL
    if (L > R)
    {
        return NULL;
    }
    
    // 申请新结点并初始化，将当前子树根结点的数据赋值给新结点
    BTNode *s = (BTNode*)malloc(sizeof(BTNode));
    s->lchild = NULL;
    s->rchild = NULL;
    s->data = level[0];
    // 在infix中找到根结点的位置
    int i = SearchIndexInArray(infix, level[0], L, R);

    int LN = i - L;
    int RN = R - i;
    char LLevel[LN];
    char RLevel[RN];
    /* 根据infix中左右子树的分界点i左边的元素，
    在level中依次搜索，并保持原有顺序，生成新的sublevel */
    GetSubLevel(LLevel, level, infix, n, L, i-1);
    /* 根据infix中左右子树的分界点i右边的元素，
    在level中依次搜索，并保持原有顺序，生成新的sublevel */
    GetSubLevel(RLevel, level, infix, n, i+1, R);
    // 递归生成左子树并赋值给当前结点的左孩子
    s->lchild = CreateBT_fromLevelAndInfix(LLevel, infix, LN, L, i-1);
    // 递归生成右子树并赋值给当前结点的右孩子
    s->rchild = CreateBT_fromLevelAndInfix(RLevel, infix, RN, i+1, R);
    // 返回根结点
    return s;
}


int SearchIndexInArray(char array[], char key, int L, int R)
{
    for (int i = L; i <= R; ++i)
    {
        if (array[i] == key)
        {
            return i;
        }
        
    }
    return -1;
}



// 根据查找level中在infix某子树的结点，并按其原顺序建立新level
void GetSubLevel(char subLevel[], char level[], char infix[], int n, int L, int R)
{
    int k = 0;
    // 保证sublevel中结点顺序与level中一致
    for (int i = 0; i < n; ++i)
    {
        if (SearchIndexInArray(infix, level[i], L, R) != -1)
        {
            subLevel[k] = level[i];
            ++k;
        }
              
    }
    
}
