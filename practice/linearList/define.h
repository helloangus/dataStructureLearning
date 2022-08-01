#include <iostream>
using namespace std;

// 顺序表定义
#define MaxSize 50
typedef struct
{
	int data[MaxSize];
	int length;
}SqList;


void del_x();

void del_s2t();

void del_same();

void merge();

void exchange();