/*
如何将 “（1-2）*（4+5）”转换为“1 2 - 4 5 + *”呢？

规则：中缀表达式a + b*c + (d * e + f) * g，其转换成后缀表达式则为a b c * + d e * f  + g * +。

*/

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
#define MAXBUFFER 10


#define OK 1
#define ERROR -1

typedef char ElemType;
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
        *e = ' ';
        return ERROR;
    }

    *e=*--(s->top);
}

int StackLen(sqStack * s){
    return (s->top - s->base);
}

Status find_top_char(sqStack *s,char * e){
    if(s->top == s->base){
        *e=' ';
        return OK;
    }
    *e = *(s->top-1);
    return OK;
}

int main(){
    sqStack s,s1;
    char c;
    double d,e;
    /*定义缓冲区*/
    char str[MAXBUFFER];
    int i=0;
    char str_top;

    InitStack(&s);

    printf("请安逆波兰表达式输入计算数据，数据之间用空格隔开，以#作为结束标志：\n");
    scanf("%c",&c);

    while (c != '#')
    {
        /* 表达式也满足  a + b 这种*/
        if(('a'<=c&& c<='z') || ('A'<=c&&c<='Z')){
            printf("%c",c);
            scanf("%c",&c);
            continue;
        }
        /*用于过滤数据|判断字符是否是数字,如果是数字直接输出*/
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
                i = 0;
                /*判断d是否为整数*/
                if(floor(d+0.5)==d){
                    printf("%d     ",int(d));
                }else{
                    printf("%.2lf   ",d);
                }
                break;
            }
        }
        /*数字、字母 直接输出 优先级小的换大的，） 栈清空到(*/
        find_top_char(&s,&str_top);
        if (c==' '){
            scanf("%c",&c);
            continue;
        }else if(c=='('){
//            Pop(&s,&str_top);
//            if(str_top==' '){
//
//            }else{
//                printf("%c ",str_top);
//            }
            Push(&s,c);
        }else if(c==')'){
            /*清空栈到 ( */
            Pop(&s,&str_top);
            while (str_top!='(')
            {
                printf("%c ",str_top);
                Pop(&s,&str_top);
            }

        }else{
            if (str_top == '*' || str_top == '/'){
                if(c=='+'||c=='-'){
                    Pop(&s,&str_top);
                    printf("%c  ",str_top);
                    Push(&s,c);
                }else{
                    Push(&s,c);
                }

            }else if(str_top == '+' || str_top == '-'){
                Push(&s,c);
            }else if(str_top==' '){
                Push(&s,c);
            }else if(str_top == '('){
                Push(&s,c);
            }
        }
        scanf("%c",&c);
    }
    Pop(&s,&str_top);
    while (str_top!=' '){
        if(str_top!='('){
            printf("%c  ",str_top);
        }
        Pop(&s,&str_top);
    }



    return 0;
}


/*
1 + 2 * 3 - 1 + 2

规则：中缀表达式a + b * c + ( d * e + f ) * g，其转换成后缀表达式则为a b c * + d e * f  + g * +。

+       *     (
+ *
a b c * + d e * f + g * +

优先级小的换大的，） 栈清空到(

a + b - c

+ -
a b c - +
*/


/*

 1 * 2 + 3 #
 +
 1 2 * 3 +
 * */
