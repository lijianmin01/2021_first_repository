// 参考：https://www.jianshu.com/p/deb1d2f2549a
#include<stdio.h>
#include<stdlib.h>

// 函数状态结果码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef char Elemtype;

// 线索二叉树的左右孩子的标示 0正常  1前去后续结点

typedef enum{Link,Thread} PointerTag;

typedef struct BinThrNode{
    Elemtype data;
    struct BinThrNode *lchild,*rchild;
    PointerTag LTag,RTag; 
}BinThrNode,*BinThrTree; 

// 线索二叉树初始化
// 前序遍历的方式构建二叉树
void CreateBinThrNode(BinThrTree *T){
    char c;
    scanf("%c",&c);
    // #代表空格
    if(c=='#'){
        *T = NULL;
    }else{
        (*T)=(BinThrTree)malloc(sizeof(BinThrNode));
        if(!T){
            exit(OVERFLOW);
        }
        (*T)->LTag = Link;
        (*T)->RTag = Link;
        CreateBinThrNode(&(*T)->lchild);
        CreateBinThrNode(&(*T)->rchild);
    }
}

//线索二叉树线索化
/*T 二叉树的头结点  pre 访问二叉树的时候，当前的结点*/
void InThreading(BinThrTree T,BinThrTree *pre){
    // 如果当前T为空，即二叉树为空
    if(!T){
        return;
    }

    InThreading(T->lchild,pre);

    if(!T->lchild){
        T->LTag = Thread;
        T->lchild =*pre;
    }

    if(!(*pre)->rchild){
        (*pre)->RTag = Thread;
        (*pre)->rchild = T;
    }

    *pre = T;
    InThreading(T->rchild,pre);
}

//为线索二叉树添加头结点，使之可以双向操作
void InOrderThreading(BinThrTree *Thrt,BinThrTree T){
    if(!(*Thrt = (BinThrTree)malloc(sizeof(BinThrNode)))) exit(OVERFLOW);
    
    (*Thrt)->LTag = Link;
    (*Thrt)->RTag = Thread;
    (*Thrt)->rchild = (*Thrt);
    if(!T) {
        (*Thrt)->lchild = (*Thrt);
        return;       //若根结点不存在,则该二叉树为空,让该头结点指向自身.
    }

    BinThrTree pre;
    //令头结点的左指针指向根结点
    pre = (*Thrt);
    (*Thrt)->lchild = T;
    //开始递归输入线索化
    InThreading(T,&pre);
    //此时结束了最后一个结点的线索化了,下面的代码把头结点的后继指向了最后一个结点.
    //并把最后一个结点的后继也指向头结点,此时树成为了一个类似双向链表的循环.
    pre->rchild = *Thrt;
    pre->RTag = Thread;
    (*Thrt)->rchild = pre;
}

//非递中序归遍历线索二叉树
void InOrderTraverse(BinThrTree T){
    BinThrTree p = T->rchild;
    while (p!=T)
    {
        // 走到左子树的尽头
        while(p->LTag!=Thread){
            p=p->lchild;
        }
        printf("%c",p->data);
        // 访问该节点的后续结点
        while (p->RTag==Thread && p->rchild!=T)
        {
            p=p->rchild;
            printf("%c",p->data);
        }
        p=p->rchild; 
    }
    
}

int main() {
  BinThrTree B,T;
  CreateBinThrNode(&B);
  InOrderThreading(&T,B);
  printf("中序遍历二叉树的结果为：");
  InOrderTraverse(T);
  printf("\n");
}
















