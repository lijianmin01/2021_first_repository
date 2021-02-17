/*打印前40位斐波那契数列*/
#include<stdio.h>
#include<stdlib.h>

int nums[40];
int flag=0;

int func(int n){
    if(n==0){
        return 1;
    }else if(n==1){
        return 1;
    }else if(nums[n]!=0){
        return nums[n];
    }else{
        return func(n-1)+func(n-2);

    }
}


int main(){
    for (int i = 0; i < 40; i++)
    {
        nums[i]=0;
    }

    for (int i = 0; i < 40; i++)
    {
        nums[i]=func(i);

        printf("%d ",nums[i]);
    }

    printf("\n");
    
    return 0;
}