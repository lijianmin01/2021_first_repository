#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct{
    ElemType *base; 
    // 用于存放内存分配地址
    // 这里可以用数组存放
    int front;
    int rear;
}cycleQueue;

/*初始化循环队列*/
void initQueue(cycleQueue *q){
    q->base = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
    if(!q->base){
        return;
    }
    q->front = 0;
    q->rear = 0;
}

/*如队列操作*/
void InsertQueue(cycleQueue *q,ElemType e){
    if((q->rear+1)%MAXSIZE == q->front){
        // 队列已满
        return;
    }
    q->base[q->rear] = e;
    q->rear = (q->rear+1)%MAXSIZE;
}


int main(){

    return 0;
}

