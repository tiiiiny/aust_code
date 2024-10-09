/*
*4.最优雷达设置问题（贪心算法） 
*【问题描述】假设海岸线可视为一条直线，一边为大海，一边为大陆，岛屿可看作一个点，雷达的监控范围为一个半径为 d 的圆。
* 为方便表示，使用笛卡尔坐标系，令海岸线为 X轴，X 轴上方为大海，X 轴下方为大陆，所有岛屿的位置都由坐标给出。
* 可将岛屿坐标作为圆心，以半径 d 画圆,如果圆与 X 轴没有交点，就无法覆盖岛屿；
* 如果圆与 X 轴的交点为 a,b,雷达放到 a、b 之间那就是可以将该岛屿覆盖住。
* 给定每个岛屿的位置，以及雷达的监控半径，请设计算法，编写程序找出覆盖所有岛屿的雷达安装的最小数量。
*【输入】有多组测试数据，第 1 行给出岛屿的数目 n(1<=n<=1000)和雷达监控范围 d，接下来 n 行输入第 i 个岛屿的 X 坐标和 Y 坐标，当 n 和 d 都是零时结束。
* 
- 5 -
* 【输出】每组测试数据输出一行，要包括样例的编号和最小雷达安装数，如
* 果无法覆盖所有岛屿，输出“-1”。
* 【输入样例】
2 5
-3 4
-6 3
4 5
-5 3
-3 5
2 3
3 3
0 0

3 2
1 2
-3 1
2 1
1 2
0 2
0 0
* 【输出样例】
Case 1: 1
Case 2: 2

Case 1: 2
Case 2: 1
*/

#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct point{
	double l,r;
}a[1005];

int d,bj=0;

void presolve(int i,double x,double y)	// 计算第i个点在x轴上的左右交点,得在x轴上范围区间
{
	double t=d*d-y*y;
	if(t<0){	
		bj=1;	
		return;
	}
	a[i].l=x-sqrt(t);		//左端点
	a[i].r=x+sqrt(t);		//右端点
}

int main()
{
	int n,t=0;
	while(scanf("%d%d",&n,&d))
	{
		if(n==0&&d==0)	break;
		t++;bj=0;
		for(int i=1;i<=n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			presolve(i,x,y);
		}
		if(bj==1||d<0)
		{
			printf("Case %d: -1\n",t);
			continue;
		}
		
	// bool cmp(const point &x,const point &y){return x.l<y.l;}
		// sort(a+1,a+n+1,cmp);
		sort(a + 1, a + n + 1, [](const point &x, const point &y) {
            return x.l < y.l;
        });	
		double pos=-0x7fffffff/2;	// INT_MIN
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].l>pos)
			{
				ans++;
				pos=a[i].r;
			}
			else pos=min(pos,a[i].r);
		}
		printf("Case %d: %d\n",t,ans);
	}
	return 0;
}