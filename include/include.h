#include <iostream>
#include <math.h>
#include "../include/define.h"
using namespace std;

int infixToPreFix(char infix[], char s2[], int &top2);
int infixToPostFix(char infix[], char s2[], int &top2);
float calPrefix(char prefix[]);
float calInfix(char infix[]);
float calPostfix(char postfix[]);

int calExpLength(char exp[]);
int getPriority(char opt);
int calSub(float opand1, char op, float opand2, float &result);

/* 树与二叉树 */
void visit(BTNode *p);
void prefixOrderTravelling(BTNode *p);
void infixOrderTravelling(BTNode *p);
void postfixOrderTravelling(BTNode *p);