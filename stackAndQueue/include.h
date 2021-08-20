#include <iostream>
#include <math.h>
using namespace std;

int infixToPreFix(char infix[], char s2[], int &top2);
int infixToPostFix(char infix[], char s2[], int &top2);
float calPrefix(char prefix[]);
float calInfix(char infix[]);
float calPostfix(char postfix[]);

int calExpLength(char exp[]);
int getPriority(char opt);
int calSub(float opand1, char op, float opand2, float &result);