#include "../include/define.h"
#include "sort.h"


void Merge(int array[], int low, int mid, int high);
void MergeSortFunction(int array[], int low, int high);

// 二路归并主函数
void mergeSort(int array[], int n)
{
    MergeSortFunction(array, 0, n-1);
}

// 二路归并排序递归函数
void MergeSortFunction(int array[], int low, int high)
{
    // 当序列存在时（序列中关键字个数大于0，即low<high）时操作
    if (low < high)
    {
        int mid = (low+high)/2;
        // 递归归并排序前半段
        MergeSortFunction(array, low, mid);
        // 递归归并排序后半段
        MergeSortFunction(array, mid+1, high);
        // 归并前后两段升序序列    
        Merge(array, low, mid, high);
    }
    
}



// 归并数组中两个升序序列为升序序列
void Merge(int array[], int low, int mid, int high)
{
    // 定义临时数组存放两条序列的值
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = array[low+i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = array[mid+1+i];
    }

    // 定义跟踪两条序列的最小值下标
    int i = 0;
    int j = 0;
    int k = low;

    // 当i、j都在对应序列范围内时循环操作
    while (i < n1 && j < n2)
    {
        // 选择较小者存入array对应位置
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            ++i;
        }
        else
        {
            array[k] = R[j];
            ++j;
        }
        ++k;
    }
    // 若某个序列中还有元素，则全部赋值到array中
    while (i < n1)
    {
        array[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2)
    {
        array[k] = R[j];
        ++j;
        ++k;
    }
    
}