#include "../include/include.h"
#include "../include/define.h"

/* 基本四则运算的优先级判断 */
int getPriority(char op)
{
    switch (op)
    {
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}

/* 子表达式计算 */
int calSub(float opand1, char op, float opand2, float &result)
{
    switch (op)
    {
    case '+':
        result = opand1 + opand2;
        break;
    case '-':
        result = opand1 - opand2;
        break;
    case '*':
        result = opand1 * opand2;
        break;
    case '/':
        if (fabs(opand2) < MIN)
        {
            return 0;
        }
        else
        {
            result = opand1 / opand2;
        }
        break;
    default:
        return 0;
        break;
    }
    return 1;
}

/* 表达式长度计算 */
int calExpLength(char exp[])
{
    int length = 0;
    while (exp[length] != '\0')
    {
        ++length;
    }
    return length;
}

