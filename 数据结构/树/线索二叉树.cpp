#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;

// 线索存储标示位
// Link 0 ，表示纸箱左右孩子的指针
// Thread 1 ,表示指向前驱后继的线索
typedef enum{Link,Thread} PointerTag;

typedef struct BinaryThreadNode{
    char data;
    struct BinaryThreadNode *lchild,*rchild;
    PointerTag ltag,rtag;
}BinThrNode,*BinThrTree;

// 全局变量，始终指向刚刚访问过的结点
BinThrTree pre;

//前驱遍历的方式创建二叉树
void CreateBinThrTree(BinThrTree *T){
    char c;

    scanf("%c",&c);
    if(' '==c){
        *T = NULL;
    }else{
        *T = (BinThrTree)malloc(sizeof(BinThrNode));
        (*T)->data = c;
        (*T)->ltag = Link;
        (*T)->rtag = Link;

        //递归创建左右结点
        CreateBinThrTree(&((*T)->lchild));
        CreateBinThrTree(&((*T)->rchild));
    }
    
}

/*中序遍历线索华*/
void Inthreading(BinThrTree T){
    if(T){
        //递归左孩子线索华
        Inthreading(T->lchild);
        // 左孩子为空
        // 左孩子指向前驱
        if(!T->lchild){
            T->ltag = Thread;
            T->lchild = pre;
        }
        // 右孩子为空
        if(!T->rchild){
            T->rtag = Thread;
            T->rchild = T;
        }
        pre = T;

        //递归右孩子线索华
        Inthreading(T->rchild);
    }

}

void InorderThreading(BinThrTree *p,BinThrTree T){
    *p = (BinThrTree)malloc(sizeof(BinThrNode));
    (*p)->ltag = Link;
    (*p)->rtag = Link;
    
    if(!T){
        (*p)->lchild = *p;
    }else{
        (*p)->lchild = T;
        pre = *p;

        Inthreading(T);
        pre->rchild = *p;
        pre->rtag = Thread;
        (*p)->rchild = pre;
    }
}

void visit(char c){
    printf("%c",c);
}

// 中序遍历二叉树，非递归
void InOrderTraverse(BinThrTree T){
    BinThrTree p;
    p = T->lchild;
    while (p!=T)
    {
        // 当存在左子树的时候
        while (p->ltag == Link)
        {
            p = p->lchild;
        }
        visit(p->data);
        while (p->rtag == Thread && p->rchild !=T)
        {
            p=p->rchild;
            visit(p->data);
        }
        p = p->rchild; 
    }
    
}

int main(){
    BinThrTree T=NULL;
    BinThrTree p=NULL;
    CreateBinThrTree(&T);
    InorderThreading(&p,T);

    printf("中序遍历输出结果为：");
    InOrderTraverse(p);
    return 0;

}













