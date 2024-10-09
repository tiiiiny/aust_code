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
/*
	main函数中使用 Lambda 表达式作为比较函数
    sort(points.begin(), points.end(), [](const point &x, const point &y) {
        return x.l < y.l;
    });
*/
// bool cmp(const point &x,const point &y){return x.l<y.l;}

void jisuan(int i,double x,double y)	// 计算第i个点在x轴上的左右交点,得在x轴上范围区间
{
	double t=d*d-y*y;
	if(t<0){bj=1;return;}
	a[i].l=x-sqrt(t);		//左端点
	a[i].r=x+sqrt(t);		//右端点
}


/* 
*【输入样例】
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
			jisuan(i,x,y);
		}
		if(bj==1||d<0)
		{
			printf("Case %d: -1\n",t);
			continue;
		}
		
		// sort(a+1,a+n+1,cmp);
		sort(a + 1, a + n + 1, [](const point &x, const point &y) {
            return x.l < y.l;
        });		//使用匿名函数更简洁，不需要再定义一个cmp函数

		double pos=-0x7fffffff/2;
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
		printf("\nCase %d: %d",t,ans);
	}
	return 0;
}