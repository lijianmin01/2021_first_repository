#include<stdio.h>
#include<stdlib.h>

/*树的双亲表示法*/
#define MAX_TREE_SIZE 100

typedef int ElemType;

typedef struct PINode
{
    ElemType data; //结点数据
    int parent; //双亲位置
}PINode;

typedef struct 
{
    PINode nodes[MAX_TREE_SIZE];
    int x;//根位置
    int n;//结点数目
}PTree;

