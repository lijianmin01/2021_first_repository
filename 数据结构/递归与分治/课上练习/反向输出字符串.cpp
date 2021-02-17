/*
题目要求：
    编写一个递归函数，实现将输入的任意长度的字符串反向输出的功能。
    例如： FishC  -> ChsiF
*/


#include<stdio.h>

void reservePrint(char *strs,int i){
    if(strs[i]!='\0'){
        int j=i+1;
        reservePrint(strs,j);
        printf("%c",strs[i]);
    }
}

int main(){
    char strs[20];
    scanf("%s",strs);
    int i=0;
    reservePrint(strs,i);
    printf("\n");
    return 0;
}