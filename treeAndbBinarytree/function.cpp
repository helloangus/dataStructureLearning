#include "../include/include.h"
#include "../include/define.h"

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

// TODO: int getWidth();


// 带剪枝操作的节点搜索函数（即仅在左子树中未找到时才在右子树中查找）
void search(BTNode *p, BTNode *&q, int key)
{
    // 若为空树，保持不变（不可以返回NULL，因为在叶子节点的孩子节点中搜索的时候必为空树，可能重置q）
    if (p != NULL)
    {
        // 若当前节点hit，p赋值给q
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