#include "../include/define.h"
#include "sort.h"



// 起泡（冒泡）排序算法
void bubbleSort(int array[], int n)
{
    // 设置无序序列长度从n-1到1循环
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