#include "define.h"
#include "include.h"

float calPrefix(char prefix[])
{
    float s[maxSize];
    int top = -1;
    int length = 0;
    // 计算表达式长度
    length = calExpLength(prefix);
    // 从右往左扫描
    for (int i = length - 1; i >= 0; --i)
    {
        // 是数字则入栈
        if ('0' <= prefix[i] && prefix[i] <= '9')
        {
            ++top;
            s[top] = prefix[i] - '0';
        }
        else
        {
            // 是运算符则出栈两个操作数（先出在左）运算，运算结果入栈    
            float opand1;
            float opand2;
            float result;
            char op;
            int flag;
            opand1 = s[top];
            --top;
            opand2 = s[top];
            --top;
            op = prefix[i];
            flag = calSub(opand1, op, opand2, result);
            if (flag == 0)
            {
                cout<<"ERROR"<<endl;
                return 0;
            }
            ++top;
            s[top] = result;
        }
        
    }
    
    return s[top];
}