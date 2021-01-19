#include<stdio.h>
#include<stdlib.h>

#define ElemType char 

/*双向链表的结构*/
typedef struct DualNode{
    ElemType data;
    struct DualNode *prior;
    struct DualNode *next;
}DualNode,*DuLinkList;


DuLinkList initList(){
    DualNode* l;
    char A = 'A';
    DuLinkList s,t,t1,t2;
    t = (DuLinkList)malloc(sizeof(DualNode));
    t->data = A;
    l = t;
    s = l;
    int i,j;
    for(i=1;i<26;i++){
        t = (DuLinkList)malloc(sizeof(DualNode));
        t->data = A+i;
        t->prior= s;

        s->next = t;
        s = t;
    }
    s->next = l;
    l->prior = s;
    
    return l;
}

void func(DuLinkList* l,int num){
    int i;
    DuLinkList s = (*l);
    for(i=0;i<num;i++){
        s=s->next;
    }
    (*l)=s;

}

void myPrint(DuLinkList l){
	DuLinkList t = l;
    int i;
    for ( i = 0; i < 26; i++)
    {
        printf("%c ",t->data);
        t = t->next;
    }
    printf("\n");
}

int main(){
    DuLinkList l = initList();
    printf("之前：");
    myPrint(l);
    func(&l,3);
    printf("之后：");
    myPrint(l);
    return 0;
}


/*
之前：A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
之后：D E F G H I J K L M N O P Q R S T U V W X Y Z A B C
*/