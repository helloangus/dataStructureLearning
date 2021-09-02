#include "../include/define.h"
#include "linearList.h"


int main()
{
    int a[] = {1,3,5,7,9};
    int b[] = {0,2,4,6,8};

    LNode *A;
    createListR(A, a, sizeof(a)/sizeof(int));
    LNode *B;
    createListR(B, b, sizeof(b)/sizeof(int));

    LNode *C;
    merge(A, B, C);

    cout<<endl;
    LNode *p = C->next;
    while (p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
    
}