#include "../include/define.h"
#include "sort.h"


int main()
{
    int array[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int n = sizeof(array)/sizeof(int);

    cout<<endl;

    heapSort(array, n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }

    cout<<endl;
}