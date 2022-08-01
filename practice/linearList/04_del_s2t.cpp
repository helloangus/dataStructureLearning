#include "define.h"

#define INPUT_S 20
#define INPUT_T 30


bool del_s2t_work(SqList &L, int s, int t)
{
    if(L.length <= 0 || s >= t)
    {
        return false;
    }

    int index = -1;
    int count = 0;
    for(int i = 0; i < L.length; ++i)
    {
        if((L.data[i] >= s) && (L.data[i] <= t))
        {
            ++count;
        }
        else
        {
            ++index;
            L.data[index] = L.data[i];
        }
    }

    L.length -= count;

    return true;
}


void del_s2t()
{
    int s = INPUT_S;
    int t = INPUT_T;

    // init
    SqList L;
    L.length = 0;

    // input test bench
    for(int i = 0; i < MaxSize; ++i)
    {
        L.data[i] = i;
    }
    L.length = MaxSize;


    for(int i = 0; i < L.length; ++i)
    {
        cout << "L.data[" << i << "] = " << L.data[i] << endl;
    }

    cout << endl << endl;

    int ret = del_s2t_work(L, s, t);
    if(ret == false)
    {
        cout << "Error" << endl;
        return;
    }
    for(int i = 0; i < L.length; ++i)
    {
        cout << "L.data[" << i << "] = " << L.data[i] << endl;
    }

    return;
}