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



void Sift(int array[], int low, int high);

// 堆排序函数（关键字从1开始标号）
void heapSort(int array[], int n)
{
    // 把输入数组直接当作完全二叉树，循环调整，建立初始堆
    for (int i = n/2; i >= 1; i--)  // 从第一个非叶结点开始调整
    {
        Sift(array, i, n);
    }
    
    // 进行n-1次循环，完成堆排序
    for (int i = n; i >= 2; i--)
    {
        // 把根结点关键字换到当前二叉树（堆）的最末端
        int temp = array[1];
        array[1] = array[i];
        array[i] = temp;
        // 执行堆调整函数   
        Sift(array, 1, i-1);
    }

}


// （大顶）堆的调整函数
void Sift(int array[], int low, int high)
{
    // 暂存当前结点值
    int temp = array[low];
    int i = low;
    int j = 2*i;
    // 循环直到堆末尾
    while (j <= high)
    {
        // 找到当前结点左右孩子的较大者
        if (array[j] < array[j+1] && j < high)
        {
            j = j + 1;
        }
        
        // 若当前结点值小于较大者，
        if (temp < array[j])
        {
            // 则较大者赋值到当前结点标记
            array[i] = array[j];
            // 同时当前结点的标记也同步移动
            i = j;
            // 孩子结点标记移动    
            j = 2 * i;
        }
        // 否则循环调整结束   
        else
        {
            break;
        }
    }
    // 当前结点值放入当前结点标记处
    array[i] = temp;
}