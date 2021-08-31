#include "../include/define.h"
#include "sort.h"


void simpleSelectSort(int array[], int n)
{
    // 每次从无序序列的起始位置开始操作，循环一次起始位置右移一位
    for (int i = 0; i < n; i++)
    {
        // 从该位置开始，向右扫描，挑出最小的关键字
        int k = i;
        for (int j = i; j < n; j++)
        {
            if (array[k] > array[j])
            {
                k = j;
            }
            
        }
        
        // 将扫描到的最小关键字与无序序列的第一个关键交换   
        int temp = array[k];
        array[k] = array[i];
        array[i] = temp;
    }
}