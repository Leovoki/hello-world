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

/*쳲���������
 int Fib(int num){
    if(num==1||num==0){//�ݹ����
        return num;
    }
    return Fib(num-1)+Fib(num-2);//�ݹ���
 }

 int main(){

    int n;
    cin>>n;
    int sum=0;
    sum=Fib(n);
    printf("%d\n",sum);

 return 0;
 }*/

/*N�ʺ����� ���

�ݹ�����ǳ����еķ�Χ���ݹ���ڣ�
�жϲ���ɨ�������е��С��С������Խ��߶����ϱ��
dfs(+1)//�ܣ������һ�н���̽��
�������ݻָ�*/

int n,sum,vis[5][50]={0,};
void dfs(int cur){ //��cur��
    if(cur==n+1){ //�ݹ����
        sum++; //����һ��˵��������������ĸ�����һ
        return ;
    }

    for(int i=1;i<=n;i++){//ÿ���ж�����֪�ģ�������i��ָ��
        if(vis[0][i]==0&&vis[1][n+i-cur]==0&&vis[2][i+cur]==0){//���ģ��ж�vis0�ж��У�vis1�ж����Խ���,vis2�жϸ��Խ��ߣ����߽�Ϊ��˵���������Խ��ŷ���һ����
            vis[0][i]=vis[1][n+i-cur]=vis[2][i+cur]=1;//���Ϊ1�����ٷ�������
            dfs(cur+1);//���п�������һ��
            vis[0][i]=vis[1][n+i-cur]=vis[2][i+cur]=0;//���ݵ�ʱ��ѸĹ��ĸĻ���
        }
    }
}



int main(){
    cin>>n;
    sum=0;
    //memset(vis,0,sizeof(vis));//vis��ʼ��
    dfs(1);//�ӵ�һ�п�ʼ����
    printf("%d\n",sum);

return 0;
}


