#include "define.h"

void merge_work(SqList A, SqList B, SqList &C)
{
    int a, b, c;
    a = 0;
    b = 0;
    c = 0;

    while((a < A.length) && (b < B.length))
    {
        if(A.data[a] >= B.data[b])
        {
            C.data[c] = B.data[b];
            ++c;
            ++b;
        }
        else
        {
            C.data[c] = A.data[a];
            ++c;
            ++a;
        }
    }

    while(a < A.length)
    {
        C.data[c] = A.data[a];
        ++c;
        ++a;
    }

    while(b < B.length)
    {
        C.data[c] = B.data[b];
        ++c;
        ++b;
    }
    C.length = c;
}


void merge()
{
    SqList A,B,C;
    A.length = 0;
    B.length = 0;
    C.length = 0;

    A.data[0] = 1;
    A.data[1] = 2;
    B.data[0] = 3;
    B.data[1] = 3;
    A.data[2] = 4;
    B.data[2] = 5;
    A.data[3] = 6;
    A.data[4] = 7;
    B.data[3] = 8;
    B.data[4] = 9;

    A.length = 5;
    B.length = 5;
    C.length = 0;

    for(int i = 0; i < A.length; ++i)
    {
        cout << "A.data[" << i << "] = " << A.data[i] << endl;
    }
    cout << endl;

    for(int i = 0; i < B.length; ++i)
    {
        cout << "B.data[" << i << "] = " << B.data[i] << endl;
    }
    cout << endl;

    merge_work(A, B, C);

    for(int i = 0; i < C.length; ++i)
    {
        cout << "C.data[" << i << "] = " << C.data[i] << endl;
    }
    cout << endl;

}