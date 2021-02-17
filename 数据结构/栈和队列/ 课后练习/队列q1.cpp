/*
1、编写一个链队列，任意输入一串字符，以 # 作为结束的标志，然后将队列中的元素显示到屏幕上
*/

#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
#define MAXSIZE 100

typedef struct QNode{
    ElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
    QueuePtr front,rear;//队头，尾指针
}LinkQueue;

void InitQueue(LinkQueue *q){
    q->front = (QueuePtr)malloc(sizeof(QNode));
    if(!q->front){
        return;
    }
    q->rear=q->front;
    q->front->next = NULL;

}
void insertQueue(LinkQueue *q,ElemType e){
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if(!p){
        return;
    }
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}

void printQueue(LinkQueue *q){
    QueuePtr p;
    p = q->front;
    while (p!=NULL)
    {
        printf("%c ",p->data);
        q->front = p->next;
        free(p);
        p = q->front;
    }
    printf("\n");
}

int main(){
    LinkQueue q;
    InitQueue(&q);
    char cnt;
    scanf("%c",&cnt);
    while (cnt!='#')
    {
        insertQueue(&q,cnt);
        scanf("%c",&cnt);
    }

    printQueue(&q);
    
    return 0;
}