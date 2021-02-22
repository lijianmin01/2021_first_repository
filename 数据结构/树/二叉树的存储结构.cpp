/*
## 二叉树的顺序存储
* 用一组连续的存储单元依次自上而下，自左至右存储完全二叉树上的结点元素


*/

#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;

typedef struct BitNode
{
    ElemType data;
    struct BitNode *lchild,*rchild;
}BitNode,*BiTree;

// 创建一棵二叉树
// 约定用户遵照前序遍历的方式输入数据
void CreateBiTree(BiTree *T){
    ElemType c;

    scanf("%c",&c);
    if (' '==c){
        *T = NULL;
    }else{
        *T = (BitNode *)malloc(sizeof(BitNode));
        (*T)->data = c;
        CreateBiTree(&((*T)->lchild));
        CreateBiTree(&((*T)->rchild));
    }
}


// 访问二叉树结点的具体操作
void visit(BiTree T,int level){
    printf("%c 位于%d层\n",T->data,level);
}

// 前序遍历二叉树
// level 深度
void PreOrderTraverse(BiTree T,int level){
    if(T){
        visit(T,level);
        PreOrderTraverse(T->lchild,level+1);
        PreOrderTraverse(T->rchild,level+1);
    }
}

int main(){
    int level = 1;
    BiTree T = NULL;

    CreateBiTree(&T);
    PreOrderTraverse(T,level);
    return 0;
}
