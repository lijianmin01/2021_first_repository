#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0


typedef int ElemType;
typedef int Status;

// 单链表的存储结构
typedef struct Node
{
    ElemType data; //数据域
    struct Node* Next; //指针域
}Node;

typedef struct Node* LinkList;

/*
初始条件：顺序线性表L已存在，1<=i<=ListLength(L)
操作结果：用e返回L中第i个数据元素的值
*/
Status GetElem(LinkList L,int i,ElemType *e){
    int j;
    LinkList p;

    p = L->Next;
    j=1;
    while (p && j<i)
    {
        p = p->Next;
        ++j;
    }

    if(!p || j>i){
        return ERROR;
    }

    *e = p->data;

    return OK;
    
}

/*
初始条件：顺序线性表L已存在， 1<= i <=ListLength(L)
操作结果： 在l中第i个位置之前插入新的元素e ，L的长度++
*/
Status ListInsert(LinkList *L,int i,ElemType e){
    int j;
    LinkList p,s;

    p = *L;
    j =1;

    while (p && j<i)
    {
        p = p->Next;
        j++;
    }

    if (!p || j>i){
        return ERROR;
    }

    s = (LinkList)malloc(sizeof(Node));
    s->data = e;

    s->Next = p->Next;
    p->Next = s;

    return OK;
    
}

/*
初始化条件：顺序线性表L已存在，1<= i <=ListLength(L)
操作结果：删除L的第i个数据元素，并用e返回其值，L的长度--
*/
Status ListDelete(LinkList *L,int i,ElemType *e){
    int j;
    LinkList p,q;

    p = *L;
    j = 1;
    while (p->Next && j<i)
    {
        p = p->Next;
        j++;
    }

    if(!(p->Next) || j>i ){
        return ERROR;
    }

    q = p->Next;
    p->Next = q->Next;
    // p->Next = p->Next->Next;
    // return OK;

    *e = q->data;
    free(q);

    return OK;
    
}

/*头插法建立单链表实例*/
void CreateListHead(LinkList *L,int n){
    LinkList p;
    int i;

    srand(time(0));//初始化随机数种子

    *L = (LinkList)malloc(sizeof(Node));
    (*L)->Next = NULL;

    for ( i = 0; i < n; i++)
    {
        // 生成新的结点
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%100+1;
        p->Next = (*L)->Next;
        (*L)->Next = p;
    }
    
}

/*尾插法建立单链表演示*/
void CreateListTail(LinkList *L,int n){
    LinkList p,r;
    int i;

    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    r = *L;

    for ( i = 0; i < n; i++)
    {
        p = (Node *)malloc(sizeof(Node));
        p->data = rand()%100+1;
        r->Next = p;
        r=p;
    }
    r->Next = NULL;
    
}

/* 单链表的整表删除
    - 声明结点p和q
    - 将第一个结点赋值给p 下一个结点赋值给q
    - 循环执行释放p和 将q赋值给p 的操作
*/

Status ClearList(LinkList *L){
    LinkList p,q;

    p = (*L)->Next;

    while (p)
    {
        q = p->Next;
        free(p);
        p=q;
    }
    (*L)->Next=NULL;
}

int main(void){

    return 0;
}