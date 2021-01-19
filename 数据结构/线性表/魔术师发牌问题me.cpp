#include<stdio.h>
#include<stdlib.h>

#define cardNumber 13

typedef struct node{
    int data;
    struct node * next;
}node,*linklist;

void func(linklist* l){
    int cardCount = 0;
    /*初始化循环链表*/
    int i,j;
    linklist s,t;
    // 第一张牌
    t = (linklist)malloc(sizeof(node));
    t->data = 0;
    t->next = NULL;
    (*l) = t;
    s = t;
    for(i=1;i<cardNumber;i++){
        t = (linklist)malloc(sizeof(node));
        t->data = 0;
        s->next = t;
        s = t;
    }
    // 核心
    s->next = (*l);

    s = (*l);
    for(i=1;i<=cardNumber;i++){
        j=1;
        while(j<i){
            if(s->data==0){
                j++;
            }
            s = s->next;
        }
        s->data = i;
    }
    // 展示
    printf("发牌顺序为：");
    s = (*l);
    for(i=1;i<=cardNumber;i++){
        printf("%d  ",s->data);
    }
    printf("\n");
}


int main(){
    linklist l;
    func(&l);

    return 0;
}