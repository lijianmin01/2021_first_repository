// /*
// 八皇后问题，一个古老而著名的问题，是回溯算法的经典例题
//     - 在 8 * 8 格的国际象棋上摆放八个皇后，使其不能互相攻击，
//     即任意两个皇后不能处于同一行、同一列或同一斜线上，
//     问有多少种摆法。

//     MDimgs/2021-02-17-15-24-24.png
// */

// #include<stdio.h>

// // 总方案数
// int count=0;

// void print_chess(int (*chess)[8]){
//     int i,j;
//     for ( i = 0; i < 8; i++)
//     {
//         for ( j = 0; j < 8; j++)
//         {
//             printf("%d ",chess[i][j]);
//         }
//         printf("\n");
//     }
//     printf("\n");
// }

// // 判读是否危险
// int notDanger(int row,int j,int (*chess)[8]){
//     int i;
//     int flag1 = 0;
//     // 判断之前的皇后是否在斜线上 左右
//     int flagL=0,flagR=0;
//     for ( i = 0; i < 8; i++)
//     {
//         if(chess[row][i]==1){
//             flag1 = -1;
//             break;
//         }
//         if(chess[i][j]==1){
//             flag1 = -1;
//             break;
//         }
//         if(chess[i][i]==1){
//             flagL = 1;
//         }
//         if(chess[i][7-i]==1 || chess[7-i][i]==1){
//             flagR = 1;
//         }
//     }

//     if(flag1==-1){
//         // return -1;
//     }else{
//         if(flagL==1){
//             if(row==j){
//                 flag1=-1;
//             }
//         }
//         if(flagR==1){
//             if(row+j == 7){
//                 flag1=-1;
//             }
//         }
//     }
//     return flag1;
// }

// // row:起始行  n:总列数  (*chess)[8]:棋盘每一行的头指针
// void EIghtQueen(int row,int n,int (*chess)[8]){
//     // 临时的棋盘
//     int chess2[8][8];
//     int i,j;
//     for ( i = 0; i < 8; i++)
//     {
//         for ( j = 0; j < 8; j++)
//         {
//             chess[i][j]=chess[i][j];
//         }
//     }

//     if(8==row){
//         print_chess(chess);
//         count++;
//     }else{
//         // 判断这个位置是否符合要求
//         // 如果没有危险，继续往下
//         for(j=0;j<n;j++){
//             // 危险返回0  否则返回1
//             if(notDanger(row,j,chess)){
//                 // 初始化这行
//                 for ( i = 0; i < 8; i++)
//                 {
//                     chess2[row][i]=0;
//                 }
//                 chess2[row][j]=1;
//                 // 继续往下进行摆放皇后位置
//                 EIghtQueen(row+1,n,chess2);
//             }
//         }
//     }
    
// }


// int main(){
//     int chess[8][8],i,j;
//     /*初始化棋盘*/
//     for(i=0;i<8;i++){
//         for (j = 0; j < 8; j++)
//         {
//             chess[i][j]=0;
//         }    
//     }

//     EIghtQueen(0,8,chess);
//     printf("%d\n",count);
// }



#include <iostream>
using namespace std;
 
const int N = 8;
int arr[10], total_cnt;
// arr记录每一行(X)皇后的Y坐标
 
bool isPlaceOK(int *a, int n, int c) {
    for (int i = 1; i <= n - 1; ++i) {
        if (a[i] == c || a[i] - i == c - n || a[i] + i == c + n)
            return false;
        //检查位置是否可以放
        //c是将要放置的位置
        //a[i] == c如果放在同一列，false
        //a[i] -+ i = c -+ n 如果在对角线上，false
    }
    return true;
}
 
void printSol(int *a) {
    for (int i = 1; i <= N; ++i) { //遍历每一行
        for (int j = 1; j <= N; ++j) { //遍历每一列
            cout << (a[i] == j ? "X" : "-") << " ";;
        } //如果标记数组中这一行的皇后放在j位置，则输出X，否则输出-，
        //用空格分隔
        cout << endl; //每一行输出一个换行
    }
    cout << endl; //每一组数据一个换行分隔
}
 
void addQueen(int *a, int n) {
    if (n > N) { //n代表从第一行开始放置
        printSol(a);
        total_cnt++;
        return ;
    }
    for (int i = 1; i <= N; ++i) { //i从第1列到第N列遍历
        if (isPlaceOK(a, n, i)) {
            a[n] = i; //如果可以放置，就把皇后放在第n行第i列
            addQueen(a, n + 1);
        }
    }
 
}
 
int main() {
    addQueen(arr, 1);
    cout << "total: " << total_cnt << " solutions.\n";
    return 0;
}