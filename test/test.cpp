#include <iostream>
#include "../include/define.h"
using namespace std;


int main()
{
    LNode *A = (LNode *)malloc(sizeof(LNode));
    LNode *B = (LNode *)malloc(sizeof(LNode));
    LNode *C = (LNode *)malloc(sizeof(LNode));
    A->data = 1; B->data = 2; C->data = 3;
    A->next = B; B->next = C;

    cout<<A->next->next->data<<endl;
    return 0;
}