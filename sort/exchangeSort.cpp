#include "../include/define.h"
#include "sort.h"

void QuickSortFunction(int array[], int low, int high);

// 起泡（冒泡）排序算法
void bubbleSort(int array[], int n)
{
    // 设置无序序列最右端从n-1到1循环
    for (int i = n; i > 1; i--)
    {
        // 设置标记显示本趟是否发生了交换
        int flag = 0;
        // 从无序序列最左到最右循环操作
        for (int j = 1; j < i; j++)
        {
            // 若左边大于右边
            if (array[j-1] > array[j])
            {
                // 则二者交换
                int temp = array[j-1];
                array[j-1] = array[j];
                array[j] = temp;
                // 同时设置交换标记为1
                flag = 1;
            }
            
        }
        // 若本趟循环未发生关键字交换
        if (flag == 0)
        {
            // 证明序列已经有序，退出排序
            return;
        }

    }

}



// 快速排序主函数
void quickSort(int array[], int n)
{
    QuickSortFunction(array, 0, n-1);
}


// 快速排序递归函数
void QuickSortFunction(int array[], int low, int high)
{
    // 若low<high开始操作
    if (low < high)
    {
        // 初始化i，j
        int i = low;
        int j = high;
        // 取出序列的最左边的关键字作为数轴暂存
        int temp = array[i];
        // 当i<j时循环操作，目的是使小于枢轴的关键字都交换到左侧，大于的交换到右侧
        while (i < j)
        {
            // j从右向左扫描，当找到一个比枢轴小的关键字停下
            while (i < j && array[j] >= temp)
            {
                --j;
            }
            // 若此时i<j，则把扫描到的关键字放到i位置处
            if (i < j)
            {
                array[i] = array[j]; 
            }
            
            // i从左往右扫描，当找到一个比枢轴大或等于的关键字停下
            while (i < j && array[i] < temp)
            {
                ++i;                
            }
            // 若此时i<j，则把扫描到的关键字放到j位置处
            if (i < j)
            {
                array[j] = array[i];
            }
            
        }
        // 循环结束时，ij相等，把暂存的枢轴放到该位置上
        array[i] = temp;
        // 对枢轴左边的序列递归快排
        QuickSortFunction(array, low, i-1);
        // 对枢轴右边的序列递归快排   
        QuickSortFunction(array, i+1, high);
    }

}