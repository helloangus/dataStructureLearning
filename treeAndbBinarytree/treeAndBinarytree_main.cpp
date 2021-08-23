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
    BTNode *G = (BTNode*)malloc(sizeof(BTNode));
    BTNode *H = (BTNode*)malloc(sizeof(BTNode));
    BTNode *I = (BTNode*)malloc(sizeof(BTNode));
    
    A->data = '*';
    B->data = '-'; C->data = '/';
    D->data = '5'; E->data = '+'; F->data = '2'; G->data = '1';
    H->data = '4'; I->data = '3';

    A->lchild = B;  A->rchild = C;
    B->lchild = D;  B->rchild = E;
    C->lchild = F;  C->rchild = G;
    D->lchild = NULL;   D->rchild = NULL;
    E->lchild = H;  E->rchild = I;
    F->lchild = NULL; F->rchild = NULL;
    G->lchild = NULL; G->rchild = NULL;
    H->lchild = NULL; H->rchild = NULL;
    I->lchild = NULL; I->rchild = NULL;

    cout<<endl;

    level(A);

    cout<<endl;

    return 0;
}

