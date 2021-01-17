#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int id;
    int is_save;
    struct node * next;
}node;

// 初始含有化num个结点的循环链表
void ds_init(node **pNode,int nums){
    int index=1;
    (*pNode) = (node *)malloc(sizeof(node));
    node* p;
    p = *pNode;
    p->id=index++;
    p->is_save=1;
    p->next=NULL;
    for(index;index<=nums;index++){
        node* temp=(node *)malloc(sizeof(node));
        temp->id=index;
        temp->is_save=1;
        p->next=temp;
        p = temp;
    }
    p->next=(*pNode);
}

// 模拟自杀流程
void ds_process(node *pNode,int sumPeopleNum,int savePeopleNum){
    int temp=0;
    node * p = pNode;
    while(sumPeopleNum!=savePeopleNum){
        if(p->is_save==1){
            temp++;
        }
        if(temp==3){
            temp==0;
            p->is_save=0;
            sumPeopleNum--;
        }
        p=p->next;
    }
    printf("最后幸存%d人，所处的位置有：",savePeopleNum);
    for(p=pNode;p->next!=pNode;p=p->next){
        if(p->is_save==1){
            printf("%d  ",p->id);
        }
    }
    printf("\n");
}

int main(void){
    node * pNode;
    ds_init(&pNode,41);
    ds_process(pNode,41,2);
    return 0;
}