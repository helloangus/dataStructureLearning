#include "../include/define.h"
#include "linearList.h"


// 根据输入数组用尾插法建立单链表
void createListR(LNode *&C, int array[], int n)
{
    // 申请C的头结点空间，完成链表初始化
    C = (LNode *)malloc(sizeof(LNode));
    C->next = NULL;
    // 定义指向新申请的结点指针s和链表尾部结点的指针r
    LNode *s;
    LNode *r = C;
    // 循环申请n个结点接受数组中元素，并将结点链接到r的后面
    for (int i = 0; i < n; i++)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = array[i];
        r->next = s;
        r = r->next;
    }
    
    // 链表尾部设为NULL
    r->next = NULL;
}


// 两条升序单链表的归并操作，生成升序单链表
void merge(LNode *A, LNode *B, LNode *&C)
{
    // 定义p跟踪A的最小值结点
    LNode *p = A->next;
    // 定义q跟踪B的最小值结点
    LNode *q = B->next;
    // 指定C的头结点为A的头结点
    C = A;
    C->next = NULL;
    // 释放B的头结点
    free(B);
    // 定义r跟踪C的终端结点
    LNode *r = C;
    // 当p与q都不空时，选择较小的插入c的尾部，对应的指针后移一位
    while (p != NULL && q != NULL)
    {
        if (p->data > q->data)
        {
            r->next = q;
            q = q->next;
            r = r->next;
        }
        else
        {
            r->next = p;
            p = p->next;
            r= r->next;
        }
    }
    r->next = NULL;
    // 若循环结束，p或q中还有剩余链表，则直接链接再c的尾部
    if (p != NULL)
    {
        r->next = p;
    }
    if (q != NULL)
    {
        r->next = q;
    }
    
    
}