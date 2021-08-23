#include "../include/include.h"
#include "../include/define.h"


int main()
{
    /* 构造一个简单的二叉树 */
    BTNode *A = (BTNode*)malloc(sizeof(BTNode));
    BTNode *B = (BTNode*)malloc(sizeof(BTNode));
    BTNode *C = (BTNode*)malloc(sizeof(BTNode));
    BTNode *D = (BTNode*)malloc(sizeof(BTNode));
    BTNode *E = (BTNode*)malloc(sizeof(BTNode));
    BTNode *F = (BTNode*)malloc(sizeof(BTNode));
    A->data = 'A'; B->data = 'B'; C->data = 'C'; D->data = 'D'; E->data = 'E'; F->data = 'F';
    A->lchild = B; A->rchild = C;
    B->lchild = D; B->rchild = NULL;
    C->lchild = E; C->rchild = F;
    D->lchild = NULL; D->rchild = NULL;
    E->lchild = NULL; E->rchild = NULL;
    F->lchild = NULL; F->rchild = NULL;

    prefixOrderTravelling(A);
    return 0;
}

