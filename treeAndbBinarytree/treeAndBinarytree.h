#include <iostream>
#include "../include/define.h"
using namespace std;


#ifndef _TREEDEFINE_
#define _TREEDEFINE_

/* 二叉树链式存储结构（二叉链表）定义 */
typedef struct BTNode
{
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
}BTNode;


/* 线索二叉树结点定义 */
typedef struct TBTNode
{
    char data;
    int ltag, rtag;
    struct TBTNode *lchild;
    struct TBTNode *rchild;    
}TBTNode;

#endif


/* 树与二叉树 */
void visitBTNode(BTNode *p);
void prefixOrderTravelling(BTNode *p);
void infixOrderTravelling(BTNode *p);
void postfixOrderTravelling(BTNode *p);
void level(BTNode *p);
int getWidth(BTNode *p);

void prefixOrderNonrecursion(BTNode *p);
void infixOrderNonrecursion(BTNode *p);
void postfixOrderNonrecursion(BTNode *p);

int comp(BTNode *p);
int getDepth(BTNode *p);
void search(BTNode *p, BTNode *&q, int key);

void createInThread(TBTNode *root);
void inThreadTravelling(TBTNode *root);

void createPreThread(TBTNode *root);
void preThreadTravelling(TBTNode *root);

void createPostThread(TBTNode *root);

BTNode *creatBT(int type, char preOrPostfix[], char infix[]);
