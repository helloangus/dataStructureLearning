#include "../include/include.h"
#include "../include/define.h"

float calPostfix(char postfix[])
{
    float s[maxSize];
    int top = -1;

    // 从左往右扫描
    for (int i = 0; postfix[i] != '\0'; ++i)
    {
        // 是数字则入栈
        if ('0' <= postfix[i] && postfix[i] <= '9')
        {
            ++top;
            s[top] = postfix[i] - '0';
        }
        else
        {
            // 是运算符则出栈两个操作数（先出在右）运算，运算结果入栈    
            float opand1;
            float opand2;
            float result;
            char op;
            int flag;
            opand2 = s[top];
            --top;
            opand1 = s[top];
            --top;
            op = postfix[i];
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