/*
问题一圆盘的移动步骤为：
    - 先将前62个盘子移动到Z上，确保大盘在小盘下
    - 在将最底下的第63个盘子移动到Y上
    - 最后将Z上的62歌盘子移动到Y上
问题二圆盘的移动步骤为：
    - 先将前62个盘子移动到X上，确保大盘在小盘下
    - 在将最低下的63个盘子移动到Z上
    - 最后将X上的62个盘子移动到Y上

*/

#include<stdio.h>

// 将n个盘子从x借助y移动到z上
void move(int n,char x,char y,char z){
    if(n==1){
        printf("%c --> %c\n",x,z);
    }else{
        // 将n-1个盘子从x借助z移动到y上
        move(n-1,x,z,y);
        // 将n个盘子从x移动到z上
        printf("%c --> %c\n",x,z);
        // 将n-1个盘子从y借助x移动到z上
        move(n-1,y,x,z);
    }
}

int main(){

    int n;

    printf("请输入汉诺塔的层数：");
    scanf("%d",&n);
    printf("汉诺塔的步骤如下：\n");
    move(n,'x','y','z');
}