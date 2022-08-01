#include "define.h"

void reverse(int A[], int s, int t)
{
    int temp;
    while(s < t)
    {
        temp = A[s];
        A[s] = A[t];
        A[t] = temp;
        ++s;
        --t;
    }

}

void exchange()
{
    int m = 5;
    int n = 6;
    int A[m+n] = {
        1, 2, 3, 4, 5,
        0, 9, 8, 7, 6, 5
    };
    reverse(A, 0, m+n-1);
    reverse(A, 0, n-1);
    reverse(A, n, m+n-1);

    for(int i = 0; i < m+n; ++i)
    {
        cout << "A[" << i << "] = " << A[i] << endl;
    }
    cout << endl;
}