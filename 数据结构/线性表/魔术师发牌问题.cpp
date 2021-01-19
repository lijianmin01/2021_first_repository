#include<stdio.h>
#include<stdlib.h>

#define CardNumber 13

typedef struct node{
    int data;
    struct node * next;
}sqlist,*linklist;

/*创建循环链表*/
linklist CreateLinkList(){
    linklist head=NULL;
    linklist s,r;
    int i;

    r = head;
    for(i = 1;i<=CardNumber;i++){
        s = (linklist)malloc(sizeof(sqlist));
        s->data = 0;
        if(head==NULL){
            head=s;
        }else{
            r->next=s;
        }
        r=s;
    }
    r->next=head;
    return head;
}

/*发牌顺序的计算*/
void Magician(linklist head){
    linklist p;
    int j;
    int Countnumber = 2;

    p = head;
    p->data = 1; // 第一张牌放1

    while (1)
    {
        for(j=0;j<Countnumber;j++){
            p = p->next;
            /*如果该位置有牌了，放在下一位置*/
            if(p->data!=0){
                p= p->next;
                j--;
            }
        }

        if(p->data==0){
            p->data = Countnumber;
            Countnumber++;

            if(Countnumber==14){
                break;
            }
        }
    }
}

/*销毁工作*/
void DestoryList(linklist * list){
    linklist ptr = * list;
    linklist buff[CardNumber];
    int i =0;
    while (i<CardNumber)
    {
        buff[i++]=ptr;
        ptr = ptr->next;
    }

    for(i=0;i<CardNumber;i++){
        free(buff[i]);
    }
    *list = 0;
}


int main(){
    linklist p;
    int i;

    p = CreateLinkList();
    Magician(p);

    printf("按如下顺序排列：\n");
    for (i=0; i < CardNumber; i++)
    {
        printf("黑桃%d ", p->data);
        p = p->next;
    }

    DestoryList(&p);

    return 0;
    return 0;
}