#include <iostream>
#include "../include/define.h"
using namespace std;


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

BTNode *creatBT(bool isPostfix, char preOrPostfix[], char infix[]);