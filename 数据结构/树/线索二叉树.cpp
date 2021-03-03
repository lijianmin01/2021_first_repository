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