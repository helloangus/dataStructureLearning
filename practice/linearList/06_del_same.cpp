#include "define.h"

void del_same_work(SqList &L)
{
    int temp = L.data[0];
    int index = 1;
    int count = 0;

    for(int i = 1; i < L.length; ++i)
    {
        if(L.data[i] != temp)
        {
            L.data[index] = L.data[i];
            temp = L.data[i];
            index = index + 1;
        }
        else
        {
            ++count;
        }
    }
    L.length -= count;
    return;
}

void del_same()
{
    // init
    SqList L;
    L.length = 0;

    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 2;
    L.data[3] = 2;
    L.data[4] = 5;
    L.data[5] = 5;
    L.data[6] = 9;
    L.data[7] = 12;
    L.data[8] = 22;

    L.length = 9;

    for(int i = 0; i < L.length; ++i)
    {
        cout << "L.data[" << i << "] = " << L.data[i] << endl;
    }
    
    cout << endl << endl;

    del_same_work(L);

    for(int i = 0; i < L.length; ++i)
    {
        cout << "L.data[" << i << "] = " << L.data[i] << endl;
    }

    cout << endl << endl;

}