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
bool cmp(const point &x,const point &y){return x.l<y.l;}
void jisuan(int i,double x,double y)
{
	double t=d*d-y*y;
	if(t<0){bj=1;return;}
	a[i].l=x-sqrt(t);
	a[i].r=x+sqrt(t);
}
int main()
{
	int n,t=0;
	while(scanf("%d%d",&n,&d))
	{
		if(n==0&&d==0)break;
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
		sort(a+1,a+n+1,cmp);
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