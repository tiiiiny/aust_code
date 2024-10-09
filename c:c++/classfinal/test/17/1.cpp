#include<iostream>
using namespace std;
#define N 1000
int cost[N][N];  // 表示第i个人完成第j件工作需要的费用
int isC[N] = {0}; // 用于记录第n个工作是否完成，0表示未完成
int n;
int scost;  // 表示总费用

void Backstrack(int i, int c)
{
    if(c < scost) return;
    if(i == n) {  // 当最后一个人也分配好工作后判断总费用
        if(c > scost) scost=c;
        return;
    }
    for(int j=0;j<n;j++) {
        if(isC[j]==0) { // 判断第j个工作是否已经完成，类似剪枝函数
            isC[j]=1;
            Backstrack(i+1, c+cost[i][j]);
            isC[j]=0;  // 回溯法
        }
    }
}

int main()
{
    // cin>>n;
	n =5;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>cost[i][j];
        }
    }
    scost = 0;  // 给总费用设置一个很大的值
    Backstrack(0,0);
        // 第一个0表示从第一个人开始 ，第二个0表示当前需要的总费用
    cout<<scost;
    return 0;
}