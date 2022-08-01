#include "define.h"

#define INPUT 1

void del_x_work(SqList &L, int i, int j, int x, int k)
{
	if(i > j) return;

	if(L.data[i] == x)
	{
		--L.length;
		return del_x_work(L, ++i, j, x, ++k);
	}
	else
	{
		L.data[i-k] = L.data[i];
		return del_x_work(L, ++i, j, x, k);
	}
}

void del_x()
{
        int x = INPUT;
        // init
        SqList L;
        L.length = 0;

        // input test bench
        L.data[0] = 1;
        L.data[1] = 9;
        L.data[2] = 7;
        L.data[3] = 1;
        L.data[4] = 1;
        L.length = 5;

	for(int i = 0; i < L.length; ++i)
	{
		cout << L.data[i] << " ";
	}
	cout << endl;

        // work
        del_x_work(L, 0, 5-1, x, 0);

	for(int i = 0; i < L.length; ++i)
        {
                cout << L.data[i] << " ";
        }
        cout << endl;

        return;
}
