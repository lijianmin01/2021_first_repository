#include<stdio.h>
#include<string.h>

/*
 * 首先将定义一个数组跟所需字符串的长度一样
 * 为了后面方便变编程  首元素定义为-1
 * 字符串  T
 * i =0 为了便利字符串
 * j = -1 next 的首元素
 * 开始便利字符串
 *      j == -1 的时候 或者  T[i] == T[j]时候
 *          i和j ++
 *      如果 T[i] ！= T[j]
 *          则 j = next[j]
 * */
void get_next(char *T, int next[]) {
    int strs_len = strlen(T);
    int i = 0, j = -1;
    next[0]=-1;
    while (i < strs_len) {
        if (j == -1 || T[i] == T[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j=next[j];
        }
    }
}

int kmp(char *str_main,char * str_branch){
    int next[100];
    int str_main_len = strlen(str_main);
    int str_branch_len = strlen(str_branch);
    int i,j;
    get_next(str_branch,next);
    i=0;
    j=0;
    /*kmp 核心
        当主串i和子串j相等的时候，i++,j++;
        反之 j = next[j];
        当 j==-1 的时候，i++,j++
    */
    while ( i < str_main_len && j < str_branch_len )
    {
        if(str_main[i]==str_branch[j]){
            i++;
            j++;
        }else{
            j = next[j];
            if(j==-1){
                j++;
                i++;
            }
        }
    }
    if(j>=str_branch_len){
        /*此时说明在主串中找到了子串*/
        return i-str_branch_len;
    }else{
        return -1;
    }

}

int main() {
    printf("KMP算法的实现\n");
    char str_main[100];
    char str_branch[100];
    printf("请输入主串：\n");
    scanf("%s",str_main);
    printf("请输入所查找的子串：\n");
    scanf("%s",str_branch);

    printf("子串在主串中开头位置为：%d\n",kmp(str_main,str_branch));

    return 0;
}

