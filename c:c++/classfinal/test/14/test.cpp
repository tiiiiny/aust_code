/*
*14.马拦过河卒（动态规划） 
*【问题描述】
*棋盘上 A 点有一个过河卒，需要走到目标 B 点。卒行走的规则：可以向下、或者向右。
*同时在棋盘上的某一点有一个对方的马（如 C 点），该马所在的点和所有跳跃一步可达的点称为对方马的控制点，
*如图中的 C 点和 P1，……，P8，卒不能通过对方马的控制点。
*棋盘用坐标表示，A 点(0,0)、B 点(n, m) (n,m 为不超过 20 的整数),同样马的位置坐标是需要给出的，C≠A 且 C≠B。
*现在要求你计算出卒从 A 点能够到达 B 点的路径的条数。
*【输入】
*给出 n、m 和 C 点的坐标。
*【输出】
*从 A 点能够到达 B 点的路径的条数。
*【输入样例】
8 6 0 4
*【输出样例】
1617
*/
#include<iostream>
using namespace std;
const int N = 25;
typedef long long LL;
LL f[N][N];
int dx[10] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
int dy[10] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
bool s[N][N];
int main()
{
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    n += 2,m += 2,x += 2,y += 2;
    f[2][1] = 1;
    s[x][y] = 1;
    for(int i = 1;i <= 8;i ++) s[x + dx[i]][y + dy[i]] = 1;
    for(int i = 2; i <= n ; i ++)
        for(int j = 2;j <= m; j ++) 
        {
            if(s[i][j]) 
				continue;
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    cout << f[n][m] << endl;
	return 0;
}
