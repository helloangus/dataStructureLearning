#include "treeAndBinarytree.h"
#include "../include/define.h"


int main()
{

    char prefix[] = "*-5+43/21";
    char infix[] = "5-4+3*2/1";
    char postfix[] = "543+-21/*";

    cout<<endl;

    BTNode *root;
    root = creatBT(1, postfix, infix);
    postfixOrderTravelling(root);

    cout<<endl;

    return 0;
}

