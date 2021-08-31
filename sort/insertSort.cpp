#include "../include/define.h"
#include "sort.h"

// 直接插入排序
void directInsertSort(int array[], int n)
{
    // 令第0个关键字为有序序列，从第1个关键字开始循环插入
    for (int i = 1; i < n; i++)
    {
        // 将待插入关键字暂存
        int temp = array[i];
        /* 从有序序列的最右边（即待插入关键字的左边）向左循环扫描，
        若扫描到的关键字大于插入关键字，则将其向右移一位，循环继续 */
        int j = i-1;
        while (j >= 0 && array[j] > temp)
        {
            array[j+1] = array[j];
            --j;
        }
        /* 退出循环时，循环标记指向有序序列中刚好小于等于插入关键字的关键字，
        因此将暂存的关键字放在循环标记的右侧 */
        array[j+1] = temp;
    }
}