#include <iostream>
using namespace std;

#ifndef _LINEARLISTDEFINE_
#define _LINEARLISTDEFINE_


/* 单链表 */
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode;



#endif

void createListR(LNode *&C, int array[], int n);
void merge(LNode *A, LNode *B, LNode *&C);