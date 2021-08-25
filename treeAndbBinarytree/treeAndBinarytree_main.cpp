#include "treeAndBinarytree.h"
#include "../include/define.h"


int main()
{
    /* 构造一个简单的二叉树 */
    TBTNode *A = (TBTNode*)malloc(sizeof(TBTNode));
    TBTNode *B = (TBTNode*)malloc(sizeof(TBTNode));
    TBTNode *C = (TBTNode*)malloc(sizeof(TBTNode));
    TBTNode *D = (TBTNode*)malloc(sizeof(TBTNode));
    TBTNode *E = (TBTNode*)malloc(sizeof(TBTNode));
    TBTNode *F = (TBTNode*)malloc(sizeof(TBTNode));
    TBTNode *G = (TBTNode*)malloc(sizeof(TBTNode));
    TBTNode *H = (TBTNode*)malloc(sizeof(TBTNode));
    TBTNode *I = (TBTNode*)malloc(sizeof(TBTNode));
    
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


    A->ltag = 0; A->rtag = 0;
    B->ltag = 0; B->rtag = 0;
    C->ltag = 0; C->rtag = 0;
    D->ltag = 0; D->rtag = 0;
    E->ltag = 0; E->rtag = 0;
    F->ltag = 0; F->rtag = 0;
    G->ltag = 0; G->rtag = 0;
    H->ltag = 0; H->rtag = 0;
    I->ltag = 0; I->rtag = 0;

// TODO: 根据前序和中序遍历序列构造二叉树
// TODO: 根据后序和中序遍历序列构造二叉树

    cout<<endl;

    createPreThread(A);
    preThreadTravelling(A);

    cout<<endl;

    return 0;
}

