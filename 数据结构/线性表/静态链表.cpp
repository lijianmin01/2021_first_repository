#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAXSIZE 1000
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct 
{
    ElemType data;//数据
    int cur; // 游标（Cursor）
}Component,StaticLinkList[MAXSIZE];

// 静态链表的初始化
Status InitList(StaticLinkList space){
    int i;
    for (i=0;i<MAXSIZE-1;i++)
    {
        space[i].cur=i+1;
    }
    return OK;
    
}

// 静态链表的插入操作
// 首先是获得空闲分量的下标
int Malloc_SLL(StaticLinkList space){
    int i = space[0].cur;
    if(space[0].cur){
        // 把它下一个分量用来作为备用 赋值给下一个空间区间
        space[0].cur = space[i].cur;
    }
    return i;
}

/*在静态链表L中第i个元素之前插入新的元素*/
Status ListInsert(StaticLinkList L,int i,ElemType e){
    int j,k,l;

    // 最后一个元素
    k = MAXSIZE - 1;
    if(i<1 || i>ListLength(L)+1){
        return ERROR;
    }

    j = Malloc_SLL(L);
    if(j){
        L[j].data = e;
        for(l=1;l<=i-1;l++){
            k = L[k].cur;
        }
        L[j].cur = L[k].cur;
        L[k].cur = j;

        return OK;
    }
    return ERROR;
}


/*
id          号码正确数量    位置正确数据量
1   6 8 2           1           1
2   6 1 4           1           0
3   2 0 6           2           0
4   7 3 8           0           0
5   8 7 0           1           0

有1、2 可得 6 肯定不为正确答案   候选数字为 8 2 1 4
结合3可得   2 0 为所求，从而 在结合1 来看  8 不为正确答案 
结合位置来看,数字形式为：
    0 * 2
下面，来看4  暂时没什么用
跟5结合来看   只得出正确数字有0 且位置不为最后一位
(4、5) 没什么作用

所以推测为：
0 1 2
0 4 2

*/

/*删除在L中的第i个数据元素*/
Status ListDelete(StaticLinkList L,int i){
    int j,k;
    if(i<1 || i>ListLength(L)){
        return ERROR;
    }

    k = MAXSIZE - 1;
    for(j=1;j<=i-1;j++){
        k = L[k].cur;
    }

    j = L[k].cur;
    L[k].cur = L[j].cur;
    Free_SLL(L,j);

    return OK;
}

/*将下标为k的空闲结点回收到备用链表*/
void Free_SLL(StaticLinkList space,int k){
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

/*返回L中数据元素的个数*/
int ListLength(StaticLinkList L){
    int j=0;
    int i = L[MAXSIZE-1].cur;

    while(i){
        i = L[i].cur;
        j++;
    }
    return j;
}



