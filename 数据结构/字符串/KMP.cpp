#include<stdio.h>

typedef struct{

}String;

/*KMP算法之next数组代码原理分析
(字符第一位记录字符串的长度)

T       5  a b a b a a a b a
index   0  1 2 3 4 5 6 7 8 9
next       0

i(后缀)=
j(前缀)=

*/


void get_next(String T,int *next){
    int i,j;
    j = 0;
    i = 1;
    next[1] = 0;
    while (i < T[0])
    {
        if(j==0 || T[i]==T[j]){
            i++;
            j++;
            next[i]=j;
        }else{
            j = next[j];
        }
    }
    
}