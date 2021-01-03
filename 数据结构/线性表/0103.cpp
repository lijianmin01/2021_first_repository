#include<stdio.h>

// 线性表顺序存储的结构代码
#define MAXSIZE 20
typedef int ElemType;
typedef struct 
{
    ElemType data[MAXSIZE];
    int length;//线性表的长度
}SqList;

typedef int Status;
#define ERROR 0;
#define OK 1;

/*
Status 是函数的类型，其值是函数结果状态代码，如OK等
初始条件：顺序线性表L已存在，1<=i<=ListLength(L)
操作结果：用e返回L中第i个数据元素
*/


// 从线性表L中查找第i个元素
Status GetElem(SqList L,int i){
    if (L.length==0||i<1||i>L.length){
        return ERROR;
    }
    ElemType e = L.data[i-1];
    return e;
}


/*
初始条件：顺序线性表中L已存在，1<= i <=ListLength(L).
操作结果：在L中第i个位置之前插入新的数据元素e ,长度L ++
*/
Status ListInsert(SqList *L,int i,ElemType e){
    int k;
    // 线性表已经满了
    if(L->length == MAXSIZE){
        return ERROR;
    }
    // i 不在范围内，插入位置有误
    if (i<1 || i>L->length){
        return ERROR;
    }

    // 如插入位置不在表尾
    if(i<=L->length){
        /*将要插入位置后的元素向后移动一位*/
        for(k=L->length;k>=i-1;k--){
            L->data[k+1]=L->data[k];
        }
    }
    // 将新元素插入
    L->data[i-1]=e;
    L->length++;
    return OK;
}

void printSqlist(SqList L){
    int i;
    for(i=0;i<L.length;i++){
        printf("%d ",L.data[i]);
    }
    printf("\n");
}

// 删除操作
//操作结果：在L中删除第i个位置的数据元素e 
Status MyListDelete(SqList *L,int i){
    int k;
    // 线性表已经空了
    if(L->length == 0){
        return ERROR;
    }
    // i 不在范围内，插入位置有误
    if (i<1 || i>L->length){
        return ERROR;
    }

    // 如删除位置不在表尾
    if(i<=L->length){
        /*将要删除位置后的元素向前移动一位*/
        // for(k=L->length;k>=i-1;k--){
        //     L->data[k-1]=L->data[k];
        // }
        for (k=i-1;k<L->length-1;k++)
        {
            L->data[k]=L->data[k+1];
        }    
    }
    L->length--;
    return OK;
}

/*
初始条件： 顺序线性表L已存在，1<= i <=L->length
操作结果：删除L的第i个数据元素，并用e返回其值，L的长度为--
*/
Status ListDelete(SqList *L,int i,ElemType *e){
    int k;
    if(L->length==0){
        return ERROR;
    }
    if (i<1 || i>L->length){
        return ERROR;
    }

    *e = L->length;

    if(i<L->length){
        for(k=i;k<L->length;k++){
            L->data[k-1]=L->data[k];
        }
    }

    L->length--;
    return OK;
}


int main(){
    SqList L=SqList();
    int i;
    for ( i = 0; i < MAXSIZE-7; i++)
    {
        L.data[i]=i;
        L.length++;
    }
    printSqlist(L);
    ListInsert(&L,0,20);
    ListInsert(&L,1,20);
    ListInsert(&L,2,200);
    ListInsert(&L,3,20);
    ListInsert(&L,4,200);
    ListInsert(&L,5,20);
    ListInsert(&L,6,200);
    printSqlist(L);
    // 删除第2个位置元素
    MyListDelete(&L,2);
    printSqlist(L);
    printf("len is %d\n",L.length);
    //删除尾元素
    MyListDelete(&L,18);
    printSqlist(L);
    return 0;
}

