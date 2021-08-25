#include "stackAndQueue.h"
#include "../include/define.h"

int main()
{
    char prefix[maxSize] = {'\0'};
    char infix[maxSize] = {'\0'};
    char postfix[maxSize] = {'\0'};
    float result;

    cout<<endl;
    cin>>infix;
    result = calInfix(infix);
    cout<<result<<endl;

    return 0;
}