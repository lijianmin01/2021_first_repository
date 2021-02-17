#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
#define MAXSIZE 100

typedef struct QNode{
    ElemType data;
    struct QNode *next;
}QNode,*QueuePrt;

typedef struct{
    QueuePrt front,rear;//队头，尾指针
}LinkQueue;

/*初始化队列*/
void initQueue(LinkQueue *q){
    q->rear = (QueuePrt)malloc(sizeof(QNode));
    q->front = q->rear;
    if(!q->front){
        return;
    }
    q->front->next=NULL;
}

/*入队操作*/
void InsertQueue(LinkQueue *q,ElemType e){
    QueuePrt p;
    p = (QueuePrt)malloc(sizeof(QNode));
    if(p==NULL){
        return;
    }
    p->data = e;
    p->next = NULL;
    q->rear->next=p;
    q->rear = p;
}

/*出队操作*/
void DeleteQueue_me(LinkQueue *q,ElemType *e){
    if (q->front == q->rear){
        return;
    }
    *e = q->front->data;

    q->front = q->front->next;
}

void DeleteQueue(LinkQueue *q,ElemType *e){
    QueuePrt p;
    if (q->front == q->rear){
        return;
    }

    p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    if(q->rear == p){
        q->rear = q->front;
    }
    free(p);
}
/*
感觉这种有点啰嗦，一开始带有头结点，后面再删除头结点，有点多此一举的“嫌疑”。
*/

/*销毁一个队列*/
void DestroyQueue(LinkQueue *q){
    while(q->front){
        q->rear = q->front->next;
        free(q->front);
        q->front = q->rear;
    }
}
