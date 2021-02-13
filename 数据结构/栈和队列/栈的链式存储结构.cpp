/*栈的链式存储结构*/
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
#define MAXSIZE 100
typedef int Status;
#define OK 1
#define ERROR -1

typedef struct StackNode
{
    ElemType data;//存放栈的数据
    struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack{
    LinkStackPtr top;//top 指针 
    int count; //栈的元素计数器
}LinkStack;

/*进栈操作*/
Status Push(LinkStack *s,ElemType e){
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    if(!p){
        return ERROR;
    }
    p->data = e;
    p->next = s->top;
    s->top = p;
    s->count++;
    return OK;
}

/*出栈操作*/
Status Pop(LinkStack *s,ElemType *e){
    LinkStackPtr p;
    /*判断是否为空栈*/
    if(s->count==0){
        return ERROR;
    }
    *e = s->top->data;
    p = s->top;
    s->top = s->top->next;
    free(p);
    s->count--;
    return OK;
}

int main(){

    return 0;
}