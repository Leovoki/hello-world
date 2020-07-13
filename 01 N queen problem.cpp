#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#include<list>
using namespace std;

/*斐波那契数列
 int Fib(int num){
    if(num==1||num==0){//递归出口
        return num;
    }
    return Fib(num-1)+Fib(num-2);//递归体
 }

 int main(){

    int n;
    cin>>n;
    int sum=0;
    sum=Fib(n);
    printf("%d\n",sum);

 return 0;
 }*/

/*N皇后问题 框架

递归出口是超出行的范围（递归出口）
判断并对扫到的这行的行、列、正负对角线都打上标记
dfs(+1)//能，则对下一行进行探究
弹出回溯恢复*/

int n,sum,vis[5][50]={0,};
void dfs(int cur){ //第cur行
    if(cur==n+1){ //递归出口
        sum++; //到这一步说明符合条件，解的个数加一
        return ;
    }

    for(int i=1;i<=n;i++){//每次行都是已知的，那这里i是指列
        if(vis[0][i]==0&&vis[1][n+i-cur]==0&&vis[2][i+cur]==0){//核心：判断vis0判断列，vis1判断正对角线,vis2判断负对角线，三者皆为零说明成立可以接着放下一行了
            vis[0][i]=vis[1][n+i-cur]=vis[2][i+cur]=1;//标记为1不能再放棋子了
            dfs(cur+1);//本行可行则下一行
            vis[0][i]=vis[1][n+i-cur]=vis[2][i+cur]=0;//回溯的时候把改过的改回来
        }
    }
}



int main(){
    cin>>n;
    sum=0;
    //memset(vis,0,sizeof(vis));//vis初始化
    dfs(1);//从第一行开始遍历
    printf("%d\n",sum);

return 0;
}


