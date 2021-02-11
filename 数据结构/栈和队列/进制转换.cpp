#include<stdio.h>

#define MAXSIZE 100
typedef int ElemType;


typedef struct 
{
	ElemType data[MAXSIZE];
	int top;
	int StackSize;
}sqstack;

void initsq(sqstack *s){
	s->top=0;
	s->StackSize=MAXSIZE;
}
/*进站*/
void Push(sqstack *s,ElemType num){
	if(s->top>=MAXSIZE){
		printf("栈已满\n");
		return;
	}
	s->data[s->top++]=num;
}

/*出栈*/
ElemType Pop(sqstack *s){
	if(s->top==0){
		// printf("栈已空\n");
		return -1;
	}
	return s->data[--s->top];
}

/*进制转换*/
/*n 转换成的进制，num 为十进制的数*/
void func(int n,int num){
	int begin_num = num;
	sqstack s;
	initsq(&s);
	int t;
	while(num!=0){
		t = num%n;
		Push(&s,t);
		num = num/n;
	}
	/*依次取数*/
	printf("十进制%d转换%d进制为：",begin_num,n);
	t = Pop(&s);
	while(t!=-1){
		printf("%d ",t);
		t = Pop(&s);
	}
	printf("\n");
}

/*十进制转换为任意进制*/
void tenTurnAll(){
	int num;
	printf("请输入十进制的数：");
	scanf("%d",&num);
	int n;
	printf("请输入要转成的进制数：");
	scanf("%d",&n);
	func(n,num);
}

/*任意进制转成十进制*/
void AllTurnTen(){
	int n,num;
	printf("请输入数字和该数的进制：");
	scanf("%d %d",&num,&n);
	int begin_num = num;
	sqstack s;
	initsq(&s);
	int t;
	while (num!=0)
	{
		t = num % 10;
		Push(&s,t);
		num = num/10;
	}
	t = Pop(&s);
	int result=0;
	while (t!=-1)
	{
		result = result*n+t;
		t = Pop(&s);
	}
	printf("%d进制的数%d转成十进制为：%d\n",n,begin_num,result);
}

/*任意进制的数转成十进制*/
ElemType allTurnTen(int n,int num){
	sqstack s;
	initsq(&s);
	int t;
	while(num!=0){
		t = num%10;
		Push(&s,t);
		num = num/10;
	}
	/*依次取数*/
	int result=0;
	t = Pop(&s);
	while(t!=-1){
		result = result*n+t;
		t = Pop(&s);
	}
	return result;
}

/*十进制转成任意进制*/
ElemType tenTurnAll(int num,int n){
	int result=0;
	int t;
	sqstack s;
	initsq(&s);
	while (num)
	{
		t = num%n;
		Push(&s,t);
		num = num/n;
	}

	t = Pop(&s);
	while (t!=-1)
	{
		result = result*10+t;
		t = Pop(&s);
	}
	return result;
}

/*任意进制之间的转换*/
void AllTurnAll(){
	int num,begin_num,b_n,g_n;
	printf("请输入一个数，数的进制，要转成的进制为：");
	scanf("%d %d %d",&num,&b_n,&g_n);
	begin_num = num;
	int ten_num = allTurnTen(b_n,num);
	int result = tenTurnAll(ten_num,g_n);
	printf("%d进制的%d 转换成%d数为:%d\n",b_n,begin_num,g_n,result);
}

int main(){
	AllTurnAll();
	return 0;
}


