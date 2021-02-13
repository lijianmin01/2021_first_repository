/*
1、实现对逆波兰输入的表达式进行计算
2、支持带小数点的数据
3、正常的表达式  -->  逆波兰表达式
a+b  --->  a b +
a+(b-c)  ---> a b c - +
a+(b-c)*d ---> a b c - d * +

a + ( b - c ) * d # 
1.01 + ( 3.2 - 2) * 1 #
*/

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
#define MAXBUFFER 10


#define OK 1
#define ERROR -1

typedef double ElemType;
typedef int Status;
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stackSize;
}sqStack;

Status InitStack(sqStack *s){
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if(!s->base){
        return ERROR;
    }

    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
    return OK;
}

Status Push(sqStack *s,ElemType e){
    //如果栈满，追加空间
    if(s->top - s->base >= s->stackSize){
        s->base = (ElemType *)realloc(s->base,(s->stackSize+STACKINCREMENT)*sizeof(ElemType));
        if(!s->base){
            return ERROR;
        }
        s->top = s->base+s->stackSize;
        s->stackSize+=STACKINCREMENT;
    }
    *(s->top)=e;
    s->top++;
}

Status Pop(sqStack *s,ElemType *e){
    if(s->top==s->base){
        return ERROR;
    }

    *e=*--(s->top);
}

int StackLen(sqStack * s){
    return (s->top - s->base);
}

int main(){
    sqStack s;
    char c;
    double d,e;
    /*定义缓冲区*/
    char str[MAXBUFFER];
    int i=0;

    InitStack(&s);

    printf("请安逆波兰表达式输入计算数据，数据之间用空格隔开，以#作为结束标志：\n");
    scanf("%c",&c);

    while (c!='#')
    {
        /*用于过滤数据|判断字符是否是数字*/
        while (isdigit(c)|| c=='.')
        {
            str[i++] = c;
            str[i] = '\0';
            if(i>=10){
                printf("出错：输出的数字位数过长！\n");
                return ERROR;
            }
            scanf("%c",&c);

            if(c == ' '){
                /* atof
                功能：把字符串转换成浮点数
                */
                d = atof(str);
                Push(&s,d); 
                i = 0;
                break;
            }
        }
        
        switch (c)
        {
            case '+':
                    Pop(&s,&e);
                    Pop(&s,&d);
                    Push(&s,d+e);
                    break;
            case '-':
                    Pop(&s,&e);
                    Pop(&s,&d);
                    Push(&s,d-e);
                    break;
            case '*':
                    Pop(&s,&e);
                    Pop(&s,&d);
                    Push(&s,d*e);
                    break;
            case '/':
                    Pop(&s,&e);
                    Pop(&s,&d);
                    if(e!=0){
                        Push(&s,d/e);
                    }else{
                        printf("错误：分母不能为0\n");
                        return ERROR;
                    }
                    
                    break;
        default:
            break;
        }
        scanf("%c",&c);
    }

    /*打印最后结果*/
    Pop(&s,&d);
    printf("\n最后结果为：%lf\n",d);
    
    return 0;
}

/*
5 + (6 + 4) * 8 + 9 / 3
5 6 4 + 8 * 9 3 / + +

5 + 10*8 + 3
*/



