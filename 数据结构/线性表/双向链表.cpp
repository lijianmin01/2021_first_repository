#include<stdio.h>
#include<stdlib.h>

#define ElemType int

/*双向链表的结构*/
typedef struct DualNode{
    ElemType data;
    struct DualNode *prior;
    struct DualNode *next;
}DualNode,*DuLinkList;