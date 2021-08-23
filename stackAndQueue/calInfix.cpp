#include "../include/include.h"
#include "../include/define.h"

int calStackTopTwo(float s1[], int &top1, char s2[], int &top2);

float calInfix(char infix[])
{
    // 生成两个栈
    float s1[maxSize];
    char s2[maxSize];
    int top1 = -1;
    int top2 = -1;
    int i;

    // 从左往右扫描表达式
    while (infix[i] != '\0')
    {
        // 遇数字则压入s1，后移
        if ('0' <= infix[i] && infix[i] <= '9')
        {
            ++top1;
            s1[top1] = infix[i] - '0';
            ++i;
        }
        
        // 遇（则压入s2，后移
        else if (infix[i] == '(')
        {
            ++top2;
            s2[top2] = infix[i];
            ++i;
        }
        
        // 遇运算符
        else if (
            infix[i] == '+' ||
            infix[i] == '-' ||
            infix[i] == '*' ||
            infix[i] == '/')
        {
            // 栈空 || （ || 新运算符优先级大于s2栈顶运算符
            if (top2 == -1 ||
                s2[top2] == '(' || 
                getPriority(infix[i]) > getPriority(s2[top2])
            )
            {
            // 压入s2
                ++top2;
                s2[top2] = infix[i];
                ++i;
            }
            else {
            //          否则出栈栈顶运算符
                int flag = calStackTopTwo(s1, top1, s2, top2);
                if (flag == 0)
                {
                    return 0;
                }
                
            }
            
        }
        
        // 遇）则s2中到最近的（运算符全部出栈运算符，后移
        else if (infix[i] == ')')
        {
            while (s2[top2] != '(')
            {
                int flag = calStackTopTwo(s1, top1, s2, top2);
                if (flag == 0)
                {
                    return 0;
                }
            }
            --top2;
            ++i;
        }
        
    }
    
    // 表达式结束，所有运算符出栈运算
    while (top2 != -1)
    {
        int flag = calStackTopTwo(s1, top1, s2, top2);
        if (flag == 0)
        {
            return 0;
        }
    }
    
    return s1[top1];
}

int calStackTopTwo(float s1[], int &top1, char s2[], int &top2)
{
    float opand1;
    float opand2;
    float result;
    char op;
    int flag;
    opand2 = s1[top1];
    --top1;
    opand1 = s1[top1];
    --top1;
    op = s2[top2];
    --top2;
    flag = calSub(opand1, op, opand2, result);
    if (flag == 0)
    {
        cout<<"ERROR"<<endl;
    }
    ++top1;
    s1[top1] = result;
    return flag;
}