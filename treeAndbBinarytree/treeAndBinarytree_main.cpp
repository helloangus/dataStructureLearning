#include "treeAndBinarytree.h"
#include "../include/define.h"


int main()
{

    char prefix[] = "*-5+43/21";
    char infix[] = "5-4+3*2/1";
    char postfix[] = "543+-21/*";
    char level[] = "*-/5+2143";

    cout<<endl;

    BTNode *root;
    root = creatBT(2, level, infix);
    prefixOrderTravelling(root);

    cout<<endl;

    return 0;
}

