#include "stackAndQueue.h"
#include "../include/define.h"

/* 中缀转前缀，s2为结果栈，top2为栈顶指针 */
int infixToPreFix(char infix[], char s2[], int &top2)
{
    // 中间栈
    char s1[maxSize] = {'\0'};
    int top1 = -1;
    int length = 0;
    int i;

    length = calExpLength(infix);    
    i = length - 1;

    while (i >= 0)
    {
        if (('0' <= infix[i] && infix[i] <= '9') || ('a' <= infix[i] && infix[i] <= 'Z'))
        {
            ++top2;
            s2[top2] = infix[i];
            --i;
        }
        else if (infix[i] == ')')
        {
            ++top1;
            s1[top1] = infix[i];
            --i;
        }
        /* 运算符判断时，若s1出栈会循环判断，直到infix[i]入栈 */
        else if (
            infix[i] == '+' ||
            infix[i] == '-' ||
            infix[i] == '*' ||
            infix[i] == '/' )
        {
            if (
                top1 == -1 ||
                s1[top1] == ')' ||
                getPriority(infix[i]) >= getPriority(s1[top1]))
            {
                ++top1;
                s1[top1] = infix[i];
                --i;
            }
            else
            {
                ++top2;
                s2[top2] = s1[top1];
                --top1;
            }
        }
        else if (infix[i] == '(')
        {
            while (s1[top1] != ')')
            {
                ++top2;
                s2[top2] = s1[top1];
                --top1;
            }
            --top1; // 丢弃括号
            --i;
        }
        else return 1;
    }
    while (top1!= -1)
    {
        ++top2;
        s2[top2] = s1[top1];
        --top1;
    }

    /* 逆序 */
    i = 0;
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        ++i;
    }
    top1 = i - 1;
    top2 = -1;
    while (top1!= -1)
    {
        ++top2;
        s2[top2] = s1[top1];
        --top1;
    }
    
    
    return 0;
}

