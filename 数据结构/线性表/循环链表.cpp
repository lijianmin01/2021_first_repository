#include<stdio.h>
#include<stdlib.h>

typedef struct CLinkList
{
    int data;
    struct CLinkList* next;
    
}node,LinkList[20];


/*初始化循环链表*/
void ds_init(node **pNode){
    int item;
    node *temp;
    node *target;

    printf("输入结点值，输入0完成初始化\n");

    while(1){
        scanf("%d",&item);
        fflush(stdin);
        /*
        fflush(stdin)是一个计算机专业术语，功能是清空输入缓冲区，
        通常是为了确保不影响后面的数据读取
        （例如在读完一个字符串后紧接着又要读取一个字符，此时应该先执行fflush(stdin);。
        */

        if(item==0){
            return;
        }

        if((*pNode)==NULL){
            /*玄幻链表中只有一个结点*/
            *pNode = (node *)malloc(sizeof(struct CLinkList));
            if(!(*pNode)){
                exit(0);
            }
            (*pNode)->data = item;
            (*pNode)->next = *pNode;
        }else{
            /*找到next 指向第一个结点的结点*/
            for(target=(*pNode);target->next !=(*pNode);target=target=target->next);
            /*生成一个新的结点*/
            temp = (node *)malloc(sizeof(struct CLinkList));

            if(!temp){
                exit(0);
            }
            temp->data = item;
            temp->next = target->next;
            target->next = temp;
        }
    }
}

/*插入结点*/
/*参数：链表的第一个结点，插入位置*/
void ds_insert(node **pNode,int i){
    node *temp;
    node *target;
    node *p;
    int item;
    int j=1;
    printf("输入要插入结点的值：");
    scanf("%d",item);

    if(i==1){
        /*新插入的结点座位第一个个结点*/
        temp = (node *)malloc(sizeof(struct CLinkList));

        if(!temp){
            exit(0);
        }

        temp->data = item;
        /*寻找最后一个结点*/
        for(target=(*pNode);target->next!=(*pNode);target=target->next);

        temp->next = target->next;
        target->next = temp;
        *pNode = temp;
    }else{
        /*新建一个结点*/
        temp = (node *)malloc(sizeof(struct CLinkList));

        if(!temp){
            exit(0);
        }

        temp->data = item;

        /*寻找第i-1个结点*/
        for(target=(*pNode);j<i-1;target=target->next){
            j++;
        }
        temp->next = target->next;
        target->next = temp;
    }
}

/*删除结点*/
void ds_delete(node **pNode,int i){
    node *target,*temp;
    int j=1;

    if(i==1){
        /*删除的是第一个结点*/
        /*找到最后一个结点*/
        for(target=*pNode;target->next!=*pNode;target=target->next);

        temp = *pNode;
        target->next=temp->next;
        *pNode = (*pNode)->next;
        free(temp);
    }else{
        /*找到第i-1位置的结点*/
        for(target=*pNode;j<i-1;target=target->next){
            j++;
        }

        /*
            target = *pNode;
            for(;j<i-1;++j){
                target=target->next;
            }       
        */
        temp = target->next;
        target->next = temp->next;
        free(temp);
    }
}

/*查找结点所在链表中的位置*/
int ds_search(node *pNode,int elem){
    node *target;
    int i=1;
    for(target=pNode;target->data!=elem&&target->next!=pNode;i++){
        target=target->next;
    }
    if(target->next==pNode){
        /*链表中不存在elem元素*/
        return 0;
    }else{
        return i;
    }
}

/*用快慢指针的方式判断链表是否有环*/
int HasLoop2(LinkList L){
    int step1 = 1;
    int step2 = 2;
    LinkList p = L;
    LinkList q = L; 
    while(p!=NULL && q!=NULL && q->next!=NULL){
        p = p->next;
        if(q->next!=NULL){
            q = q->next->next;
        }
        printf("p:%d q:%d\n",p->data,q->data);

        if(p==q){
            return 1;
        }
    }
    return 0;
}