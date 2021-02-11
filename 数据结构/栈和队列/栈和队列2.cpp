#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
#define MAXSIZE 100

/*指针创造栈*/
typedef struct 
{
	ElemType *base;
	ElemType *top;
	int stackSize;
}sqStack;

/*初始化栈*/
void initStack(sqStack *s){
	s->base = (ElemType *)malloc(MAXSIZE*sizeof(ElemType));
	if(!s->base){
		return;
	}
	s->top = s->base; // 最开始栈顶就是栈低
	s->stackSize = MAXSIZE;
}
/*入栈操作*/
void Push(sqStack *s,ElemType e){
	/*如果栈满则追加空间*/
	if(s->top - s->base >= s->stackSize){
		s->base = (ElemType *)realloc(s->base,(s->stackSize + MAXSIZE)*sizeof(ElemType));
		if(!s->base){
			exit(0);
		}
		s->top = s->base + s->stackSize;
		s->stackSize = s->stackSize+MAXSIZE;
	}
	*(s->top)=e;
	s->top++;
}

/*出栈操作*/
void Pop(sqStack *s,ElemType *e){
	if(s->top == s->base){
		/*栈已经空了*/
		return;
	}
	*e = *--(s->top);
}

typedef struct 
{
	ElemType data[MAXSIZE];
	int top; // 用于标注栈顶的位置
	int stackSize; // 容量
};

/*销毁一个栈*/
void DestroyStack(sqStack *s){
	int i,len;
	len = s->stackSize;
	for(i=0;i<len;i++){
		free(s->base);
		s->base++;
	}
	s->base = NULL;
	s->top =NULL;
	s->stackSize=0;
}

/*获取栈的元素数目*/
int StackLen(sqStack * s){
	return (s->top-s->base);//中间隔了一个元素
}
int main(){

	return 0;
}